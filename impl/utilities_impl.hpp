#ifndef VTU11_UTILITIES_IMPL_HPP
#define VTU11_UTILITIES_IMPL_HPP

namespace vtu11
{

template<typename DataType>
inline std::string dataTypeString( )
{
  std::string base;
  
  if( std::numeric_limits<DataType>::is_integer and std::numeric_limits<DataType>::is_signed )
  {
      base = "Int";
  }
  else if( std::numeric_limits<DataType>::is_integer and not std::numeric_limits<DataType>::is_signed )
  {
      base = "UInt";
  }
  else
  {
    base = "Float";
  }
  
  return base + std::to_string( sizeof( DataType ) * 8 );
}

} // namespace vtu11

inline std::string vtu11::endianness( )
{
   int i = 0x0001;

   if( *reinterpret_cast<char*>( &i ) != 0 )
   {
     return "LittleEndian";
   }
   else
   {
     return "BigEndian";
   }
}

#endif // VTU11_UTILITIES_IMPL_HPP
