// Our Main header file - will update to remove library references
// and ensure pre-processing statements are optimized

#ifndef SMALL_RAYS_H
#define SMALL_RAYS_H

// Library features
#include <memory>
#include <limits>
#include <cmath>
#include <random>

// Common Headers
#include "Ray.hpp"
#include "Colour.hpp"
#include "Vector3.hpp"
#include "Interval.hpp"

using std::make_shared; using std::shared_ptr;

// Mathematical Constants
constexpr double INFINITY = std::numeric_limits<double>::infinity();
constexpr double PI = 3.1415926535897;

inline double convert_radians(const double degrees) { return (PI * degrees) / 180.00; }

// inline double random_double() { return std::rand() / (RAND_MAX + 1.0); }

inline double random_double() {
	// using real distribution based on a bell curve for random
	// intervals between 0.0 ... 1.0
	static std::uniform_real_distribution<double> distrib(0.0, 1.0);
	static std::m19937 gen;

	return distrib(gen);
}

// Only returns real numbers from min ... max
inline double random_double(double min, double max) { return min + ( max - min) * random_double(); }


#endif 
