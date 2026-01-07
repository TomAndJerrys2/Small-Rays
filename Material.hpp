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

