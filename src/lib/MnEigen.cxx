// @(#)root/minuit2:$Id: MnEigen.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/MnEigen.hh"
#include "minuit-cpp/MnUserCovariance.hh"
#include "minuit-cpp/MnMatrix.hh"

 

   namespace MinuitCpp {


LAVector eigenvalues(const LASymMatrix&);

std::vector<double> MnEigen::operator()(const MnUserCovariance& covar) const {
   // wrapper to calculate eigenvalues of the covariance matrix using mneigen function
   
   LASymMatrix cov(covar.Nrow());
   for(unsigned int i = 0; i < covar.Nrow(); i++)
      for(unsigned int j = i; j < covar.Nrow(); j++)
         cov(i,j) = covar(i,j);
   
   LAVector eigen = eigenvalues(cov);
   
   std::vector<double> result(eigen.Data(), eigen.Data()+covar.Nrow());
   return result;
}

   }  // namespace MinuitCpp

 
