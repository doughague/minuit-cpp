// @(#)root/minuit2:$Id: MnParameterScan.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnParameterScan
#define MINUITCPP_MnParameterScan

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/MnUserParameters.hh"

#include <vector>
#include <utility>

 

   namespace MinuitCpp {


class FCNBase;

/** Scans the values of FCN as a function of one Parameter and retains the 
    best function and Parameter values found.
 */

class MnParameterScan {

public:

  MnParameterScan(const FCNBase&, const MnUserParameters&);

  MnParameterScan(const FCNBase&, const MnUserParameters&, double);

  ~MnParameterScan() {}

// returns pairs of (x,y) points, x=parameter Value, y=function Value of FCN
  std::vector<std::pair<double, double> > operator()(unsigned int par, unsigned int maxsteps = 41, double low = 0., double high = 0.);

  const MnUserParameters& Parameters() const {return fParameters;}
  double Fval() const {return fAmin;}

private:

  const FCNBase& fFCN;
  MnUserParameters fParameters;
  double fAmin;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnParameterScan
