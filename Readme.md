# Minuit C++
Minimization of mathematical functions can be subtle to understand, 
difficult to implement and numerically intensive. 
This library is a fork and "re-factoring" of the world-renowned
[ROOT::Minuit2 v5.28.00](http://seal.web.cern.ch/seal/snapshot/work-packages/mathlibs/minuit/) 
C++ minimization package.
The goal of this project is to enhance the availability and portability 
of Minuit2 for use in other projects like, say, Android apps.

The features of this fork include:

* Licensed as Free Software under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.txt).
* Introduction of CMake build system.
* Depends only on [the C/C++ standard libraries](www.cplusplus.com/reference/).
* Tutorials and examples (still in progress).
* Unit and sanity tests (still in progress).

## Installation

### Build
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

### Install
From the build directory use:
```
sudo make install
```
to install (the libraries and headers) to /usr/local.
Information about the installed objects can be accessed by running 
`pkg-config minuit-cpp --help`.

## Contribute
Bug reports, example usages, complaints or any other information that might be 
helpful in the development of this project should be submitted to 
[the issue traker](https://github.com/doughague/minuit-cpp/issues).

**Consider helping with this project.**
In particular, if you build this library on a non MacOSX or Debian-style 
system, please let me know.

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
