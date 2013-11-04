// @(#)root/minuit2:$Id: LaSumOfElements.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/LAVector.hh"
#include "minuit-cpp/LASymMatrix.hh"

 

   namespace MinuitCpp {


double mndasum(unsigned int, const double*, int); 

double sum_of_elements(const LAVector& v) {
   // calculate the absolute sum of the vector elements using mndasum 
   // which is a translation from dasum from BLAS
   return mndasum(v.size(), v.Data(), 1);
}

double sum_of_elements(const LASymMatrix& m) {
   // calculate the absolute sum of all the matrix elements using mndasum 
   // which is a translation of dasum from BLAS
   return mndasum(m.size(), m.Data(), 1);
}

   }  // namespace MinuitCpp

 
