# Minuit C++
This library is a "re-factoring" of the
[ROOT::Minuit2](http://seal.web.cern.ch/seal/snapshot/work-packages/mathlibs/minuit/) 
C++ minimization package.

### New Features
Negligable amounts of the original code have been re-written but the
re-factoring does include (at least):

* Introduction of CMake build system.
* Renaming of the package/library from `Minuit2` to `minuit-cpp`.
* Change header file extentions from ".h" to ".hh".
* Changed naming convention for header files `#define`s
* Removing "global" `ROOT` namespace.
* Renaming the namespace `Minuit2` to `MinuitCpp`.

### Minuit2 Links
* [Original Minuit paper](http://inspirehep.net/search?p=find+j+cphcb,10,343)
* [Minuit](http://seal.web.cern.ch/seal/snapshot/work-packages/mathlibs/minuit/)
* [Minuit2 documentation](http://seal.web.cern.ch/seal/MathLibs/Minuit2/html/)
* [search: Minuit2](https://duckduckgo.com/?q=Minuit2)
* [wiki: MINUIT](https://en.wikipedia.org/wiki/MINUIT)

## Installation

### Dependencies
* [C/C++ standard libraries](www.cplusplus.com/reference/).
* [C++ compiler](llvm.org/releases/download.html).
* [CMake](http://www.cmake.org/) for creating build instructions.
* [(GNU) make](https://www.gnu.org/software/make/) for compiling/building.
* [doxygen](www.stack.nl/~dimitri/doxygen/) for making API documentation (optional).

### Build
From the top level minuit-cpp source directory one can follow a standard CMake 
procedure to compile this library:
```
mkdir build && cd build
cmake ..
make
```
Both a static archive and a shared object library are created in the lib/
sub-directory of the build directory.

### Install
From the build directory use:
```
sudo make install
```
to install (the libraries and headers) to /usr/local.
This will also allow minuit-cpp to be used with the pkg-config software, 
i.e. `pkg-config minuit-cpp --version`.

### Documentation
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

## Contribute
Bug reports, example usages, complaints or any other information that might be 
helpful in the development of this project should be submitted to 
[John D. Hague](mailto:haguejd@nv.doe.gov).

Please consider helping with this project!

**To-Do's**:
* Add `math` headers
* Add tests
* Add tutorials

**Wish List**:

* Update CMakeLists.txt to support:
  * Windows (+ Cygwin?) compilation!
  * Visual-Studio project 
  * XCode project
  * Eclipse project

## License

### Original
The original [ROOT::Minuit2](http://seal.web.cern.ch/seal/MathLibs/Minuit2/html/) package 
contains the following copyright:

> Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT  
> Authors: M. Winkler, F. James, L. Moneta, A. Zsenei 2003-2005


### This Version
minuit-cpp - C++ Minimization Package
Copyright (C) 2013 Doug Hague

This library is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
