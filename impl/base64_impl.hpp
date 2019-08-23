#ifndef VTU11_BASE64_IMPL_HPP
#define VTU11_BASE64_IMPL_HPP

#include <iostream>

namespace vtu11
{

constexpr char base64Map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

template<typename Iterator>
inline std::string base64Encode( Iterator begin, Iterator end )
{
  constexpr auto size = sizeof( decltype( *begin ) );
  
  size_t length = std::distance( begin, end );
  size_t rawBytes = length * size;
  size_t encodedBytes = ( rawBytes / 3 + 1 ) * 4;
  
  std::string result;
  
  result.reserve( encodedBytes );
  
  auto it = begin;
  char byteIndex = 0;

  auto next = [&]( )
  { 
    char byte = *( reinterpret_cast<const char*>(&(*it)) + byteIndex++ );
    
    if( byteIndex == size )
    {
      it++;
      byteIndex = 0;
    }

    return byte;
  };
  
  auto encodeTriplet = [&]( std::array<char, 3> bytes, size_t padding )
  {
    char tmp[4] = { base64Map[ ( bytes[0] & 0xfc ) >> 2 ],
                    base64Map[ ( ( bytes[0] & 0x03 ) << 4) + ( ( bytes[1] & 0xf0 ) >> 4 ) ],
                    base64Map[ ( ( bytes[1] & 0x0f ) << 2) + ( ( bytes[2] & 0xc0 ) >> 6 ) ],
                    base64Map[ bytes[2] & 0x3f ] };
    
    std::fill( tmp + 4 - padding, tmp + 4, '=' );
    
    result += tmp;
  };
  
  for( size_t i = 0; i < rawBytes / 3; ++i )
  {
    encodeTriplet( { next( ), next( ), next( ) }, 0 );
  }
  
  if( it != end )
  {
    std::array<char, 3> bytes { '\0', '\0', '\0' };
    
    size_t remainder = std::distance( it, end ) * size - byteIndex;
  
    for( size_t i = 0; i < remainder; ++i )
    {
      bytes[i] = next( );
    }
    
    encodeTriplet( bytes, 3 - remainder );
  }
  
  return result;
}


} // namespace vtu11

#endif // VTU11_BASE64_IMPL_HPP
