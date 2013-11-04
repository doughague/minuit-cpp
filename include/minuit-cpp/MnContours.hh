// @(#)root/minuit2:$Id: MnContours.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnContours
#define MINUITCPP_MnContours


#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/MnStrategy.hh"

#include <vector>
#include <utility>

 

   namespace MinuitCpp {


class FCNBase;
class FunctionMinimum;
class ContoursError;

//_____________________________________________________________
/**
   API class for Contours Error analysis (2-dim errors);
   minimization has to be done before and Minimum must be valid;
   possibility to ask only for the points or the points and associated Minos
   errors;
 */

class MnContours {

public:

   /// construct from FCN + Minimum
   MnContours(const FCNBase& fcn, const FunctionMinimum& min) : fFCN(fcn), fMinimum(min), fStrategy(MnStrategy(1)) {} 

   /// construct from FCN + Minimum + strategy
   MnContours(const FCNBase& fcn, const FunctionMinimum& min, unsigned int stra) : fFCN(fcn), fMinimum(min), fStrategy(MnStrategy(stra)) {} 

   /// construct from FCN + Minimum + strategy
   MnContours(const FCNBase& fcn, const FunctionMinimum& min, const MnStrategy& stra) : fFCN(fcn), fMinimum(min), fStrategy(stra) {} 

   ~MnContours() {}

   /// ask for one Contour (points only) from number of points (>=4) and parameter indeces
   std::vector<std::pair<double,double> > operator()(unsigned int, unsigned int, unsigned int npoints = 20) const;

   /// ask for one Contour ContoursError (MinosErrors + points)
   /// from number of points (>=4) and parameter indeces
   /// can be printed via std::cout
   ContoursError Contour(unsigned int, unsigned int, unsigned int npoints = 20) const;

   const MnStrategy& Strategy() const {return fStrategy;}

private:

   const FCNBase& fFCN;
   const FunctionMinimum& fMinimum;
   MnStrategy fStrategy;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnContours
