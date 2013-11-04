// @(#)root/minuit2:$Id: MnTiny.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/MnTiny.hh"

 

   namespace MinuitCpp {


double MnTiny::One() const {return fOne;}

double MnTiny::operator()(double epsp1) const {
   // evaluate minimal diference between two floating points
   double result = epsp1 - One();
   return result;
}

   }  // namespace MinuitCpp

 
