// @(#)root/minuit2:$Id: MnFcn.cxx 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#include "minuit-cpp/MnFcn.hh"
#include "minuit-cpp/FCNBase.hh"
#include "minuit-cpp/MnVectorTransform.hh"

 

   namespace MinuitCpp {


MnFcn::~MnFcn() {
   //   std::cout<<"Total number of calls to FCN: "<<fNumCall<<std::endl;
}

double MnFcn::operator()(const MnAlgebraicVector& v) const {
   // evaluate FCN converting from from MnAlgebraicVector to std::vector
   fNumCall++;
   return fFCN(MnVectorTransform()(v));
}

// double MnFcn::operator()(const std::vector<double>& par) const {
//     return fFCN(par);
// }

double MnFcn::ErrorDef() const {return fFCN.Up();}

double MnFcn::Up() const {return fFCN.Up();}

   }  // namespace MinuitCpp

 
