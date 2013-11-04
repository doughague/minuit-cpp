#################################################################
#                   CMake file for minuit-cpp                   #
#################################################################


# ---------------------------------------------------------------
# CMake settings
# ---------------------------------------------------------------
# Due to Mac OSX we need to keep compatibility with CMake 2.6
# see http://www.cmake.org/Wiki/CMake_Policies
cmake_minimum_required(VERSION 2.6)

# --> Helpers
include(CheckIncludeFile)


# ---------------------------------------------------------------
# Build options
# ---------------------------------------------------------------
# --> CMake verbosity
option(CMAKE_VERBOSE_MAKEFILE "Makefiles that show each command line as it is used" OFF)
option(CMAKE_RULE_MESSAGES "Add a progress message describing what each build rule does" ON)

# --> Apple
option(APPLE_UNIVERSAL_BIN "Apple: Build universal binary" OFF)


# ---------------------------------------------------------------
# Project settings
# ---------------------------------------------------------------
# --> Project Name.
#     Additionally this sets the variables 
#     <projectName>_BINARY_DIR and <projectName>_SOURCE_DIR.
#     See http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:project
project(MINUIT_CPP CXX C)

# --> Project tags
set(MINUIT_CPP_MONIKER "minuit-cpp")
set(MINUIT_CPP_TITLE   "C++ Minimization Package")
set(MINUIT_CPP_AUTHOR  "Doug Hague")
set(MINUIT_CPP_YEAR    "2013")

# --> Version-ing
set(MINUIT_CPP_VERSION_MAJOR "5")
set(MINUIT_CPP_VERSION_MINOR "29")
set(MINUIT_CPP_VERSION_PATCH "00")
set(MINUIT_CPP_VERSION "${MINUIT_CPP_VERSION_MAJOR}.${MINUIT_CPP_VERSION_MINOR}.${MINUIT_CPP_VERSION_PATCH}")

# --> GNU getopt
check_include_file("getopt.h" HAVE_GETOPT_H)

# --> Configuration header
#     Pass some of the CMake settings to the source code
configure_file("${MINUIT_CPP_SOURCE_DIR}/src/Config.hh.in" 
               "${MINUIT_CPP_SOURCE_DIR}/include/${MINUIT_CPP_MONIKER}/Config.hh")


# ---------------------------------------------------------------
# Project options
# ---------------------------------------------------------------


# ---------------------------------------------------------------
# Project sources, headers, directories and libraries
# ---------------------------------------------------------------

# --> Define the header top-level directory
set(inc_dir "include")
set(head_dir "${inc_dir}/${MINUIT_CPP_MONIKER}")
# --> Add include directories to the build
include_directories(${MINUIT_CPP_SOURCE_DIR}/${inc_dir})
# --> Actual header files
file(GLOB headers "${head_dir}/[a-zA-Z]*.hh")
#  "${head_dir}/math/[a-zA-Z]*.hh"

# --> Actual source files
set(src_dir "src")
set(lib_src_dir "${src_dir}/lib")
file(GLOB lib_sources "${lib_src_dir}/[a-zA-Z]*.cxx")

# --> Define the output library directory
set(lib_dir "lib")
# --> The project shared object library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${lib_dir}")
add_library(${MINUIT_CPP_MONIKER} SHARED ${headers} ${lib_sources})
set_target_properties(${MINUIT_CPP_MONIKER} 
                      PROPERTIES
                      VERSION "${MINUIT_CPP_VERSION}"
		      SOVERSION "${MINUIT_CPP_VERSION_MAJOR}.${MINUIT_CPP_VERSION_MINOR}"
		      OUTPUT_NAME "${MINUIT_CPP_MONIKER}"
		      MINUIT_CPP_LABEL "${MINUIT_CPP_MONIKER}")
# --> The project static library (archive)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${lib_dir}")
add_library(${MINUIT_CPP_MONIKER}-static STATIC ${headers} ${lib_sources})
set_target_properties(${MINUIT_CPP_MONIKER}-static 
                      PROPERTIES
		      OUTPUT_NAME "${MINUIT_CPP_MONIKER}")

# --> utility executable(s)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
set(util_src_dir "${src_dir}/utils")
add_executable(${MINUIT_CPP_MONIKER}-config 
               "${util_src_dir}/${MINUIT_CPP_MONIKER}-config.cxx")


# ---------------------------------------------------------------
# General compilation settings
# ---------------------------------------------------------------
# --> Check for build type
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# --> Apple (MacOS)
if(APPLE)
  # set better default install prefix for MacOS
  set(CMAKE_INSTALL_PREFIX /opt/local/)
  # build an Apple Universal binary?
  if(APPLE_UNIVERSAL_BIN)
    set(CMAKE_OSX_ARCHITECTURES ppc;i386)
  endif()
endif()


