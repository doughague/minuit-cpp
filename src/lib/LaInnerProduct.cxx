// @(#)root/minuit2:$Id: LaInnerProduct.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/LAVector.hh"

 

   namespace MinuitCpp {


double mnddot(unsigned int, const double*, int, const double*, int);

double inner_product(const LAVector& v1, const LAVector& v2) {
   // calculate inner (dot) product of two vectors  using mnddot function
   return mnddot(v1.size(), v1.Data(), 1, v2.Data(), 1);
}

   }  // namespace MinuitCpp

 
