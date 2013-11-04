// @(#)root/minuit2:$Id: MnPosDef.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnPosDef
#define MINUITCPP_MnPosDef

 

   namespace MinuitCpp {


class MinimumState;
class MinimumError;
class MnMachinePrecision;

/**
   Force the covariance matrix to be positive defined
   by adding extra terms in the diagonal
 */
class MnPosDef {

public:
  
  MnPosDef() {}
  
  ~MnPosDef() {}
  
  MinimumState operator()(const MinimumState&, const MnMachinePrecision&) const;
  MinimumError operator()(const MinimumError&, const MnMachinePrecision&) const;
private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnPosDef
