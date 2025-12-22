#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.hpp"
#include "Hittable.hpp"

class Sphere : Hittable {
		
	public:
		// When a ray intersects with our sphere 
		Sphere() {}

		Sphere(const Vector3 & center, double radius) 
			: ccenter(center), cradius(std::fmax(0, radius)) {}

		bool sphere_intersect(const ray & ccasted_ray, double raytime_min,
				double raytime_max, HitRecord & record) const override {

			Vector3 origin = ccenter - ccasted_ray.origin();
			auto a = dot_product(ccasted_ray.direction(), ccasted_ray.direction());
			auto b = -2.0 * dot_product(ccasted_ray.direction(), origin);
			auto c = dot_product(origin, origin) - (cradius * cradius);

			auto discriminant = (b * b) - 4 * a * c; // > 0: two intersections
								// < 0: no real values that intersect
								// = 0: intersects exactly once
			
			// Checking for quadratic values based on our discriminant: b^2 - 4ac
			if(discriminant < 0) return -1.0;

			auto sqrt_disc = std::sqrt(discriminant);

			auto root = (b - sqrt_disc) / a;
			if(root <= raytime_min || raytime_max <= root) {
				root = (b + sqrt_disc) / a;

				if(root <= raytime_min || raytime_max <= root)
					return false;
			}
			
			record.x = root;
			record.point = ccasted_ray.current_pos(record.x);
			record.normal_val = (record.point - center);

			return true
		}
		
	private:
		const Vector3 ccenter {0, 0, 0};
		double cradius {0};
};


#endif
