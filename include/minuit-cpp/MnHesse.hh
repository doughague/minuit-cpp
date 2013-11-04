// @(#)root/minuit2:$Id: MnHesse.h 23654 2008-05-06 07:30:34Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnHesse
#define MINUITCPP_MnHesse

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/MnStrategy.hh"

#include <vector>

 

   namespace MinuitCpp {


class FCNBase;
class MnUserParameterState;
class MnUserParameters;
class MnUserCovariance;
class MnUserTransformation;
class MinimumState;
class MnMachinePrecision;
class MnFcn;
class FunctionMinimum; 

//_______________________________________________________________________
/** 
    API class for calculating the numerical covariance matrix 
    (== 2x Inverse Hessian == 2x Inverse 2nd derivative); can be used by the 
    user or Minuit itself
 */

class MnHesse {

public:

   /// default constructor with default strategy
   MnHesse() : fStrategy(MnStrategy(1)) {}

   /// constructor with user-defined strategy level
   MnHesse(unsigned int stra) : fStrategy(MnStrategy(stra)) {}

   /// conctructor with specific strategy
   MnHesse(const MnStrategy& stra) : fStrategy(stra) {}

   ~MnHesse() {}

   ///
   /// low-level API
   ///
   /// FCN + parameters + errors
   MnUserParameterState operator()(const FCNBase&, const std::vector<double>&, const std::vector<double>&, unsigned int maxcalls=0) const;
   /// FCN + parameters + covariance
   MnUserParameterState operator()(const FCNBase&, const std::vector<double>&,  unsigned int nrow, const std::vector<double>&, unsigned int maxcalls = 0) const;
   /// FCN + parameters + MnUserCovariance
   MnUserParameterState operator()(const FCNBase&, const std::vector<double>&, const MnUserCovariance&, unsigned int maxcalls=0) const;
   ///
   /// high-level API
   ///
   /// FCN + MnUserParameters
   MnUserParameterState operator()(const FCNBase&, const MnUserParameters&, unsigned int maxcalls=0) const;
   /// FCN + MnUserParameters + MnUserCovariance
   MnUserParameterState operator()(const FCNBase&, const MnUserParameters&, const MnUserCovariance&, unsigned int maxcalls=0) const;
   /// FCN + MnUserParameterState
   MnUserParameterState operator()(const FCNBase&, const MnUserParameterState&, unsigned int maxcalls=0) const;
   /// 
   /// API to use MnHesse after minimization when function mimimum is avalilable, otherwise information on the last state will be 
   /// lost. (It would be needed to re-call the gradient and spend extra useless function calls) 
   /// The Function Minimum is updated (modified) by adding the Hesse results as last state of minimization
   ///
   void operator()(const FCNBase&, FunctionMinimum&, unsigned int maxcalls=0) const;
   

   /// internal interface
   ///
   MinimumState operator()(const MnFcn&, const MinimumState&, const MnUserTransformation&, unsigned int maxcalls=0) const;

   /// forward interface of MnStrategy
   unsigned int Ncycles() const {return fStrategy.HessianNCycles();}
   double Tolerstp() const {return fStrategy.HessianStepTolerance();}
   double TolerG2() const {return fStrategy.HessianG2Tolerance();}

private:

   MnStrategy fStrategy;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnHesse
