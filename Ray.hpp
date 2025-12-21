#ifndef RAY_H
#define RAY_H

#include "Vector3.hpp"

class ray {

	public:
		ray() {}
		
		// Defining a rays direction and origin from arguments
		ray(const Vector3 & origin, const Vector3 & direction) 
			: origin_pos(origin), direction_pos(direction) {}
		
		// In terms, refers to a single point at where the ray is cast
		const Vector3 & origin() const { return origin_pos; }

		// casting direction of said ray
		const Vector3 & direction() const { return direction_pos; }

		Vector3 current_pos(double pos) const {
			return origin_pos + pos * direction_pos;
		}

	private:
		Vector3 origin_pos; // as a point
		Vector3 direction_pos;
};

#endif
