#ifndef PARASPHERESTRUC_H
#define PARASPHERESTRUC_H
#include "parallelArrayList.h"
#include "sphere.h"
#include "vec3Pal.h"
#include "vec1Pal.h"

class ParaSphereStruc : public parallelArrayList
{
    public:
        ParaSphereStruc(unsigned long length);
        ~ParaSphereStruc();

        void addItem(vec3<float> pos, vec3<float> colour, vec1<float> radius);
        void addItem(sphere s);

        sphere getItem(unsigned long index);

    protected:
        //member variables for the sphere, these are stored in PALs
        vec3Pal<float> mPositions;
        vec3Pal<float> mColours;
        vec1Pal<float> mRadius;


    private:
};

#endif // PARASPHERESTRUC_H
