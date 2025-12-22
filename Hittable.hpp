#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"
#include "Vector.hpp"

class HitRecord {
	
	public:
		Vector3 point;
		Vector3 normal_val;
		double double x;	
};

class Hittable {

	public:
		virtual ~Hittable() = default;

		virtual bool on_hit(const ray & casted_ray, double raytime_min,
				double raytime_max, HitRecord & record) const = 0;
};

#endif
