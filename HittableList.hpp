#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "Hittable.hpp"
// #include "RayMemory.hpp"

#include <vector>

// Smart Pointer to make references shared by
// a reference count
using std::make_shared; using std::shared_ptr;

class HittableList : public Hittable {

	public:
		// A vector to store shared pointers
		// that point to Hittable Objects
		// this Smart pointer makes this useful
		// as multiple rays may hit multiple objects
		std::vector<shared_ptr<Hittable>> hit_objects;

		HittableList() {}
		HittableList(shared_ptr<Hittable> hit_obj) { obj_push(hit_obj); }
		
		// from vector
		void clear() { hit_objects.clear(); }

		void obj_push(shared_ptr<Hittable> hit_obj) { hit_obj.push_back(hit_obj); }
		
		bool on_hit(const ray & casted_ray, Interval ray_time, 
				HitRecord & record) const override {

			HitRecord temp_record;
			bool has_hit = false;
			auto closest = ray_time.max;

			for(const auto & obj : hit_objects) {
				if(hit_objects->on_hit(casted_ray, Interval(ray_time.min, closest), 
							temp_record)) {
					
					has_hit = true;
					closest = temp_record.x;
					record = temp_record;
				}
			}

			return has_hit;
		}
};

#endif
