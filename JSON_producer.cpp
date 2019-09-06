#include <iostream>
#include <map>
#include <vector>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>


#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TF1.h"



namespace pt = boost::property_tree;

 struct CalibrationKey
{
    int sector, plane, channel;

    bool operator < (const CalibrationKey &rhs) const {
		return std::tie(this->sector, this->plane, this->channel) < std::tie(rhs.sector, rhs.plane, rhs.channel);
    }

    CalibrationKey(const int sector=-1, const int plane=-1, const int channel=-1)
    : sector(sector), plane(plane), channel(channel)
    {};
};


std::map < std::pair<CalibrationKey,int>, int >  GetOOT_map()
        {
          std::map < std::pair<CalibrationKey,int>, int > m;

		  // non RF clock
		  m[std::make_pair(CalibrationKey(0,0,0) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,1) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,2) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,3) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,4) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,5) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,6) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,7) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,8) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,9) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,10),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,0,11),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,1,0) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,1) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,2) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,3) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,4) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,5) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,6) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,7) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,1,8) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,1,9) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,1,10),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,1,11),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,0) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,1) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,2) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,3) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,4) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,5) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,6) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,7) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,8) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,9) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,10),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,11),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,0) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,1) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,2) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,3) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,4) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,5) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,6) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,7) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,8) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,9) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,10),-1)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,11),-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,0,0) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,1) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,2) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,3) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,4) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,5) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,6) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,7) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,8) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,9) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,10),-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,11),-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,0) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,1) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,2) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,3) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,4) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,1,5) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,1,6) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,7) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,8) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,9) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,10),-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,11),-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,0) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,1) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,2) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,3) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,4) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,5) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,6) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,7) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,8) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,9) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,10),-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,2,11),-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,3,0) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,1) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,2) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,3) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,4) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,5) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,6) ,-1)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,7) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,3,8) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,3,9) ,-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,3,10),-1)] = 2;
		  m[std::make_pair(CalibrationKey(1,3,11),-1)] = 2;
		  // 300122
		  m[std::make_pair(CalibrationKey(0,0,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,9) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,11),-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,9) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,11),-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,0) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,1) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,2) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,3) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,4) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,5) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,6) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,9) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,2,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,11),-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,7) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,8) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,9) ,-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,10),-2)] = 2;
		  m[std::make_pair(CalibrationKey(0,3,11),-2)] = 2;
		  m[std::make_pair(CalibrationKey(1,0,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,9) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,11),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,9) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,11),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,9) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,11),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,0) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,1) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,2) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,3) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,4) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,5) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,6) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,7) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,8) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,9) ,-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,10),-2)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,11),-2)] = 3;
		  // 300155
		  m[std::make_pair(CalibrationKey(0,0,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,0,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,1,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,2,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(0,3,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,0,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,1,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,3) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,4) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,5) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,6) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,2,11),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,0) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,1) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,2) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,3) ,-3)] = 4;
		  m[std::make_pair(CalibrationKey(1,3,4) ,-3)] = 4;
		  m[std::make_pair(CalibrationKey(1,3,5) ,-3)] = 4;
		  m[std::make_pair(CalibrationKey(1,3,6) ,-3)] = 4;
		  m[std::make_pair(CalibrationKey(1,3,7) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,8) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,9) ,-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,10),-3)] = 3;
		  m[std::make_pair(CalibrationKey(1,3,11),-3)] = 3;
          return m;
}



pt::ptree	Generate_dummy_ch_node(const CalibrationKey CalKey, int oot)
{

		pt::ptree dummy_ch_node, dummy_param_node, base_node;

		dummy_ch_node.put("channel", CalKey.channel);
		dummy_ch_node.put("time_precision", 1000);
		dummy_ch_node.put("time_offset", oot*25.0);

		base_node.put("", 0.0);
		dummy_param_node.push_back(std::make_pair("", base_node));
		dummy_param_node.push_back(std::make_pair("", base_node));
		dummy_param_node.push_back(std::make_pair("", base_node));
		dummy_param_node.push_back(std::make_pair("", base_node));

		dummy_ch_node.add_child("param",dummy_param_node);

		return dummy_ch_node;

}