# ---------------------------------------------------------------
# Compiler specific settings
# ---------------------------------------------------------------
# --> GCC/Clang specialities
if((CMAKE_COMPILER_IS_GNUCXX) OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
  # set flags
  set(CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG -Wfatal-errors")
  set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG -Wfatal-errors")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g -DDEBUG -Wfatal-errors")
  set(CMAKE_CXX_FLAGS_DEBUG          "-O1 -g -DDEBUG -Wall -Wextra -Wshadow -Wcast-align -Wno-unused-private-field")

  # customized targets
  add_custom_target(release $(MAKE) clean
                    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
		    COMMENT "Adjusting settings for release compilation"
		    VERBATIM)
  add_custom_target(min-size-release $(MAKE) clean
                    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=MinSizeRel ${CMAKE_SOURCE_DIR}
		    COMMENT "Adjusting settings for minimum size release compilation"
		    VERBATIM)
  add_custom_target(release-debug $(MAKE) clean
                    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=RelWithDebInfo ${CMAKE_SOURCE_DIR}
		    COMMENT "Adjusting settings for releasable with debug info compilation"
		    VERBATIM)
  add_custom_target(debug $(MAKE) clean
                    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
                    COMMENT "Adjusting settings for debug compilation"
		    VERBATIM)
endif()


# ---------------------------------------------------------------
# Install
# ---------------------------------------------------------------
# --> Library + bins
set(_INSTALL_DESTINATIONS
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(TARGETS 
        ${MINUIT_CPP_MONIKER} ${MINUIT_CPP_MONIKER}-static 
	${MINUIT_CPP_MONIKER}-config
	${_INSTALL_DESTINATIONS})

# --> Headers
install(DIRECTORY      include/${MINUIT_CPP_MONIKER}
	DESTINATION    include
	FILES_MATCHING PATTERN "*.hh")

# --> Package configuration
if(UNIX)
  set(PC_FILE ${CMAKE_BINARY_DIR}/${MINUIT_CPP_MONIKER}.pc)
  configure_file("src/${MINUIT_CPP_MONIKER}.pc.cmake" ${PC_FILE} @ONLY)
  install(FILES ${PC_FILE} 
          DESTINATION lib/pkgconfig)
endif()


# ---------------------------------------------------------------
# documentation
# ---------------------------------------------------------------
include(FindDoxygen)
if(DOXYGEN_FOUND)
  # --> Set the doc directory, and config options
  set(doc_dir "${MINUIT_CPP_SOURCE_DIR}/doc")
  set(doc_cfg "${doc_dir}/doxy.cfg")
  set(doc_log "${doc_dir}/doxy.log")
  set(doc_head_dir "${MINUIT_CPP_SOURCE_DIR}/${inc_dir}")
  set(doc_src_dir "${MINUIT_CPP_SOURCE_DIR}/${src_dir}")
  
  # --> Configuration file
  configure_file("${doc_cfg}.in" "${doc_cfg}")
  
  # --> Documentation target
  add_custom_target(doc 
                    COMMAND ${DOXYGEN_EXECUTABLE} ${doc_cfg} > ${doc_log}
                    COMMENT "Creating doxygen documentation"
                    VERBATIM)

  # --> Clean documentation target
  add_custom_target(clean-doc 
                    COMMAND rm -rf ${doc_dir}/html
                    COMMENT "Cleaning doxygen documentation"
                    VERBATIM)
endif()


# ---------------------------------------------------------------
# Distribution bundle
# ---------------------------------------------------------------
include(FindGit)
if(GIT_FOUND)
  # --> Distribution name
  set(ARCHIVE_NAME ${MINUIT_CPP_MONIKER}-${MINUIT_CPP_VERSION})
  # --> Distribution target
  add_custom_target(dist 
                    COMMAND ${GIT_EXECUTABLE} archive --prefix=${ARCHIVE_NAME}/ HEAD 
  		            | gzip > ${CMAKE_SOURCE_DIR}/${ARCHIVE_NAME}.tgz
  		    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    COMMENT "Creating distribution bundle ${ARCHIVE_NAME}.tgz"
                    VERBATIM)
endif()

# # ---------------------------------------------------------------
# # Tests
# # ---------------------------------------------------------------
# if(("${CMAKE_BUILD_TYPE}" STREQUAL "Debug"))
#   # --> Test headers
#   file(GLOB test_headers ${src_dir}/test/[a-z]*.hh)
#   # --> Test sources
#   file(GLOB test_sources ${src_dir}/test/[a-z]*.cxx)

#   # --> Include local
#   include_directories(${MINUIT_CPP_SOURCE_DIR}/test)
#   # --> Test executable
#   add_executable(tests ${test_sources} ${test_headers})
#   # --> Link this library
#   target_link_libraries(tests minuit-cpp)
# endif()
