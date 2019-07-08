vtu11
Small lib to read/write vtu files

## PhilippB
- **Requirements**
Since I want to use it within Kratos I have some basic requirements:
    - License has to be BSD4 (or MIT would also work I think, I am not the expert here. Or whatever pybind has, since we can include this)
    - Should we then move it to github at some point? I could imagine it to be useful for others too. (then we could also use free CI like Travis or Appveyor => could be an argument of moving it there right from the beginning)
    - c++11 (Kratos unfortunately cannot simply be updated to c++14 :/)
    - header-only, since this is really convenient to use. Esp when including in external codes it makes life much easier if they don't have to link against a library. Maybe even one file like [nlohmann-json](https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp) does it, but I am not sure, up for discussion.

- **Intended Use**
    - Base for VTU-output (currently we only have VTK)
    - Base for FileIO when we couple to external solvers, hence the read & write. Here it will be interesting for me to see how fast the exchange can be with compression.

- **Features**
    - different compresions should be available:
        - ACSII
        - binary (raw) => necessary? (maybe interessting for me since I use )
        - Compressed Binary => PhilippK
    - support for PointData & CellData
    - should be able to be compiled into a lib and exposed to python with pybind11
    - at least support for WIN & LINUX
    - at least some testing ;)

- **Open Questions**
    - Class-based or function-based? (see next point)
    - how to configure? => e.g. how to tell file-name / -format => probably constructor => seems like we need classes ...
    - => I think it is easier to go with a class
    - **Important**: come up with a datastructure that can be used to feed the writer => probably tmplated (and maybe pass fct-ptrs that tell how to extract the data, this way hopefully no intermediate datastructure is necessary)