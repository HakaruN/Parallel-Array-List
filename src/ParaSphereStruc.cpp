#include "../include/ParaSphereStruc.h"


ParaSphereStruc::ParaSphereStruc(unsigned long length)
    : mPositions(length), mColours(length), mRadius(length)
{
    //vec3Pal<float> mPositions(length);
    //vec3Pal<float> mColours(length);
    //vec1Pal<float> mRadius(length);
    //ctor
}

ParaSphereStruc::~ParaSphereStruc()
{

    //dtor
}


void ParaSphereStruc::addItem(vec3<float> pos, vec3<float> colour, vec1<float> radius)
{
    //mPositions.addItem(pos.getX(), pos.getY(), pos.getZ());
    mPositions.addItem(pos);
    //mColours.addItem(colour.getX(), colour.getY(), colour.getZ());
    mColours.addItem(colour);
    mRadius.addItem(radius.getX());
    mArrayEndIndex++;
}

