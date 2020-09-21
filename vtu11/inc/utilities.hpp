//          __        ____ ____
// ___  ___/  |_ __ _/_   /_   |
// \  \/ /\   __\  |  \   ||   |
//  \   /  |  | |  |  /   ||   |
//   \_/   |__| |____/|___||___|
//
//  License: BSD License ; see LICENSE
//

#ifndef VTU11_UTILITIES_HPP
#define VTU11_UTILITIES_HPP

#include "vtu11.hpp"

namespace vtu11
{

template<typename DataType>
inline std::string dataTypeString( );

//Source: https://stackoverflow.com/questions/8233842/how-to-check-if-directory-exist-using-c-and-winapi
//checks, if a directory exists (might only work in windows!!!)
inline bool directoryExists(const std::string& directoryPath);
	
inline std::string endianness( );

#define VTU11_CHECK( expr, message ) if( !( expr ) ) throw std::runtime_error( message )
} // namespace vtu11

#include "impl/utilities_impl.hpp"

#endif // VTU11_UTILITIES_HPP
