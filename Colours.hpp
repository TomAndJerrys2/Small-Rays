#ifndef COLOURS_H
#define COLOURS_H

#include "SmallRays.hpp"

using Colour = Vector3;

// Write Colour Pixels via a vector quantity
void write_colour(std::ostream & output, const Colour & p_colour) {

	// Colours scaling from {x, y, z} to be mapped
	auto red = p_colour.get_x();
	auto green = p_colour.get_y();
	auto blue = p_colour.get_z();
	
	// check for optimizations later...
	uint16_t red_byte = std::static_cast<uint16_t>(255.999 * red);
	uint16_t green_byte = std::static_cast<uint16_t>(255.999 * green);
	uint16_t blue_byte = std::static_cast<uint16_t>(255.999 * blue);

	// Writes output from Ostream
	output << red_byte << ' ' << green_byte << ' ' << blue_byte << '\n';
}

#endif
