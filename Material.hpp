#pragma once

#include "Hittable.hpp"

class Material {
	
	public:
		virtual ~Material() = default;

		virtual bool scatter(const ray & casted_ray, const HitRecord & record,
				Colour & attenuation, ray & scattered) const {
			return false;	
		}
};

class Lambertian : public Material {
	
	public:
		Lambertian(const Colour & albedo) : albedo_(albedo) {}
		
		bool scatter(const ray & ray_in, const HitRecord & record,
				Colour & attenuation, ray & scattered) const override {
			
			auto scatter_dir = record.normal + random_unit_vec();
			
			if(scatter_dir.near_zero())
				scatter_dir = record.normal;

			scattered = ray(record.x, scatter_dir);
			attenuation = albedo_;

			return true;
		}

	private:
		Colour albedo_;
	
};	

class Metal : public Material {
	
	public:
		Metal(const Colour & albedo) : albedo_(albedo) {}

		bool scatter(const ray & ray_in, const HitRecord & record, 
				Colour & attenuation, ray & scattered) const override {
			
			Vector3 reflected = reflect(ray_in.direction(), record.normal);
			scattered = ray(record.x, reflected);
			attenuation = albedo;

			return true;
		}

	private:
		Colour albedo;
};

class Dielectric : public Material {
	
	public:
		Dielectric(const double refraction_index) : refract_index(refraction_index) {}

		bool scatter(const ray & ray_in, const HitRecord & record,
				Colour & attenuation, ray & scattered) const override {
			attenuation = Colour(1.0, 1.0, 1.0);
			double real_index = record.front_face ? (1.0 / refract_index) : refract_index;

			Vector3 unit_dir = unit_vector(ray_in.direction());
			Vector3 refracted = refract(unit_dir, record.normal, real_index);

			scattered = ray(record.x, refracted);
			return true;
		}

	private:
		double refract_index;
		
};

