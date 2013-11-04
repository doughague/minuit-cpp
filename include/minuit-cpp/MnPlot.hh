// @(#)root/minuit2:$Id: MnPlot.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnPlot
#define MINUITCPP_MnPlot

#include "minuit-cpp/MnConfig.hh"
#include <vector>
#include <utility>

 

   namespace MinuitCpp {


/** MnPlot produces a text-screen graphical output of (x,y) points, e.g. 
    from Scan or Contours.
*/

class MnPlot {

public:
  
  MnPlot() : fPageWidth(80), fPageLength(30) {}

  MnPlot(unsigned int width, unsigned int length) : fPageWidth(width), fPageLength(length) {
    if(fPageWidth > 120) fPageWidth = 120;
    if(fPageLength > 56) fPageLength = 56;
  }

  ~MnPlot() {}

  void operator()(const std::vector<std::pair<double,double> >&) const;
  void operator()(double, double, const std::vector<std::pair<double,double> >&) const;

  unsigned int Width() const {return fPageWidth;}
  unsigned int Length() const {return fPageLength;}

private:

  unsigned int fPageWidth;
  unsigned int fPageLength;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnPlot
