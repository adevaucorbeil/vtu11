//          __        ____ ____
// ___  ___/  |_ __ _/_   /_   |
// \  \/ /\   __\  |  \   ||   |
//  \   /  |  | |  |  /   ||   |
//   \_/   |__| |____/|___||___|
//
//  License: BSD License ; see LICENSE
//

#ifndef VTU11_VTU11_HPP
#define VTU11_VTU11_HPP


#include "inc/alias.hpp"
#include "inc/writer.hpp"
#include "inc/parallel_helper.hpp"

namespace vtu11
{

struct Vtu11UnstructuredMesh
{
  std::vector<double>& points_;
  std::vector<VtkIndexType>& connectivity_;
  std::vector<VtkIndexType>& offsets_;
  std::vector<VtkCellType>& types_;

  std::vector<double>& points( ){ return points_; }
  std::vector<VtkIndexType>& connectivity( ){ return connectivity_; }
  std::vector<VtkIndexType>& offsets( ){ return offsets_; }
  std::vector<VtkCellType>& types( ){ return types_; }

  size_t numberOfPoints( ){ return points_.size( ) / 3; }
  size_t numberOfCells( ){ return types_.size( ); }
};


template<typename MeshGenerator, typename Writer = AsciiWriter>
void write( const std::string& filename,
            MeshGenerator& mesh,
            const std::vector<DataSet>& pointData,
            const std::vector<DataSet>& cellData,
            Writer writer );
	
//The declaration of the parallelWrite function
template<typename MeshGenerator, typename Writer = AsciiWriter>
void parallelWrite( const std::string& path,
                    std::string baseName,
                    MeshGenerator& mesh,
                    const std::vector<DataSet>& pointData,
                    const std::vector<DataSet>& cellData,
                    size_t fileId, size_t numberOfFiles,
                    Writer writer );

} // namespace vtu11

#include "impl/vtu11_impl.hpp"

#endif // VTU11_VTU11_HPP
