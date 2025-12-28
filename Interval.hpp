#ifndef INTERVAL_H
#define INTERVAL_H

#include "SmallRays.hpp"

class Interval {

	public:

    		double min, max;

    		Interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    		Interval(double min, double max) : min(min), max(max) {}

    		// size of the interval for rays
    		double size() const { return max - min; }

    		// checking for each interval if a casted ray is contained within the scene
   		bool contains(double x) const { return min <= x && x <= max; }

    		// will improve - function for the minimum and maximum ray sizes
    		bool surrounds(double x) const { return min < x && x < max; }

    		static const Interval empty, universe;    // where static and dynamic rays are either active or not 
};

const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);

#endif
