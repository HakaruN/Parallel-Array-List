#ifndef SPHERE_H
#define SPHERE_H

#include "vec1Pal.h"
#include "vec2Pal.h"
#include "vec3Pal.h"
#include "vec4Pal.h"

class sphere
{
    public:
    sphere(vec3<float> pos, vec1<float> radius, vec3<float> colour);//cnstr
    sphere(const sphere& other);//cpy cnstr
    ~sphere();//dstr

    void setPos(vec3<float> pos) {mPos = pos;}
    void setRadius(vec1<float> radius) {mRadius = radius;}
    void setColour(vec3<float> colour) {mColour = colour;}

    vec3<float> getPos() {return mPos;}
    vec1<float> getRadius() {return mRadius;}
    vec3<float> getColour() {return mColour;}

    protected:

    private:
        vec3<float> mPos;
        vec1<float> mRadius;
        vec3<float> mColour;


};

#endif // SPHERE_H
