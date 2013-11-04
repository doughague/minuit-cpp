// @(#)root/minuit2:$Id: MnGlobalCorrelationCoeff.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnGlobalCorrelationCoeff
#define MINUITCPP_MnGlobalCorrelationCoeff

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/MnMatrix.hh"

#include <vector>

 

   namespace MinuitCpp {


/**
   class for global correlation coefficient
 */
class MnGlobalCorrelationCoeff {

public:

  MnGlobalCorrelationCoeff() : 
    fGlobalCC(std::vector<double>()), fValid(false) {}

  MnGlobalCorrelationCoeff(const MnAlgebraicSymMatrix&);

  ~MnGlobalCorrelationCoeff() {}

  const std::vector<double>& GlobalCC() const {return fGlobalCC;}

  bool IsValid() const {return fValid;}

private:

  std::vector<double> fGlobalCC;
  bool fValid;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnGlobalCorrelationCoeff
