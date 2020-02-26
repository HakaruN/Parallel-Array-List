#ifndef PARASPHERESTRUC_H
#define PARASPHERESTRUC_H
#include "parallelArrayList.h"
#include "vec3Pal.h"
#include "vec1Pal.h"

class ParaSphereStruc : public parallelArrayList
{
    public:
        ParaSphereStruc(unsigned long length);
        ~ParaSphereStruc();

        void addItem(vec3<float> pos, vec3<float> colour, vec1<float> radius);
        //uLong getEndIndex is a function available to get the array end pointer

    protected:
        vec3Pal<float> mPositions;
        vec3Pal<float> mColours;
        vec1Pal<float> mRadius;


    private:
};

#endif // PARASPHERESTRUC_H
