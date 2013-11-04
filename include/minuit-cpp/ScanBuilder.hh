// @(#)root/minuit2:$Id: ScanBuilder.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_ScanBuilder
#define MINUITCPP_ScanBuilder

#include "minuit-cpp/MinimumBuilder.hh"

 

   namespace MinuitCpp {


class FunctionMinimum;
class MnFcn;
class MinimumSeed;

/** Performs a minimization using the simplex method of Nelder and Mead
    (ref. Comp. J. 7, 308 (1965)).
 */

class ScanBuilder : public MinimumBuilder {

public:

  ScanBuilder() {}

  ~ScanBuilder() {}

  virtual FunctionMinimum Minimum(const MnFcn&, const GradientCalculator&, const MinimumSeed&, const MnStrategy&, unsigned int, double) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_ScanBuilder
