/** \file      minuit-cpp-config.cxx
    \brief     Source for binary executable for minuit-cpp-config.
    \author    Doug Hague
    \date      03.11.2013
    \copyright See License.txt
*/
#include "minuit-cpp/Config.hh"  // minuit-cpp configuration
#include <iostream>              // STD input/output stream objects
using std::ostream;
using std::cout;
using std::cerr;
using std::endl;
#include <string>                // C++ string class
using std::string;

#ifdef HAVE_GETOPT_H
#include <getopt.h>              // GNU option parsing

/** \typedef GnuOpt_t
    \brief GNU getopt option.
    The struct option structure has these fields:
    - const char *name : This field is the name of the option. It is a string.
    - int has_arg : This field says whether the option takes an argument. 
    It is an integer, and there are three legitimate values: 
    no_argument, required_argument and optional_argument.
    - int *flag : If flag is a null pointer, then the val is a value 
    which identifies this option. Often these values are chosen to uniquely 
    identify particular long options. If flag is not a null pointer, 
    it should be the address of an int variable which is the flag for this option. 
    The value in val is the value to store in the flag to indicate that the option was seen. 
    - int val : These fields control how to report or act on the option when it occurs.
*/
typedef struct option GnuOpt_t;

#endif // end HAVE_GETOPT_H


//_____________________________________________________________________________
//! main method for minuit-cpp-config.
void PrintUsage(ostream& os)
{
  os << "Usage: minuit-cpp-config [option]" << endl;
  os << "Options:" << endl;
  os << "  -h|--help        display this help message" << endl;
  os << "  -i|--info        library title & description" << endl;
  os << "  -c|--copyright   library lisence" << endl;
  os << "  -v|--version     library version" << endl;
  os << "  -p|--prefix      install prefix (location)" << endl;
  os << "  -f|--cflags      pre-processor and compiler flags" << endl;
  os << "  -l|--libs        shared library linker flags" << endl;
  os << "  -s|--static      static library linker flags" << endl;
}

//_____________________________________________________________________________
//! main method for minuit-cpp-config.
int main(int argc, char** argv)
{
#ifndef HAVE_GETOPT_H
  // --------------------------------------------
  // check for GNU getopt.h
  cerr << "ERROR: minuit-cpp-config: <getopt.h> not found." << endl;
  return -1;
#else

  // --------------------------------------------
  // check input(s)
  if(argc <= 1){
    PrintUsage(cerr);
    return 0;
  }

  // --------------------------------------------
  // struct array for feeding to getopt
  static GnuOpt_t gGnuLongOpts[] = 
    {
      {"help",       no_argument, 0, 'h'},
      {"info",       no_argument, 0, 'i'},
      {"copyright",  no_argument, 0, 'c'},
      {"version",    no_argument, 0, 'v'},
      {"prefix",     no_argument, 0, 'p'},
      {"cflags",     no_argument, 0, 'f'},
      {"libs",       no_argument, 0, 'l'},
      {"static",     no_argument, 0, 's'},
      {0, 0, 0, 0}
    };

  // getopt_long stores the option index here.
  int optIdx(0), optChar(-1);

  // --------------------------------------------
  // begin reading options
  while(1){
    // GNU getopt_long parser
    optChar = getopt_long(argc, argv, "hicvpfls", gGnuLongOpts, &optIdx);
    
    // Detect the end of the options.
    if(optChar == -1) break;

    // Detect the options
    switch(optChar){
    case 'h':
      PrintUsage(cout);
      return 0;

    case 'i':
      cout << MINUIT_CPP_MONIKER << " - " << MINUIT_CPP_TITLE << endl;
      return 0;

    case 'v':
      cout << MINUIT_CPP_VERSION << endl;
      return 0;

    case 'c':
      {
	// extract program name from full path
	string pnFull(argv[0]);
	string pn = pnFull.substr(pnFull.find_last_of('/')+1, pnFull.size());
	// print the copyright
	cout << pn.c_str() << " " << MINUIT_CPP_COPYRIGHT << endl;
	return 0;
      }

    case 'p':
      cout << MINUIT_CPP_PREFIX << endl;
      return 0;

    case 'f':
      cout << MINUIT_CPP_CFLAGS << endl;
      return 0;

    case 'l':
      cout << MINUIT_CPP_LIBS << endl;
      return 0;

    case 's':
      cout << MINUIT_CPP_STATIC << endl;
      return 0;

    default:
      PrintUsage(cerr);
      return -1;
    } // end option switch
  } // end while (read opts)

  // --------------------------------------------
  // return
  return 0;

#endif // end HAVE_GETOPT_H
}
