// @(#)root/minuit2:$Id: CombinedMinimumBuilder.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/CombinedMinimumBuilder.hh"
#include "minuit-cpp/FunctionMinimum.hh"
#include "minuit-cpp/MnStrategy.hh"

#if defined(DEBUG) || defined(WARNINGMSG)
#include "minuit-cpp/MnPrint.hh" 
#endif


 

   namespace MinuitCpp {


FunctionMinimum CombinedMinimumBuilder::Minimum(const MnFcn& fcn, const GradientCalculator& gc, const MinimumSeed& seed, const MnStrategy& strategy, unsigned int maxfcn, double edmval) const {
   // find minimum using combined method 
   // (Migrad then if fails try Simplex and then Migrad again) 
   
   FunctionMinimum min = fVMMinimizer.Minimize(fcn, gc, seed, strategy, maxfcn, edmval);
   
   if(!min.IsValid()) {
#ifdef WARNINGMSG
      MN_INFO_MSG("CombinedMinimumBuilder: migrad method fails, will try with simplex method first."); 
#endif
      MnStrategy str(2);
      FunctionMinimum min1 = fSimplexMinimizer.Minimize(fcn, gc, seed, str, maxfcn, edmval);
      if(!min1.IsValid()) {
#ifdef WARNINGMSG
         MN_INFO_MSG("CombinedMinimumBuilder: both migrad and simplex method fail.");
#endif
         return min1;
      }
      MinimumSeed seed1 = fVMMinimizer.SeedGenerator()(fcn, gc, min1.UserState(), str);
      
      FunctionMinimum min2 = fVMMinimizer.Minimize(fcn, gc, seed1, str, maxfcn, edmval);
      if(!min2.IsValid()) {
#ifdef WARNINGMSG
         MN_INFO_MSG("CombinedMinimumBuilder: both migrad and method fails also at 2nd attempt.");
         MN_INFO_MSG("CombinedMinimumBuilder: return simplex Minimum.");
#endif
         return min1;
      }
      
      return min2;
   }
   
   return min;
}

   }  // namespace MinuitCpp

 
