// @(#)root/minuit2:$Id: MnMatrix.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnMatrix
#define MINUITCPP_MnMatrix

//add MnConfig file to define before everything compiler 
// dependent macros

#include "minuit-cpp/MnConfig.hh"

// Removing this the following include will cause the library to fail
// to compile with gcc 4.0.0 under Red Hat Enterprise Linux 3.  That
// is, FumiliBuiilder.cpp will fail with message about ambigous enum.
// Putting an include <vector> before other includes in that file will
// Fix it, but then another file class will fail with the same
// message.  I don't understand it, but putting the include <vector>
// in this one spot, fixes the problem and does not require any other
// changes to the source code.
//
// Paul_Kunz@slac.stanford.edu  3 June 2005
//
#include <vector>

#include "minuit-cpp/LASymMatrix.hh"
#include "minuit-cpp/LAVector.hh"
#include "minuit-cpp/LaInverse.hh"
#include "minuit-cpp/LaOuterProduct.hh"

 

   namespace MinuitCpp {


typedef LASymMatrix MnAlgebraicSymMatrix;
typedef LAVector MnAlgebraicVector;

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnMatrix
