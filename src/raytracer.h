#ifndef RAYTRACER_H
#define RAYTRACER_H

// Was supposed to be main header file
// But i like it more as just a file for utils
// But i already commited it and i don't want to go through a headache
// So just imagine its name is utils.h

#include <limits>
#include <memory>

// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif