#ifndef INTERVAL_H
#define INTERVAL_H

class interval {

  public:

    double min, max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double min, double max) : min(min), max(max) {}

    // size of the interval for rays
    double size() const { return max - min; }

    // checking for each interval if a casted ray is contained within the scene
    bool contains(double x) const { return min <= x && x <= max; }

    // will improve - function for the minimum and maximum ray sizes
    bool surrounds(double x) const { return min < x && x < max; }

    static const interval empty, universe;    // where static and dynamic rays are either active or not 
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif
