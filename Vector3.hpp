#ifndef VECTOR3_H
#define VECTOR3_H


class Vector3 {
	
	// A 3D vector should have {x, y, z}
	// Using this as an object - where other Vectors or Scalar quantities
	// can have a direct affect on a vector
	//
	// Operators: +=, *=, /=, for scaling operations
	// [], array operators will return the vector 0-2
	// - will negate the vectors elements

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
		
		// Negate x, y and z on Vector3
		Vector3 operator - () const {
			return Vector3(-arr[0], -arr[1], -arr[2]);
		}
		
		// Treating Vector as an array to find a value
		// at a given index
		double operator [] (uint8_t e) { return arr[e]; }
		
		// Reference operator in decay
		double & operator [] (uint8_t e) { return arr[e]; }

		// <<< Scaling Operations >>>
		
		Vector3 & operator += (const Vector3 & vec) {
			arr[0] += vec.arr[0];
			arr[1] += vec.arr[1];
			arr[2] += vec.arr[2];

			return * this;
		}
		
		// By Scalar Values
		Vector3 & operator *= (double scalar) {
			arr[0] *= scalar;
			arr[1] *= scalar;
			arr[2] *= scalar;

			return * this;
		}
		
		Vector3 & operator /= (double scalar) {
			return (* this) *= 1 / scalar;
		}
};

#endif
