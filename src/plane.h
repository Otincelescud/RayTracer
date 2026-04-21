#ifndef PLANE_H
#define PLANE_H

#include "raytracer.h"
#include "vec3.h"
#include "hittable.h"

class plane : public hittable {
public:
    plane(const point3 center, const vec3 norm) : center(center), norm(norm) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = center - r.origin();
        double numerator = dot(norm, oc);
        double divisor = dot(norm, r.direction());

        double t = numerator/divisor;

        if (!ray_t.sorrounds(t)) return false;

        rec.t = t;
        rec.p = r.at(rec.t);
        vec3 outward_normal = norm;
        rec.set_face_normal(r, outward_normal);
        
        return true;
    }

private:
    point3 center;
    vec3 norm;
};

#endif