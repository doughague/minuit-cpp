// @(#)root/minuit2:$Id: DavidonErrorUpdator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_DavidonErrorUpdator
#define MINUITCPP_DavidonErrorUpdator

#ifndef MINUITCPP_MinimumErrorUpdator
#include "minuit-cpp/MinimumErrorUpdator.hh"
#endif

 

   namespace MinuitCpp {


/**
   Update of the covariance matrix for the Variable Metric minimizer (MIGRAD)
 */
class DavidonErrorUpdator : public MinimumErrorUpdator {

public:

  DavidonErrorUpdator() {}
  
  virtual ~DavidonErrorUpdator() {}

  virtual MinimumError Update(const MinimumState&, const MinimumParameters&,
			      const FunctionGradient&) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_DavidonErrorUpdator
