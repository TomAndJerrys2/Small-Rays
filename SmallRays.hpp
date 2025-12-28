// Our Main header file - will update to remove library references
// and ensure pre-processing statements are optimized

#ifndef SMALL_RAYS_H
#define SMALL_RAYS_H

// Library features
#include <memory>
#include <limits>
#include <cmath>

// Common Headers
#include "Ray.hpp"
#include "Colour.hpp"
#include "Vector3.hpp"
#include "Interval.hpp"

using std::make_shared; using std::shared_ptr;
using std::make_unique; using std::unique_ptr;

// Mathematical Constants
constexpr double INFINITY = std::numeric_limits<double>::infinity();
constexpr double PI = 3.1415926535897;

inline double convert_radians(const double degrees) { return (PI * degrees) / 180.00; }

#endif 
