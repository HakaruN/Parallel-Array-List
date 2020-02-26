#include "../include/sphere.h"

sphere::sphere(vec3<float> pos, vec1<float> radius, vec3<float> colour)
    : mPos(pos), mRadius(radius), mColour(colour)//reg cstr
{
}

sphere::sphere(const sphere& other)
{

}

