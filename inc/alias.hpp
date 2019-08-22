#ifndef VTU11_ALIAS_HPP
#define VTU11_ALIAS_HPP

#include <string>
#include <map>
#include <utility>
#include <vector>

namespace vtu11
{

using StringStringMap = std::map<std::string, std::string>;

using DataSet = std::tuple<std::string, size_t, std::vector<double>>; 

} // namespace vtu11

#endif // VTU11_ALIAS_HPP
