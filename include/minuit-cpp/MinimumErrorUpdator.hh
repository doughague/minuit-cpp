// @(#)root/minuit2:$Id: MinimumErrorUpdator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MinimumErrorUpdator
#define MINUITCPP_MinimumErrorUpdator

 

   namespace MinuitCpp {


class MinimumState;
class MinimumError;
class MinimumParameters;
class FunctionGradient;

class MinimumErrorUpdator {

public:

  virtual ~MinimumErrorUpdator() {}

  virtual MinimumError Update(const MinimumState&, const MinimumParameters&,
			      const FunctionGradient&) const = 0;

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MinimumErrorUpdator
