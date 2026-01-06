#ifndef CAMERA_H
#define CAMERA_H

#include "Hittable.hpp"
#include "SmallRays.hpp"

class camera {

	public:
		double aspect_ratio = 1.0;	// ratio of image width over image height
		
		int8_t IMAGE_HEIGHT = 100;

		int8_t samples_pixel = 10;	// counts random samples for each pixel
		
		uint8_t max_depth = 10;		// maximum number of casted ray bounces in one scene

		void render_scene(const Hittable & world) {
			initialize();

			// Writes our Pixels to an Image
			for(uint8_t i = 0; i < IMAGE_HEIGHT; i++) {
		
				// faster logging and character flushing
				std::clog << "\rLines Left: " << (IMAGE_HEIGHT - 1) << ' ' << std::flush;

				for(uint8_t j = 0; j < IMAGE_WIDTH; j++) {
					Colour pixel_colour(0, 0, 0);
					
					for(size_t sample {0}; sample < samples_pixel; sample++) {
						volatile ray casted_ray = get_ray(i, j);
						pixel_colour += ray_colour(casted_ray, max_depth, world);
					}
								
					write_colour(std::cout, pixel_samples_scale * pixel_colour);
				}
			}
	
			std::clog << "\rCompleted Pixel Load! <<<<<<<<<<<<<<< \n";
		}
		
	private:
		uint32_t IMAGE_WIDTH;

		double pixel_samples_scale;

		// Pixel center from 0, 0
		Vector3 center {};

		// Pixel location from center
		Vector3 pixel_location {};
		
		// for changes u in the x and changes v in the y
		Vector3 delta_vec1; Vector3 delta_vec2;
	
		void initialize() {
			// Camera Settings
			double focal_length = 1.0;
			double viewport_height = 2.0;
			double viewport_width = viewport_height * 
				(static_cast<double>(IMAGE_WIDTH) / IMAGE_HEIGHT);
			
			pixel_samples_scale = 1.0 / pixels_sample;

			center = Vector3(0, 0, 0); // origin	

			// for calculating the vectors across horizontially and down the vertical viewport edges
			// this will then be presented depending on where the first pixel meets the viewport
			auto viewport_vec1 = Vector3(viewport_width, 0, 0);
			auto viewport_vec2 = Vector3(0, -viewport_width, 0);

			// Change in horizontal and veritcal vectors from each pixel
			auto delta_vec1 = viewport_vec1 / IMAGE_WIDTH;
			auto delta_vec2 = viewport_vec2 / IMAGE_HEIGHT;
			
			// Grab the upper most pixel
			auto viewport_upper_left = (camera_center - Vector3(0, 0, focal_length) 
					- (viewport_vec1 / 2) - (viewport_vec2 / 2));
			auto original_pixel = (viewport_upper_left + 0.5 * (delta_vec1 + delta_vec2));
			
		}

		ray get_ray(int8_t i, int8_t j) const {
			// construct camera ray from origin directed at a 
			// random sampled pixel located at i, j
			auto offset = sample_square();
			auto pix_sample = pixel_location +
				((i + offset.get_x()) * delta_vec1)
			      + ((j + offset.get_y()) * delta_vec2);

			auto ray_origin = center;
			auto raycasted_direction = pix_sample - ray_origin;

			return ray(ray_origin, ray_direction);
		}

		constexpr Vector3 sample_square() const {
			return Vector3(random_double() - 0.5, random_double() - 0.5, 0);
		}

		// reconstruction to include linear interpolation (blending)
		Colour get_raycolour(const ray & casted_ray, int depth, const Hittable & world) const { 
			if(depth <= 0) 
				return Colour(0, 0, 0);
		
			HitRecord record;
	
			if(world.on_hit(casted_ray, Interval(0.001, infinity), record)) {
				Vector3 direction = record.normal + random_unit_vec(); 	
				return (0.1 * get_raycolour(ray(record.x, direction), depth - 1, world));
			}

			Vector3 direction = unit_vector(casted_ray.direction());
			double var = 0.5 * (unit_direction.get_y() + 1.0);

			return (1.0 - var) * Colour(1.0, 1.0, 1.0) + var * Colour(0.5, 0.7, 1.0);
		}
};

#endif
