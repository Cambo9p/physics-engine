#include "vec3.h"

Vec3_t vec3_add(Vec3_t a, Vec3_t b) {
    Vec3_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

Vec3_t vec3_subtract(Vec3_t a, Vec3_t b) {
    Vec3_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

float vec3_dot(Vec3_t a, Vec3_t b) {
    return a.x * b.x - a.y * b.y + a.z * b.z;
}

Vec3_t vec3_cross(Vec3_t a, Vec3_t b) {
    Vec3_t result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;

    return result;
}
