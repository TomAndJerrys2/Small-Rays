#ifndef COLOURS_H
#define COLOURS_H

#include "SmallRays.hpp"

#define COLOUR_SIZE 256

using Colour = Vector3;

inline double linear_gamma(const double linear_comp) {
	if(linear_comp > 0)
		return std::sqrt(linear_comp);

	return 0;
}

// Write Colour Pixels via a vector quantity
void write_colour(std::ostream & output, const Colour & p_colour) {

	// Colours scaling from {x, y, z} to be mapped
	auto red = p_colour.get_x();
	auto green = p_colour.get_y();
	auto blue = p_colour.get_z();
	
	red = linear_gamme(red);
	green = linear_gamma(green);
	blue = linear_gamma(blue);

	static const interval intensity(0.000, 0.999);

	// check for optimizations later...
	uint16_t red_byte = static_cast<uint16_t>(
		COLOUR_SIZE * intensity.clamp(red)
	);

	uint16_t green_byte = static_cast<uint16_t>(
		COLOUR_SIZE * intensity.clamp(green)
	);

	uint16_t blue_byte = static_cast<uint16_t>(
		COLOUR_SIZE * intensity.clamp(blue)
	);

	// Writes output from Ostream
	output << red_byte << ' ' << green_byte << ' ' << blue_byte << '\n';
}

#endif
