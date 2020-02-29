#ifndef SPHERE_H
#define SPHERE_H

#include "vec1Pal.h"
#include "vec2Pal.h"
#include "vec3Pal.h"
#include "vec4Pal.h"

class sphere
{
    public:
    sphere(vec3<float> pos, vec3<float> colour, vec1<float> radius);//cnstr

/*
    sphere(const sphere& other)//cpy cnstr
    {
    //vec3<float> pos = other.getPos();
    //vec3<float> colour = other.getColour();
    //vec1<float> radus = other.getRadius();
    }
    */


    void setPos(vec3<float> pos) {mPos = pos;}
    void setRadius(vec1<float> radius) {mRadius = radius;}
    void setColour(vec3<float> colour) {mColour = colour;}

    vec3<float> getPos() {return mPos;}
    vec1<float> getRadius() {return mRadius;}
    vec3<float> getColour() {return mColour;}
    vec3<float> getNormal(vec3<float> hitPoint);

    void offsetPos(vec3<float> offset){mPos = mPos + offset;}

    protected:

    private:
        vec3<float> mPos;
        vec3<float> mColour;
        vec1<float> mRadius;

};

#endif // SPHERE_H