int JSON_producer(string input_file_name, int res_level=0, string output_file_name = "DiamondCalibration.json",int oot=0)
{


	// open root file
	TFile input_file(input_file_name.c_str(),"READ");

	if (!input_file.IsOpen())
	{
		std::cout << "ERROR: Can't open input files " << input_file_name << std::endl;
		return 1;
	}
	std::cout << "processing " << input_file_name.c_str() << std::endl;

	ofstream output_file (output_file_name.c_str());
	if (!output_file.is_open())
	{
		std::cout << "ERROR: Can't open output file " << output_file_name << std::endl;
		return 2;
	}

	std::map< std::pair<CalibrationKey,int>, int > OOT_map=GetOOT_map();


	// get and setup calibration tree
	TTree *calibTree= (TTree*) input_file.Get("DiamondTimingAnalyzer/Calib/CalibTree");

	int cal_sector=0, cal_plane=0, cal_channel=0;
	double cal_Chi_2=0, cal_res_L1=0, cal_res_L2=0, cal_res_L2_3p=0;
	double cal_par[4];

	calibTree-> SetBranchAddress("Sector"  		, &cal_sector		);
	calibTree-> SetBranchAddress("Plane"		, &cal_plane	);
	calibTree-> SetBranchAddress("Channel"  	, &cal_channel	);
	calibTree-> SetBranchAddress("Par_0"		, &cal_par[0]	);
	calibTree-> SetBranchAddress("Par_1"		, &cal_par[1]	);
	calibTree-> SetBranchAddress("Par_2"		, &cal_par[2]	);
	calibTree-> SetBranchAddress("Par_3"		, &cal_par[3]	);
	calibTree-> SetBranchAddress("Chi_2"		, &cal_Chi_2	);
	calibTree-> SetBranchAddress("Res_L1"		, &cal_res_L1	);
	calibTree-> SetBranchAddress("Res_L2"		, &cal_res_L2	);
	calibTree-> SetBranchAddress("Res_L2_3p"		, &cal_res_L2_3p);


	pt::ptree root, sectors, planes, channels;
	std::map<CalibrationKey, pt::ptree> channel_node_map;

	for (int i=0; i< calibTree->GetEntries(); i++)
	//for (int i=0; i< 0; i++)
	{
		calibTree-> GetEntry(i);

		CalibrationKey CalKey(cal_sector, cal_plane, cal_channel);
		int ch_oot = oot;

		if (oot<0)
			ch_oot = OOT_map[std::make_pair(CalKey,oot)];

		pt::ptree ChNode, param_node;
		ChNode.put("channel", cal_channel);

		double resolution=0.0;

		if (cal_plane==2 ||cal_plane==3 )
			resolution= 0.150;
		else
			resolution= 0.250;

		if (res_level==1)
			resolution=cal_res_L1;
		else if (res_level==2)
		{
			if  (cal_sector==1 && cal_plane<3 && cal_channel==0)
			{
				if (cal_res_L2_3p < 0.999)
				{
					resolution=cal_res_L2_3p;
					std::cout << "L2_3p resolution used for arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << " : " << cal_res_L2 << std::endl;
				}
				else
				{
					resolution=cal_res_L1;
					std::cout << "L1 resolution used for arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << " : " << cal_res_L1 << std::endl;
				}
			}
			else if  (cal_sector==0 && cal_plane>0 &&(cal_channel<2 || cal_channel>9))
			{
				if (cal_res_L2_3p < 0.999)
				{
					resolution=cal_res_L2_3p;
					std::cout << "L2_3p resolution used for arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << " : " << cal_res_L2 << std::endl;
				}
				else
				{
					resolution=cal_res_L1;
					std::cout << "L1 resolution used for arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << " : " << cal_res_L1 << std::endl;
				}
			}
			else
			{
				if (cal_res_L2 < 0.999)
				{
					resolution=cal_res_L2;
					std::cout << "L2 resolution used for arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << " : " << cal_res_L2 << std::endl;
				}
				else
				{
					resolution=cal_res_L1;
					std::cout << "L1 resolution used for arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << " : " << cal_res_L1 << std::endl;
				}
			}
		}


		if(cal_par[0]<0)
		{
			ChNode.put("time_precision", 1000);
			std::cout << "invalid calib arm " << cal_sector << " plane "  << cal_plane << " channel "  << cal_channel << std::endl;
		}
		else
			ChNode.put("time_precision", resolution);


		ChNode.put("time_offset", ch_oot*25.0);

		for (auto &param : cal_par)
		{
			pt::ptree base_node;
			base_node.put("", param);
			param_node.push_back(std::make_pair("", base_node));
		}
		// add param node to channel node
		ChNode.add_child("param",param_node);

		channel_node_map[CalKey] = ChNode;

	}
	input_file.Close();



	root.put("formula", "[0]/(exp((x-[1])/[2])+1)+[3]");

	std::vector< pt::ptree > sectorNode_V(2);

	std::vector<std::vector <pt::ptree> > stationNode_V(2,std::vector<pt::ptree>(2));

	std::vector<std::vector<std::vector <pt::ptree> > > planeNode_V(2, std::vector<std::vector <pt::ptree> >(2,std::vector<pt::ptree>(4)));

	pt::ptree SectorListNode, GlobParNode;
	for (int sector_id=0; sector_id < 2; sector_id++)
	{
		sectorNode_V[sector_id].put("sector", sector_id);
		pt::ptree StationListNode;
		for (int station_id=1; station_id < 2; station_id++)
		{
			stationNode_V[sector_id][station_id].put("station", station_id);
			pt::ptree PlaneListNode;
			for (int plane_id=0; plane_id < 4; plane_id++)
			{
				planeNode_V[sector_id][station_id][plane_id].put("plane", plane_id);
				pt::ptree ChListNode;
				for (int ch_id=0; ch_id < 12; ch_id++)
				{
					CalibrationKey CalKey(sector_id, plane_id, ch_id);
					if (channel_node_map.find(CalKey) != channel_node_map.end()) // calibration node exist
					{
						ChListNode.push_back(std::make_pair("", channel_node_map[CalKey]));
					}
					else
					{
						ChListNode.push_back(std::make_pair("", Generate_dummy_ch_node(CalKey,0)));
						std::cout << "missing calib arm " << sector_id << " plane "  << plane_id << " channel "  << ch_id << std::endl;
					}
				}
				planeNode_V[sector_id][station_id][plane_id].add_child("Channels",ChListNode);
				PlaneListNode.push_back(std::make_pair("", planeNode_V[sector_id][station_id][plane_id]));
			}
			stationNode_V[sector_id][station_id].add_child("Planes",PlaneListNode);
			StationListNode.push_back(std::make_pair("", stationNode_V[sector_id][station_id]));
		}
		sectorNode_V[sector_id].add_child("Stations",StationListNode);
		SectorListNode.push_back(std::make_pair("", sectorNode_V[sector_id]));
	}
	GlobParNode.add_child("Sectors",SectorListNode);
	root.add_child("Parameters",GlobParNode);

	pt::write_json(output_file, root);
	return 0;


}
