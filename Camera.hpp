#ifndef CAMERA_H
#define CAMERA_H

#include "Hittable.hpp"
#include "SmallRays.hpp"

class camera {

	public:
		
	
		void render_scene(const Hittable & world) {
			initialize();

			// Writes our Pixels to an Image
			for(uint8_t i = 0; i < IMAGE_HEIGHT; i++) {
		
				// faster logging and character flushing
				std::clog << "\rLines Left: " << (IMAGE_HEIGHT - 1) << ' ' << std::flush;

				for(uint8_t j = 0; j < IMAGE_WIDTH; j++) {
					// Important: Think of i as rows and j as columns
					// i.e our vertical and horizontal buffers
					auto pixel_center = (original_pixel + (i * delta_vec1) 
							+ (j * delta_vec2));

					auto ray_direction = pixel_center - camera_center;
					ray current_ray(camera_center, ray_direction);
			
					Colour pixel_colour = ray_colour(current_ray, world);
					write_colour(std::cout, pixel_colour);
				}
			}
	
			std::clog << "\rCompleted Pixel Load! <<<<<<<<<<<<<<< \n";
		}
		
	private:
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
				(std::static_cast<double>(IMAGE_WIDTH) / IMAGE_HEIGHT);

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

		// reconstruction to include linear interpolation (blending)
		constexpr Colour get_raycolour(const ray & casted_ray, const Hittable & world) { 
			HitRecord record;
	
			if(world.on_hit(casted_ray, Interval(0, infinity), record))
				return (0.5 * (record.normal_val + Colour(1, 1, 1));

			Vector3 direction = unit_vector(casted_ray.direction());
			double var = 0.5 * (unit_direction.get_y() + 1.0);

			return (1.0 - var) * Colour(1.0, 1.0, 1.0) + var * Colour(0.5, 0.7, 1.0);
		}
};

#endif
