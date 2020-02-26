#include "../include/ParaSphereStruc.h"
#include <iostream>

ParaSphereStruc::ParaSphereStruc(unsigned long length)
    : mPositions(length), mColours(length), mRadius(length)
{
}

ParaSphereStruc::~ParaSphereStruc()
{
    //nothing needs cleaning up yet (that i know of)
    //dtor
}


void ParaSphereStruc::addItem(vec3<float> pos, vec3<float> colour, vec1<float> radius)
{//will add a sphere to the structure given the components of a sphere
    mPositions.addItem(pos);
    mColours.addItem(colour);
    mRadius.addItem(radius.getX());
    mArrayEndIndex++;
}

void ParaSphereStruc::addItem(sphere s)
{//will add a sphere to the structure with a given sphere
 //   if(mArrayEndIndex = mLength + 1)
 //       stderr("Struct full");

    mPositions.addItem(s.getPos());
    mColours.addItem(s.getColour());
    mRadius.addItem(s.getRadius());
    mArrayEndIndex++;
}

sphere ParaSphereStruc::getItem(unsigned long index)
{//will construct and return a sphere from the structure at the given index
    sphere returnSphere(
    mPositions.getItem(index),
    mColours.getItem(index),
    mRadius.getItem(index)
    );

    return returnSphere;
}
