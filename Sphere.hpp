#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.hpp"
#include "ray.hpp"

class Sphere {
		
	public:
		// When a ray intersects with our sphere 
		Sphere() {}

		Sphere(const Vector3 & center, double radius, const ray & _ray) 
			: ccenter(center), cradius(radius), ccasted_ray(_ray) {}

		bool sphere_intersect() const {
			Vector3 origin = ccenter - ccasted_ray.origin();
			auto a = dot_product(ccasted_ray.direction(), ccasted_ray.direction());
			auto b = -2.0 * dot_product(ccasted_ray.direction(), origin);
			auto c = dot_product(origin, origin) - (cradius * cradius);

			auto discriminant = (b * b) - 4 * a * c; // > 0: two intersections
								// < 0: no real values that intersect
								// = 0: intersects exactly once
			
			// Checking for quadratic values based on our discriminant: b^2 - 4ac
			if(discriminant < 0) return -1.0;
			else return (-b - std::sqrt(discriminant) / (2.0 * a));
		}
		
	private:
		const Vector3 ccenter {0, 0, 0};
		double cradius {0};
		const ray ccasted_ray;
};


#endif
