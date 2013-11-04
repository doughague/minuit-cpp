# Available `make` Targets

## Build
From the top level minuit-cpp source directory one can follow a standard [CMake](http://www.cmake.org/) 
procedure to compile this library:
```
mkdir build && cd build
cmake ..
make
```
Both a static archive (libminuit-cpp.a) and a shared object library (libminuit-cpp.so) 
are created in build/lib.
Information about the (local) built objects can be accessed by running 
`build/bin/minuit-cpp-config --help`.

## Install
From the build directory use:
```
sudo make install
```
to install (the libraries and headers) to /usr/local.
Information about the installed objects can be accessed by running 
`pkg-config minuit-cpp --help`.

## Documentation
If you have [doxygen](www.stack.nl/~dimitri/doxygen/) you can build html 
source code documentation by typing:
```
make doc
```
from the build directory.

The documentation can be accessed by opening 
[doc/html/index.html](doc/html/index.html) in your web browser.

The documentation can be cleaned (deleted) by typing:
```
make clean-doc
```

