#include "raytracer.h"

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "plane.h"
#include "triangle.h"
#include "camera.h"

#include <cmath>

int main() {
    // World

    hittable_list world;

    //world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    //world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
    //world.add(make_shared<tri>(point3(0, -1.5, -1), point3(0, -1.5, -101.5), point3(-101.5, -1.5, -1)));
    vec3 offset(0.0, -0.2, 0.0);
    world.add(make_shared<tri>(
        point3(std::sqrt(3.0)/2, -1.0/2, -1.0)+offset,
        point3(-std::sqrt(3.0)/2, -1.0/2, -1.0)+offset,
        point3(0.0, 1.0, -1.0)+offset
    ));

    // Use Camera
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.initialize();

    cam.render(world);

    return 0;
}