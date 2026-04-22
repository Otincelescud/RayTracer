#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
#include <type_traits>

template<typename T> class vector_like3 {
public:
    T e[3];

    vector_like3() : e{0,0,0} {}
    vector_like3(T e0, T e1, T e2) : e{e0, e1, e2} {}

    T x() const { return e[0]; }
    T y() const { return e[1]; }
    T z() const { return e[2]; }
    
    vector_like3<T> operator-() const { return vector_like3<T>(-e[0], -e[1], -e[2]); }
    T operator[](int i) const { return e[i]; }
    T& operator[](int i) { return e[i]; }

    vector_like3<T>& operator+=(const vector_like3<T>& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vector_like3<T>& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vector_like3<T>& operator/=(double t) {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
    }

    double length() const requires std::is_same_v<T, double> {
        return std::sqrt(length_squared());
    }

    double length_squared() const requires std::is_same_v<T, double> {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// Define Alias
using vec3 = vector_like3<double>;
using point3 = vector_like3<double>;
using mat3 = vector_like3<vector_like3<double>>;

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t*v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

template<typename T> inline T dot(const vector_like3<T>& u, const vec3& v) {
    return u.e[0] * v.e[0] +
           u.e[1] * v.e[1] +
           u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

inline vec3 operator*(const mat3& m, const vec3& v) { return dot(m, v); }
inline mat3 operator*(const mat3& m, const mat3& m2) { return mat3(m*m2.e[0], m*m2.e[1], m*m2.e[2]); }

#endif