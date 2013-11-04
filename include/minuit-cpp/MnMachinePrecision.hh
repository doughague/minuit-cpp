// @(#)root/minuit2:$Id: MnMachinePrecision.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnMachinePrecision
#define MINUITCPP_MnMachinePrecision

#include <math.h>

 

   namespace MinuitCpp {


/** 
    determines the relative floating point arithmetic precision. The 
    SetPrecision() method can be used to override Minuit's own determination, 
    when the user knows that the {FCN} function Value is not calculated to 
    the nominal machine accuracy.
 */

class MnMachinePrecision {

public:

  MnMachinePrecision();

  ~MnMachinePrecision() {}

  MnMachinePrecision(const MnMachinePrecision& prec) : fEpsMac(prec.fEpsMac), fEpsMa2(prec.fEpsMa2) {}

  MnMachinePrecision& operator=(const MnMachinePrecision& prec) {
    fEpsMac = prec.fEpsMac;
    fEpsMa2 = prec.fEpsMa2;
    return *this;
  }

  /// eps returns the smallest possible number so that 1.+eps > 1.
  double Eps() const {return fEpsMac;}

  /// eps2 returns 2*sqrt(eps)
  double Eps2() const {return fEpsMa2;}

  /// override Minuit's own determination
  void SetPrecision(double prec) {
    fEpsMac = prec;
    fEpsMa2 = 2.*sqrt(fEpsMac);
  }

private:

  double fEpsMac;
  double fEpsMa2;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnMachinePrecision
