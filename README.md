# Data Pipeline  

This is a library to process different types of hotels data by reading from 
one format and outputting to another format into file.

## Environment & Requirements

* C++ compiler (GNU <= v4.8, Clang <= v3.6, vc++)
* Cmake v2.8 or greater
* Mac & linux
* current build not running on Windows

## Compilation & Execution

The code is developed in C++ with C++11 features, moreover for building the code the compilation instruction are implemented in CMake. The code when compiled generates a shared library and also an executable file which can be used to run the code directly without even writing any code. The code can be build with enabling or disabling unit tests, the tests and code has been extensively tested on Linux (Ubuntu 14.04 LTS) and Mac OSX 10.11.2 with both Clang and Gnu compilers.  

### Installation

For clean compile and installation of code inside code directory
```
mkdir build && cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=<installation_path_for_binaries>
make && make install
```
The above steps should install shared library in lib directory and `run` in bin directory and all header files in include directory

#### installation with unit tests
For unit testing [Google Testing Framework](https://github.com/google/googletest) is used to compile along with unit testing, although the framework is predownloaded in source code provided in `external` directory.
```
mkdir build && cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=<installation_path_for_binaries> -DBUILD_UNIT_TESTS=ON
if any preference for compiler add extra parameter -DCMAKE_CXX_COMPILER=<compiler-name>
make test or ctest
make && make install
```

#### Running the code
The compilation generates shared library and runnable binary file, although it is not necessary to use the shared library
the code is written in executable `run` which can be used to generate outputs. The executable through compilation is generated in same directory where it is compiled therefore can be run by `./run` command however if desired this executable could be globally accessed by setting up `$PATH` and `$LD_LIBRARY_PATH` on linux or `$DYLD_LIBRARY_PATH` on Mac OSX.  
```
run <file-to-read> <output-format(xml|json)> <output-file-name>
```  

## Status  
### Not working  
 * Validate Class  
 This class has been experiencing problems with regular expression validation for url and check UTF8 function, basically the member function check is supposed to traverse through all datarows in class Data and validate ratings, url and check the strings but the main problem is occuring because I unable to figure out reading and writing or validating UTF-8 strings.  
 * UTF-8 processed file
 Although the data is read processed and stored in output files but it is not UTF-8 charset compatible. I have been working on to resolve this issue mostly while reading data from file by informing C++ string to understand the data in UTF-8 charset format once this starts working then writing data would not be an issue.

### Working
The code reads a csv file process data to output `json` and `XML` files.

