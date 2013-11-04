// @(#)root/minuit2:$Id: ContoursError.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_ContoursError
#define MINUITCPP_ContoursError

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/MinosError.hh"

#include <vector>
#include <utility>

 

   namespace MinuitCpp {


class ContoursError {

public:

  ContoursError(unsigned int parx, unsigned int pary, const std::vector<std::pair<double,double> >& points, const MinosError& xmnos, const MinosError& ymnos, unsigned int nfcn) : fParX(parx), fParY(pary), fPoints(points), fXMinos(xmnos), fYMinos(ymnos), fNFcn(nfcn) {}

  ~ContoursError() {}

  ContoursError(const ContoursError& cont) : fParX(cont.fParX), fParY(cont.fParY), fPoints(cont.fPoints), fXMinos(cont.fXMinos), fYMinos(cont.fYMinos), fNFcn(cont.fNFcn) {}

  ContoursError& operator()(const ContoursError& cont) {
    fParX = cont.fParX;
    fParY = cont.fParY;
    fPoints = cont.fPoints;
    fXMinos = cont.fXMinos;
    fYMinos = cont.fYMinos;
    fNFcn = cont.fNFcn;
    return *this;
  }

  const std::vector<std::pair<double,double> >& operator()() const {
    return fPoints;
  }

  std::pair<double,double> XMinos() const {
    return fXMinos();
  }

  std::pair<double,double> YMinos() const {
    return fYMinos();
  }

  unsigned int Xpar() const {return fParX;}
  unsigned int Ypar() const {return fParY;}

  const MinosError& XMinosError() const {
    return fXMinos;
  }

  const MinosError& YMinosError() const {
    return fYMinos;
  }

  unsigned int NFcn() const {return fNFcn;}
  double XMin() const {return fXMinos.Min();}
  double YMin() const {return fYMinos.Min();}
  
private:

  unsigned int fParX;
  unsigned int fParY;
  std::vector<std::pair<double,double> > fPoints;
  MinosError fXMinos;
  MinosError fYMinos;
  unsigned int fNFcn;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_ContoursError
