#ifndef VEC3_H
#define VEC3_H

typedef struct {
    float x;
    float y;
    float z;
} Vec3_t;

// adds vector a to vector b
Vec3_t vec3_add(Vec3_t a, Vec3_t b);

// subtracts vec b from a 
Vec3_t vec3_subtract(Vec3_t a, Vec3_t b);

// dot product of two vectors
float vec3_dot(Vec3_t a, Vec3_t b);

// cross product of two vectors
Vec3_t vec3_cross(Vec3_t a, Vec3_t b);

#endif /* VEC3_H */
