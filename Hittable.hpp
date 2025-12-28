#ifndef HITTABLE_H
#define HITTABLE_H

#include "SmallRays.hpp"

class HitRecord {
	
	public:
		Vector3 point;
		Vector3 normal_val;
		double double x;

		bool front_face;

		const void set_front_face(const ray & casted_ray, const Vector3 & vec_front) {
			// call dot product to calculate the surface trajetory of when the ray hits
			// making sure that its not positive as this would mean the opposite direction.
			front_face = dot_product(casted_ray.direction(), vec_front) < 0;
			
			// like before - checking whether its facing in the +/-
			normal_val = front_face ? vec_front : -(vec_front);
		}
};

class Hittable {

	public:
		virtual ~Hittable() = default;

		virtual bool on_hit(const ray & casted_ray, double raytime_min,
				double raytime_max, HitRecord & record) const = 0;
};

#endif
