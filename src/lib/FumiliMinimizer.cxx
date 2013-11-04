// @(#)root/minuit2:$Id: FumiliMinimizer.cxx 23654 2008-05-06 07:30:34Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/FumiliMinimizer.hh"
#include "minuit-cpp/MinimumSeedGenerator.hh"
#include "minuit-cpp/FumiliGradientCalculator.hh"
#include "minuit-cpp/Numerical2PGradientCalculator.hh"
#include "minuit-cpp/AnalyticalGradientCalculator.hh"
#include "minuit-cpp/MinimumBuilder.hh"
#include "minuit-cpp/MinimumSeed.hh"
#include "minuit-cpp/FunctionMinimum.hh"
#include "minuit-cpp/MnUserParameterState.hh"
#include "minuit-cpp/MnUserParameters.hh"
#include "minuit-cpp/MnUserTransformation.hh"
#include "minuit-cpp/MnUserFcn.hh"
#include "minuit-cpp/FumiliFCNBase.hh"
#include "minuit-cpp/FumiliFCNBase.hh"
#include "minuit-cpp/FumiliGradientCalculator.hh"
#include "minuit-cpp/FCNGradientBase.hh"
#include "minuit-cpp/MnStrategy.hh"
#include "minuit-cpp/MnPrint.hh"

 

   namespace MinuitCpp {


// for Fumili implement Minimize here because need downcast 

      
FunctionMinimum FumiliMinimizer::Minimize(const FCNBase& fcn, const MnUserParameterState& st, const MnStrategy& strategy, unsigned int maxfcn, double toler) const {
   // Minimize using Fumili. Create seed and Fumili gradient calculator. 
   // The FCNBase passed must be a FumiliFCNBase type otherwise method will fail !
   
   MnUserFcn mfcn(fcn, st.Trafo());
   Numerical2PGradientCalculator gc(mfcn, st.Trafo(), strategy);
   
   unsigned int npar = st.VariableParameters();
   if(maxfcn == 0) maxfcn = 200 + 100*npar + 5*npar*npar;
   //FUMILI needs much less function calls
   maxfcn = int(0.1*maxfcn); 
   
   MinimumSeed mnseeds = SeedGenerator()(mfcn, gc, st, strategy);
   
   // downcast fcn 
   
   //std::cout << "FCN type " << typeid(&fcn).Name() << std::endl;
   
   FumiliFCNBase * fumiliFcn = dynamic_cast< FumiliFCNBase *>( const_cast<FCNBase *>(&fcn) ); 
   if ( !fumiliFcn ) { 
      MN_ERROR_MSG("FumiliMinimizer: Error : wrong FCN type. Try to use default minimizer");
      return  FunctionMinimum(mnseeds, fcn.Up() );
   }
   
   
   FumiliGradientCalculator fgc(*fumiliFcn, st.Trafo(), npar);
#ifdef DEBUG
   std::cout << "Minuit::Minimize using FumiliMinimizer" << std::endl;
#endif 
   return ModularFunctionMinimizer::Minimize(mfcn, fgc, mnseeds, strategy, maxfcn, toler);
}



FunctionMinimum FumiliMinimizer::Minimize(const FCNGradientBase& fcn, const MnUserParameterState& st, const MnStrategy& strategy, unsigned int maxfcn, double toler) const {
   // Minimize using Fumili. Case of interface is a FCNGradientBase. 
   // Normally other method is used  - probably this could be removed (t.b.i.)
   
   // need MnUserFcn
   MnUserFcn mfcn(fcn, st.Trafo() );
   AnalyticalGradientCalculator gc(fcn, st.Trafo());
   
   unsigned int npar = st.VariableParameters();
   if(maxfcn == 0) maxfcn = 200 + 100*npar + 5*npar*npar;
   
   MinimumSeed mnseeds = SeedGenerator()(mfcn, gc, st, strategy);
   
   // downcast fcn 
   
   FumiliFCNBase * fumiliFcn = dynamic_cast< FumiliFCNBase *>( const_cast<FCNGradientBase *>(&fcn) ); 
   if ( !fumiliFcn ) { 
      MN_ERROR_MSG("FumiliMinimizer: Error : wrong FCN type. Try to use default minimizer");
      return  FunctionMinimum(mnseeds, fcn.Up() );
   }
   
   
   FumiliGradientCalculator fgc(*fumiliFcn, st.Trafo(), npar);
#ifdef DEBUG
   std::cout << "Minuit::Minimize using FumiliMinimizer" << std::endl;
#endif
   return ModularFunctionMinimizer::Minimize(mfcn, fgc, mnseeds, strategy, maxfcn, toler);
   
}

   }  // namespace MinuitCpp

 
