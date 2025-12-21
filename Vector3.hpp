#ifndef VECTOR3_H
#define VECTOR3_H


class Vector3 {
	
	// A 3D vector should have {x, y, z}
	// Using this as an object - where other Vectors or Scalar quantities
	// can have a direct affect on a vector
	//
	// Operators: +=, *=, /=, - and + for scaling operations
	// [], array operators will return the vector 0-2

	public:
		double arr[3];
		
		// Constructor where nothing is passed
		Vector3() : e {0.0, 0.0, 0.0} {}

		// Constructor where arguments are passed
		Vector3(double x, double y, double z) : e {x, y, z} {}
		
		// Getters for xi, yi and zi in a vector (i is subscript)
		double get_x() const { return arr[0]; }
		double get_y() const { return arr[1]; }
		double get_z() const { return arr[2]; }
		
		double length_squared() const { 
			return ((arr[0] * arr[0]) 
				+ (arr[1] * arr[1]) 
				+ (arr[2] * arr[2]));
		}

		double length() const { return std::sqrt(length_squared); }
}


#endif
