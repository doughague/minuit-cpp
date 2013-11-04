// @(#)root/minuit2:$Id: MnScan.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/MnScan.hh"
#include "minuit-cpp/MnParameterScan.hh"

 

   namespace MinuitCpp {


std::vector<std::pair<double, double> > MnScan::Scan(unsigned int par, unsigned int maxsteps, double low, double high) {
   // perform a scan of the function in the parameter par
   MnParameterScan scan(fFCN, fState.Parameters());
   double amin = scan.Fval();
   
   std::vector<std::pair<double, double> > result = scan(par, maxsteps, low, high);
   if(scan.Fval() < amin) {
      fState.SetValue(par, scan.Parameters().Value(par));
      amin = scan.Fval();
   }
   
   return result;
}

   }  // namespace MinuitCpp

 
