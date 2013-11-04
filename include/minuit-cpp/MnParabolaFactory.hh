// @(#)root/minuit2:$Id: MnParabolaFactory.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnParabolaFactory
#define MINUITCPP_MnParabolaFactory

 

   namespace MinuitCpp {


class MnParabola;
class MnParabolaPoint;

class MnParabolaFactory {

public:

  MnParabolaFactory() {}

  ~MnParabolaFactory() {}

  MnParabola operator()(const MnParabolaPoint&, const MnParabolaPoint&, 
			const MnParabolaPoint&) const;

  MnParabola operator()(const MnParabolaPoint&, double, 
			const MnParabolaPoint&) const;

private: 
  
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnParabolaFactory
