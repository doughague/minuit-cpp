// @(#)root/minuit2:$Id: InitialGradientCalculator.cxx 31182 2009-11-16 11:08:36Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/InitialGradientCalculator.hh"
#include "minuit-cpp/MnFcn.hh"
#include "minuit-cpp/MnUserTransformation.hh"
#include "minuit-cpp/MnMachinePrecision.hh"
#include "minuit-cpp/MinimumParameters.hh"
#include "minuit-cpp/FunctionGradient.hh"
#include "minuit-cpp/MnStrategy.hh"

#include <math.h>

//#define DEBUG 

#if defined(DEBUG) || defined(WARNINGMSG)
#include "minuit-cpp/MnPrint.hh" 
#endif



 

   namespace MinuitCpp {


FunctionGradient InitialGradientCalculator::operator()(const MinimumParameters& par) const {
   // initial rough  estimate of the gradient using the parameter step size 
   
   assert(par.IsValid());
   
   unsigned int n = Trafo().VariableParameters();
   assert(n == par.Vec().size());

#ifdef DEBUG
   std::cout << "Initial gradient calculator - params " << par.Vec() << std::endl;
#endif
   
   MnAlgebraicVector gr(n), gr2(n), gst(n);
   
   for(unsigned int i = 0; i < n; i++) {
      unsigned int exOfIn = Trafo().ExtOfInt(i);
      
      double var = par.Vec()(i);
      double werr = Trafo().Parameter(exOfIn).Error();
      double sav = Trafo().Int2ext(i, var); 
      double sav2 = sav + werr;
      if(Trafo().Parameter(exOfIn).HasLimits()) {
         if(Trafo().Parameter(exOfIn).HasUpperLimit() &&
            sav2 > Trafo().Parameter(exOfIn).UpperLimit()) 
            sav2 = Trafo().Parameter(exOfIn).UpperLimit();
      }
      double var2 = Trafo().Ext2int(exOfIn, sav2);
      double vplu = var2 - var;
      sav2 = sav - werr;
      if(Trafo().Parameter(exOfIn).HasLimits()) {
         if(Trafo().Parameter(exOfIn).HasLowerLimit() && 
            sav2 < Trafo().Parameter(exOfIn).LowerLimit()) 
            sav2 = Trafo().Parameter(exOfIn).LowerLimit();
      }
      var2 = Trafo().Ext2int(exOfIn, sav2);
      double vmin = var2 - var;
      double gsmin = 8.*Precision().Eps2()*(fabs(var) + Precision().Eps2());
      // protect against very small step sizes which can cause dirin to zero and then nan values in grd
      double dirin = std::max(0.5*(fabs(vplu) + fabs(vmin)),  gsmin );
      double g2 = 2.0*fFcn.ErrorDef()/(dirin*dirin);
      double gstep = std::max(gsmin, 0.1*dirin);
      double grd = g2*dirin;
      if(Trafo().Parameter(exOfIn).HasLimits()) {
         if(gstep > 0.5) gstep = 0.5;
      }
      gr(i) = grd;
      gr2(i) = g2;
      gst(i) = gstep;
   }
   
   return FunctionGradient(gr, gr2, gst);  
}

FunctionGradient InitialGradientCalculator::operator()(const MinimumParameters& par, const FunctionGradient&) const {
   // Base class interface
   return (*this)(par);
}

const MnMachinePrecision& InitialGradientCalculator::Precision() const {
   // return precision (is set in trasformation class)
   return fTransformation.Precision();
}

unsigned int InitialGradientCalculator::Ncycle() const {
   // return ncyles (from Strategy)
   return Strategy().GradientNCycles();
}

double InitialGradientCalculator::StepTolerance() const {
   // return Gradient step tolerance (from Strategy)
   return Strategy().GradientStepTolerance();
}

double InitialGradientCalculator::GradTolerance() const {
   // return Gradient tolerance
   return Strategy().GradientTolerance();
}


   }  // namespace MinuitCpp

 
