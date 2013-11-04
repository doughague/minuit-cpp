// @(#)root/minuit2:$Id: MinimumParameters.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MinimumParameters
#define MINUITCPP_MinimumParameters

#include "minuit-cpp/MnRefCountedPointer.hh"
#include "minuit-cpp/BasicMinimumParameters.hh"

 

   namespace MinuitCpp {


class MinimumParameters {

public:

  MinimumParameters(unsigned int n) : 
   fData(MnRefCountedPointer<BasicMinimumParameters>(new BasicMinimumParameters(n))) {}

  /** takes the Parameter vector */
  MinimumParameters(const MnAlgebraicVector& avec, double fval) : 
   fData(MnRefCountedPointer<BasicMinimumParameters>(new BasicMinimumParameters(avec, fval)))  {}
  
  /** takes the Parameter vector plus step size x1 - x0 = dirin */
  MinimumParameters(const MnAlgebraicVector& avec, const MnAlgebraicVector& dirin, double fval) : fData(MnRefCountedPointer<BasicMinimumParameters>(new BasicMinimumParameters(avec, dirin, fval)))  {}
  
  ~MinimumParameters() {}

  MinimumParameters(const MinimumParameters& par) : fData(par.fData) {}

  MinimumParameters& operator=(const MinimumParameters& par) {
    fData = par.fData;
    return *this;
  }

  const MnAlgebraicVector& Vec() const {return fData->Vec();}
  const MnAlgebraicVector& Dirin() const {return fData->Dirin();}
  double Fval() const {return fData->Fval();}
  bool IsValid() const {return fData->IsValid();}
  bool HasStepSize() const {return fData->HasStepSize();}

private:

  MnRefCountedPointer<BasicMinimumParameters> fData;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MinimumParameters
