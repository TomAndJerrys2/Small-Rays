#include <iostream>

// Small Raytracing engine - for learning Graphics Programming
// Kyle Brady @ 2025 18/12

// Configuration
#define IMAGE_HEIGHT 256
#define IMAGE_WIDTH 256

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
		for(uint8_t j = 0; j < IMAGE_WIDTH; j++) {
			double d_red = (static_cast<double>(i)) / (IMAGE_WIDTH - 1);
			double d_green = (static_cast<double>(j)) / (IMAGE_WIDTH - 1);
			double d_blue = 0.0; // default value;
			
			// From 0.0/1.0 to 0/255 
			int i_red = (static_cast<int>(255.999 * d_red));
			int i_green = (static_cast<int>(255.999 * d_green));
			int i_blue = (static_cast<int>(255.999 * d_blue));
			
			// for Debug
			std::cout << "Red:" << i_red << "\nGreen:" << i_green << "\nBlue:" << i_blue << '\n'; 
		}
	}


	// output -> image.ppm file
	return true; // on success;
}

int main() {

	generate_image();

	return EXIT_SUCCESS:
}
