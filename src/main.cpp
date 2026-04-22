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
    vec3 offset(0.0, -0.2, -1.0);
    double angle1=120*pi/180;
    double angle2=-60*pi/180;
    mat3 rot1(vec3(cos(angle1), sin(angle1), 0),
              vec3(-sin(angle1), cos(angle1), 0),
              vec3(0, 0, 1));

    mat3 rot2(vec3(1, 0, 0),
              vec3(0, cos(angle2), sin(angle2)),
              vec3(0, -sin(angle2), cos(angle2)));

    point3 v1(0.0, 1.0, 0.0);
    point3 v2 = rot1*v1;
    point3 v3 = rot1*v2;
    world.add(make_shared<tri>(
        point3(rot2*v1+offset),
        point3(rot2*v2+offset),
        point3(rot2*v3+offset)
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