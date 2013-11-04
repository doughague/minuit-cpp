// @(#)root/minuit2:$Id: FunctionMinimizer.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_FunctionMinimizer
#define MINUITCPP_FunctionMinimizer


#include "minuit-cpp/MnConfig.hh"
#include <vector>

 

   namespace MinuitCpp {


class FCNBase;
class FCNGradientBase;
class FunctionMinimum;

//_____________________________________________________________________________________
/** base class for function minimizers; user may give FCN or FCN with Gradient,
    Parameter starting values and initial Error guess (sigma) (or "step size"),
    or Parameter starting values and initial covariance matrix; 
    covariance matrix is stored in Upper triangular packed storage format, 
    e.g. the Elements in the array are arranged like 
    {a(0,0), a(0,1), a(1,1), a(0,2), a(1,2), a(2,2), ...},
    the size is nrow*(nrow+1)/2 (see also MnUserCovariance.h);   
 */

class FunctionMinimizer {

public:
  
   virtual ~FunctionMinimizer() {}

   //starting values for parameters and errors
   virtual FunctionMinimum Minimize(const FCNBase&, const std::vector<double>& par, const std::vector<double>& err, unsigned int strategy, unsigned int maxfcn, double toler) const = 0; 

   //starting values for parameters and errors and FCN with Gradient
   virtual FunctionMinimum Minimize(const FCNGradientBase&, const std::vector<double>& par, const std::vector<double>& err, unsigned int strategy, unsigned int maxfcn, double toler) const = 0; 

   //starting values for parameters and covariance matrix
   virtual FunctionMinimum Minimize(const FCNBase&, const std::vector<double>& par, unsigned int nrow, const std::vector<double>& cov, unsigned int strategy, unsigned int maxfcn, double toler) const = 0; 

   //starting values for parameters and covariance matrix and FCN with Gradient
   virtual FunctionMinimum Minimize(const FCNGradientBase&, const std::vector<double>& par, unsigned int nrow, const std::vector<double>& cov, unsigned int strategy, unsigned int maxfcn, double toler) const = 0; 

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_FunctionMinimizer
