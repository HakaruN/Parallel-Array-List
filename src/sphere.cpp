#include "../include/sphere.h"

sphere::sphere(vec3<float> pos, vec3<float> colour, vec1<float> radius)
    : mPos(pos), mColour(colour), mRadius(radius)//reg cstr
{
}


vec3<float> sphere::getNormal(vec3<float> hitPoint)
{
    return (hitPoint - mPos);
}
