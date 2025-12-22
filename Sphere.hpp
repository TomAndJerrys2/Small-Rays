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
		}
		
	private:
		const Vector3 ccenter {0, 0, 0};
		double cradius {0};
		const ray ccasted_ray;
};


#endif
