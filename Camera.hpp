#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera {
  public:
    /* Public Camera methods and data members here */

    void render(const hittable& world) {
        //

        //
    }

  private:
    /* Private Camera Accessors and specifications, for example; */

    void initialize() {
        //

        //
    }

    color ray_color(const ray& r, const hittable& world) const {
        //

        //

        return Colour(0.0, 0.0, 0.0);
    }
};

#endif
