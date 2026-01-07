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
		
		double length() const { return std::sqrt(length_squared); }
		
		double length_squared() const { 
			return ((arr[0] * arr[0]) 
				+ (arr[1] * arr[1]) 
				+ (arr[2] * arr[2]));
		}

		bool near_zero() const {
			auto seq = 1e-8;
			return ( (std::fabs(e[0]) < seq) && (std::fabs(e[1]) < seq)
					&& (std::fabs(e[2]) < seq)
			);
		}

		static Vector3 random() {
			return Vector3(random_double(), 
					random_double(), 
					random_double());
		}
		
		static Vector3 random(const double min, const double max) {
			return Vector3(random_double(min, max), 
					random_double(min, max), 
					random_double(min, max));
		}

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

// Utility functions

// insertion stream operator for printing {x,y,z}
inline std::ostream & operator << (std::ostream & output, const Vector3 & vec) {
	return output << vec.arr[0] << ' ' << vec.arr[1] << ' ' << vec.arr[2] << '\n';
}

// Adding two vectors quantities
inline Vector3 operator + (const Vector3 & vec1, const Vector3 & vec2) {
	// x1 + x2, y1 + y2, z1 + z2
	return Vector3(
		(vec1.arr[0] + vec2.arr[0]), (vec1.arr[1] + vec2.arr[1]), (vec1.arr[2] + vec2.arr[2])
	);
}

// Subtracting two vector quantities
inline Vector3 operator - (const Vector3 & vec1, const Vector3 & vec2) {
	// x1 - x2, y1 - y2, z1 - z2
	return Vector3(
		(vec1.arr[0] - vec2.arr[0]), (vec1.arr[1] - vec2.arr[1]), (vec1.arr[2] - vec2.arr[2])
	);	
}

// Multiplies two vector quantities
inline Vector3 operator * (const Vector3 & vec1, const Vector3 & vec2) {
	// x1 * x2, y1 * y2, z1 * z2
	return Vector3(
		(vec1.arr[0] * vec2.arr[0]), (vec1.arr[1] * vec2.arr[1]), (vec1.arr[2] * vec2.arr[2])
	);
}

// Cross Product of two vector quantities
inline Vector3 cross_product(const Vector3 & vec1, const Vector3 & vec2) {

	// Two Vectors: vec1 {x1, y1, z1} and vec2 {x2, y2, z2}
	// Taking the cross product of the two invloves
	// 
	// (y1 * z2) - (z1 * y2)
	// (z1 * x2) - (x1 * z2)
	// (x1 * y2) - (y1 * x2)
	//
	// Looking at it like this gives a better insight into the "cross"
	// To me it becomes a lot more visible. I've represented the code in this
	// way as well: vec1(y/z/x) * vec2(z/x/y) - vec1(z/x/y) * vec2(y/z/x)
	//
	// :))

	return Vector3(
		(vec1.arr[1] * vec2.arr[2]) - (vec1.arr[2] * vec2.arr[1]),
		(vec1.arr[2] * vec2.arr[0]) - (vec1.arr[0] * vec2.arr[2]),
		(vec1.arr[0] * vec2.arr[1]) - (vec1.arr[1] * vec2.arr[0]),
	);
}

// Dot Product of two vector quantities
inline double dot_product(const Vector3 & vec1, const Vector3 & vec2) {
	return (
		(vec1.arr[0] * vec2.arr[0]) + (vec1.arr[1] * vec2.arr[1])+ (vec1.arr[2] * vec2.arr[2])
	);
}

// multiplying a vector quantity by a scalar quantity (just overloads * operator)
inline Vector3 operator * (const Vector3 & vec, double scalar) {
	// scalar * {x,y,z}
	return Vector3(
		(scalar * vec.arr[0]), (scalar * vec.arr[1]), (scalar * vec.arr[2])
	);
}

// dividing a vector quantity by a scalar quantity (yikes)
inline Vector3 operator / (const Vector3 & vec, double scalar) {
	// scalar / {x,y,z}
	return Vector3(
		(scalar / vec.arr[0]), (scalar / vec.arr[1]), (scalar / vec.arr[2])
	);
}

// returns the unit vector quantity i/e vector / its length
inline Vector3 unit(const Vector3 & vec1) {
	return (vec1 / vec1.length());
}

inline Vector3 random_unit_vec() {

	bool random_run = true;
	while(random_run != false) {
		auto parent = Vector3::random(-1 , 1);
		auto len_sq = parent.length_squred();

		if(1e-160 < len_sq && len_sq <= 1) { 
			return (
				parent / sqrt(len_sq)
			);	
		}
	}
}

inline Vector3 random_hemisphere_p(const Vector3 & normal) {
	Vector3 on_unit_sphere = random_unit_vec();

	if(dot_product(on_unit_sphere) > 0.0)
		return on_unit_sphere;

	else return -on_unit_sphere;
}

inline Vector3 reflect(const Vector3 & vec1, const Vector3 & vec2) {
	return vec1 - (2 * dot_product(vec1, vec2) * vec2);
}

#endif
