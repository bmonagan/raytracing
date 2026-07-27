#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera {
  public:
    /* Public Camera PArameters here */

    void render(cosnt hittable& world) {
      ...
    }

  private:
    /* Private camera variables here */

    void initialize(){
      ...
    }

    color ray_color(const ray& r, const hittable& world) const {
      ...
    }
};
