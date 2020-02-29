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

        sphere getVec(unsigned long index);

                //allows for setting/updating information in the data structure
        void setItem(unsigned long index, sphere s);


    protected:
        //member variables for the sphere, these are stored in PALs
        vec3Pal<float> mPositions;
        vec3Pal<float> mColours;
        vec1Pal<float> mRadius;


    private:
};

#endif // PARASPHERESTRUC_H
