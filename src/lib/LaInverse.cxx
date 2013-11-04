// @(#)root/minuit2:$Id: LaInverse.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/LaInverse.hh"
#include "minuit-cpp/LASymMatrix.hh"

 

   namespace MinuitCpp {


int mnvert(LASymMatrix& t);

// symmetric matrix (positive definite only)

int Invert(LASymMatrix& t) {
   // function for inversion of symmetric matrices using  mnvert function 
   // (from Fortran Minuit)
   
   int ifail = 0;
   
   if(t.size() == 1) {
      double tmp = t.Data()[0];
      if(!(tmp > 0.)) ifail = 1;
      else t.Data()[0] = 1./tmp;
   } else {
      ifail = mnvert(t);
   }
   
   return ifail;
}


   }  // namespace MinuitCpp

 
