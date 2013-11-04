// @(#)root/minuit2:$Id: VariableMetricEDMEstimator.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/VariableMetricEDMEstimator.hh"
#include "minuit-cpp/FunctionGradient.hh"
#include "minuit-cpp/MinimumError.hh"

 

   namespace MinuitCpp {


double similarity(const LAVector&, const LASymMatrix&);

double VariableMetricEDMEstimator::Estimate(const FunctionGradient& g, const MinimumError& e) const {
   // estimate the edm (expected distance to the minimum) =  0.5 * g^T V g  (where V is the error matrix, inverse of Hessian) 
   // assuminigfirst derivatives if F are zero at the mminimum, 
   
   if(e.InvHessian().size()  == 1) 
      return 0.5*g.Grad()(0)*g.Grad()(0)*e.InvHessian()(0,0);
   
   double rho = similarity(g.Grad(), e.InvHessian());
   return 0.5*rho;
}

   }  // namespace MinuitCpp

 
