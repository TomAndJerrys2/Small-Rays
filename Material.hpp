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
		Lambertian(const Colour & albedo) : albedo(albedo_) {}
		
		bool scatter(const ray & ray_in, const HitRecord & record,
				Colour & attenuation, ray & scattered) const override {
			
			auto scatter_dir = record.normal + random_unit_vec();
			scattered = ray(record.x, scatter_dir);
			attenuation = albedo_;

			return true;
		}

	private:
		Colour albedo_;
	
};	

