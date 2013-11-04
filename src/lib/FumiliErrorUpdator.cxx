// @(#)root/minuit2:$Id: FumiliErrorUpdator.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/FumiliErrorUpdator.hh"
#include "minuit-cpp/MnFcn.hh"
#include "minuit-cpp/MnStrategy.hh"
#include "minuit-cpp/MnUserParameterState.hh"
#include "minuit-cpp/FumiliGradientCalculator.hh"
#include "minuit-cpp/MinimumParameters.hh"
#include "minuit-cpp/FunctionGradient.hh"
#include "minuit-cpp/MnMatrix.hh"
#include "minuit-cpp/MinimumError.hh"
#include "minuit-cpp/MinimumState.hh"
#include "minuit-cpp/LaSum.hh"
#include <limits>

#if defined(DEBUG) || defined(WARNINGMSG)
#include "minuit-cpp/MnPrint.hh" 
#endif


 

namespace MinuitCpp {



double sum_of_elements(const LASymMatrix&);


MinimumError FumiliErrorUpdator::Update(const MinimumState& s0, 
                                        const MinimumParameters& p1,
                                        const FunctionGradient& g1) const {
   // dummy methods to suppress unused variable warnings
   // this member function should never be called within
   // the Fumili method...
   s0.Fval();
   p1.Fval();
   g1.IsValid();
   return MinimumError(2);
}


MinimumError FumiliErrorUpdator::Update(const MinimumState& s0, 
                                        const MinimumParameters& p1,
                                        const GradientCalculator&  gc , 
                                        double lambda) const {
   // calculate the error matrix using approximation of Fumili
   // use only first derivatives (see tutorial par. 5.1,5.2)
   // The Fumili Hessian is provided by the FumiliGRadientCalculator class
   // we apply also the Marquard lambda factor to increase weight of diagonal term
   // as suggester in Numerical Receipt for Marquard method
   
   // need to downcast to FumiliGradientCalculator
   FumiliGradientCalculator * fgc = dynamic_cast< FumiliGradientCalculator *>( const_cast<GradientCalculator *>(&gc) ); 
   assert(fgc != 0); 
   
   
   // get Hessian from Gradient calculator
   
   MnAlgebraicSymMatrix h = fgc->Hessian(); 
   
   int nvar = p1.Vec().size();
   
   // apply Marquard lambda factor 
   double eps = 8*std::numeric_limits<double>::min();
   for (int j = 0; j < nvar; j++) { 
      h(j,j) *= (1. + lambda);
      // if h(j,j) is zero what to do ?
      if ( fabs( h(j,j) ) < eps ) { // should use DBL_MIN 
                                       // put a cut off to avoid zero on diagonals
         if ( lambda > 1) 
            h(j,j) = lambda*eps; 
         else 
            h(j,j) = eps; 
      }
   }
   
   
   
   int ifail = Invert(h);
   if(ifail != 0) {
#ifdef WARNINGMSG
      MN_INFO_MSG("FumiliErrorUpdator inversion fails; return diagonal matrix.");
#endif
      for(unsigned int i = 0; i < h.Nrow(); i++) {
         h(i,i) = 1./h(i,i);
      }
   }
   
   
   const MnAlgebraicSymMatrix& v0 = s0.Error().InvHessian();
   
   // calculate by how much did the covariance matrix changed
   // (if it changed a lot since the last step, probably we 
   // are not yet near the Minimum)
   double dcov = 0.5*(s0.Error().Dcovar() + sum_of_elements(h-v0)/sum_of_elements(h)); 
   
   
   
   return MinimumError(h, dcov);
   
}


}  // namespace MinuitCpp

 
