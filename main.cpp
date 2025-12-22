#include <iostream>

// Project Header
#include "small_rays.hpp"

// 3D Vector Utility
#include "Vector3.hpp"

// Pixel Colours
#include "Colours.hpp"

// Ray Object
#include "Ray.hpp"

Colour get_raycolour(const ray & casted_ray) { return Colour(0, 0, 0); }

// Small Raytracing engine - for learning Graphics Programming
//
// Kyle Brady @ 2025 18/12

// Same Behaviour Currently
const bool generate_image() {
	
	std::cout << "Image Loaded:\n" << IMAGE_HEIGHT << "/" << IMAGE_WIDTH << '\n';
	
	// Rendering our Image;
	// Pixels per row, per column;
	// 
	// Pixels as you see here are generated top down;
	// Colors by convention are represented via doubles from 0.0 <-> 1.0;
	// However, Real values i.e from 0 to 255 (1 Byte) (256 is omitted for signing);
	//
	// Hence we convert via static cast to integers where we can now represent each pixel;
	//
	// via a ppm image (Portable PixMap file);
	
	// Looping through Columns and Rows for each Pixel;
	
	// Check the Image Height is atleast 1
	IMAGE_HEIGHT = (IMAGE_HEIGHT < 1) ? 1 : IMAGE_HEIGHT;

	// Camera Settings
	double focal_length = 1.0, viewport_height = 2.0;
	double viewport_width = viewport_height * (std::static_cast<double>(IMAGE_WIDTH) / IMAGE_HEIGHT);
	double camera_center = Vector3(0, 0, 0); // origin
	
	// for calculating the vectors across horizontially and down the vertical viewport edges
	// this will then be presented depending on where the first pixel meets the viewport
	auto viewport_vec1 = Vector3(viewport_width, 0, 0);
	auto viewport_vec2 = Vector3(0, -viewport_width, 0);

	// Change in horizontal and veritcal vectors from each pixel
	auto delta_vec1 = viewport_vec1 / IMAGE_WIDTH;
	auto delta_vec2 = viewport_vec2 / IMAGE_HEIGHT;

	// Grab the upper most pixel
	auto viewport_upper_left = (camera_center - Vector3(0, 0, focal_length) - (viewport_vec1 / 2)
						- (viewport_vec2 / 2));
	auto original_pixel = (viewport_upper_left + 0.5 * (delta_vec1 + delta_vec2));
	
	// Writes our Pixels to an Image
	for(uint8_t i = 0; i < IMAGE_HEIGHT; i++) {
		
		// faster logging and character flushing
		std::clog << "\rLines Left: " << (IMAGE_HEIGHT - 1) << ' ' << std::flush;

		for(uint8_t j = 0; j < IMAGE_WIDTH; j++) {
			// Important: Think of i as rows and j as columns
			// i.e our vertical and horizontal buffers
			auto pixel_center = (original_pixel + (i * delta_vec1) + (j * delta_vec2));
			auto ray_direction = pixel_center - camera_center;
			ray current_ray(camera_center, ray_direction);
			
			Colour pixel_colour = ray_colour(current_ray);
			write_colour(std::cout, pixel_colour);
		}
	}
	
	std::clog << "\rCompleted Pixel Load! <<<<<<<<<<<<<<< \n";

	// output -> image.ppm file
	return true; // on success;
}

int main() {

	generate_image();

	return EXIT_SUCCESS:
}
