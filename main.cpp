// Project Header
#include "SmallRays.hpp"

// Object to be Rendered
#include "Sphere.hpp"

// Collision List detection
#include "Hittable.hpp"
#include "HittableList.hpp"

#include <stdint.h>

// reconstruction to include linear interpolation (blending)
const inline Colour get_raycolour(const ray & casted_ray, const Hittable & world) { 
	HitRecord record;
	
	if(world.on_hit(casted_ray, Interval(0, infinity), record))
		return (0.5 * (record.normal_val + Colour(1, 1, 1));

	Vector3 direction = unit_vector(casted_ray.direction());
	double var = 0.5 * (unit_direction.get_y() + 1.0);

	return (1.0 - var) * Colour(1.0, 1.0, 1.0) + var * Colour(0.5, 0.7, 1.0);
}

// Small Raytracing engine - for learning Graphics Programming
//
// Kyle Brady @ 2025 18/12

int main() {

	// World Environment - Main rendering scene
	HittableList world;

	world.obj_push(make_shared<Sphere>(Vector3(0, 0, -1), 0.5));
	world.obj_push(make_shared<Sphere>(Vector3(0, -100.5, -1), 100);

	Camera world_camera;
	world_camera.aspect_ratio = 16.0 / 9.0;
	world_camera.IMAGE_WIDTH = 400;
	world_camera.samples_per_pixel = 100;

	world_camera.render(world);

	return EXIT_SUCCESS;
}
