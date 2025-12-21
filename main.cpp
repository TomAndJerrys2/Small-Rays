#include <iostream>

// Project Header
#include "small_rays.hpp"

// 3D Vector Utility
#include "Vector3.hpp"

// Pixel Colours
#include "Colours.hpp"

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
	for(uint8_t i = 0; i < IMAGE_HEIGHT; i++) {
		
		// faster logging and character flushing
		std::clog << "\rLines Left: " << (IMAGE_HEIGHT - 1) << ' ' << std::flush;

		for(uint8_t j = 0; j < IMAGE_WIDTH; j++) {
			
			auto pixel_colour = Colour(
				double(i) / (IMAGE_WIDTH - 1), double(j) / (IMAGE_HEIGHT - 1), 0
			);

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
