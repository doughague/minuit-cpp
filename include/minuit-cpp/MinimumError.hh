// @(#)root/minuit2:$Id: MinimumError.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MinimumError
#define MINUITCPP_MinimumError

#include "minuit-cpp/MnRefCountedPointer.hh"
#include "minuit-cpp/BasicMinimumError.hh"

 

   namespace MinuitCpp {

 
/** MinimumError keeps the inv. 2nd derivative (inv. Hessian) used for 
    calculating the Parameter step size (-V*g) and for the covariance Update
    (ErrorUpdator). The covariance matrix is equal to twice the inv. Hessian.
 */

class MinimumError {

public:

  class MnNotPosDef {};
  class MnMadePosDef {};
  class MnHesseFailed {};
  class MnInvertFailed {};

public:
  
  MinimumError(unsigned int n) : fData(MnRefCountedPointer<BasicMinimumError>(new BasicMinimumError(n))) {}
 
  MinimumError(const MnAlgebraicSymMatrix& mat, double dcov) : fData(MnRefCountedPointer<BasicMinimumError>(new BasicMinimumError(mat, dcov))) {}
  
  MinimumError(const MnAlgebraicSymMatrix& mat, MnHesseFailed) : fData(MnRefCountedPointer<BasicMinimumError>(new BasicMinimumError(mat, BasicMinimumError::MnHesseFailed()))) {}

  MinimumError(const MnAlgebraicSymMatrix& mat, MnMadePosDef) : fData(MnRefCountedPointer<BasicMinimumError>(new BasicMinimumError(mat, BasicMinimumError::MnMadePosDef()))) {}

  MinimumError(const MnAlgebraicSymMatrix& mat, MnInvertFailed) : fData(MnRefCountedPointer<BasicMinimumError>(new BasicMinimumError(mat, BasicMinimumError::MnInvertFailed()))) {}

  MinimumError(const MnAlgebraicSymMatrix& mat, MnNotPosDef) : fData(MnRefCountedPointer<BasicMinimumError>(new BasicMinimumError(mat, BasicMinimumError::MnNotPosDef()))) {}

  ~MinimumError() {}

  MinimumError(const MinimumError& e) : fData(e.fData) {}

  MinimumError& operator=(const MinimumError& err) {
    fData = err.fData;
    return *this;
  }

  MnAlgebraicSymMatrix Matrix() const {return fData->Matrix();}

  const MnAlgebraicSymMatrix& InvHessian() const {return fData->InvHessian();}

  MnAlgebraicSymMatrix Hessian() const {return fData->Hessian();}

  double Dcovar() const {return fData->Dcovar();}
  bool IsAccurate() const {return fData->IsAccurate();}
  bool IsValid() const {return fData->IsValid();}
  bool IsPosDef() const {return fData->IsPosDef();}
  bool IsMadePosDef() const {return fData->IsMadePosDef();}
  bool HesseFailed() const {return fData->HesseFailed();}
  bool InvertFailed() const {return fData->InvertFailed();}
  bool IsAvailable() const {return fData->IsAvailable();}

private:

  MnRefCountedPointer<BasicMinimumError> fData;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MinimumError
