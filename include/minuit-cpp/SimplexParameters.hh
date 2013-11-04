// @(#)root/minuit2:$Id: SimplexParameters.h 21114 2007-11-29 17:16:45Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_SimplexParameters
#define MINUITCPP_SimplexParameters

#include <cassert>

#include "minuit-cpp/MnMatrix.hh"

#include <vector>
#include <utility>

 

   namespace MinuitCpp {

/**
   class describing the simplex set of points (f(x), x )  which evolve during the minimization 
   iteration process. 
 */

class SimplexParameters {

public:

  SimplexParameters(const std::vector<std::pair<double, MnAlgebraicVector> >& simpl, unsigned int jh, unsigned int jl) : fSimplexParameters(simpl), fJHigh(jh), fJLow(jl) {}

  ~SimplexParameters() {}

  void Update(double, const MnAlgebraicVector&); 
  
  const std::vector<std::pair<double, MnAlgebraicVector> >& Simplex() const {
    return fSimplexParameters;
  }

  const std::pair<double, MnAlgebraicVector>& operator()(unsigned int i) const {
    assert(i < fSimplexParameters.size());
    return fSimplexParameters[i];
  }
  
  unsigned int Jh() const {return fJHigh;}
  unsigned int Jl() const {return fJLow;}
  double Edm() const {return fSimplexParameters[Jh()].first - fSimplexParameters[Jl()].first;}
  MnAlgebraicVector Dirin() const;

private:

  std::vector<std::pair<double, MnAlgebraicVector> > fSimplexParameters;
  unsigned int fJHigh;
  unsigned int fJLow;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_SimplexParameters
