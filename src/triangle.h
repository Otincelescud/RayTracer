#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "raytracer.h"
#include "vec3.h"
#include "hittable.h"
#include "ray.h"
#include "interval.h"
#include "plane.h"

class tri : public plane {
public:
    point3 v1, v2, v3;
    tri(point3 v1, point3 v2, point3 v3) : plane((v1 + v2 + v3) / 3, unit_vector(cross((v1 - v3), (v2 - v3)))), v1(v1), v2(v2), v3(v3) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        if (!plane::hit(r, ray_t, rec)) return false;

        if (dot(cross(v1-v3, rec.p-v3), cross(v2-v3, rec.p-v3)) > 0) return false;
        if (dot(cross(v1-v2, rec.p-v2), cross(v3-v2, rec.p-v2)) > 0) return false;

        return true;
    }

};

#endif