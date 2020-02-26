#ifndef VEC3PAL_H
#define VEC3PAL_H
#include "parallelArrayList.h"
#include "vec3.h"
template<typename T>
class vec3Pal : public parallelArrayList
{
    public:
        vec3Pal(unsigned long length)
        {
            this->mLength = length;
            this->mX = new T[mLength];
            this->mY = new T[mLength];
            this->mZ = new T[mLength];
        }

        ~vec3Pal()
        {
            delete [] mX;
            delete [] mY;
            delete [] mZ;
        }

        void addItem(T x, T y, T z)
        {
            mX[mArrayEndIndex] = x;
            mY[mArrayEndIndex] = y;
            mZ[mArrayEndIndex] = z;
            mArrayEndIndex++;

        }

        void addItem(vec3<T> vec)
        {
            mX[mArrayEndIndex] = vec.getX();
            mY[mArrayEndIndex] = vec.getY();
            mZ[mArrayEndIndex] = vec.getZ();
            mArrayEndIndex++;
        }

        vec3<T> getItem(unsigned long index)
        {
            vec3<T> vec(mX[index], mY[index], mZ[index]);
            return vec;
        }

       T dot(unsigned long indexOne, unsigned long indexTwo)
        {
            T elementOneX = getItem(indexOne).getX();
            T elementOneY = getItem(indexOne).getY();
            T elementOneZ = getItem(indexOne).getZ();

            T elementTwoX = getItem(indexTwo).getX();
            T elementTwoY = getItem(indexTwo).getY();
            T elementTwoZ = getItem(indexTwo).getZ();

            T returnVec =
            (elementOneX * elementTwoX) +
            (elementOneY * elementTwoY) +
            (elementOneZ * elementTwoZ);
            return returnVec;
        }

        vec3<T> cross(unsigned long indexOne, unsigned long indexTwo)
        {
            vec3<T> vecOne = getItem(indexOne);
            vec3<T> vecTwo = getItem(indexTwo);

            T elementOneX = vecOne.getX();
            T elementOneY = vecOne.getY();
            T elementOneZ = vecOne.getZ();
            //std::cout << "Elements: " << elementOneX << ", " << elementOneY << ", " << elementOneZ << std::endl;


            T elementTwoX = vecTwo.getX();
            T elementTwoY = vecTwo.getY();
            T elementTwoZ = vecTwo.getZ();
            //std::cout << "Elements: " << elementTwoX << ", " << elementTwoY << ", " << elementTwoZ << std::endl;

            vec3<T> normalVec(
            (elementOneY * elementTwoZ - elementOneZ * elementTwoY),
            (elementOneZ * elementTwoX - elementOneX * elementTwoZ),
            (elementOneX * elementTwoY - elementOneY * elementTwoX)
            );


            /*std::cout<< "Normal Vector4 - X:" << normalVec.getX() << " Y: "
            << normalVec.getY() << " Z: " << normalVec.getZ() << std::endl;*/
            return normalVec;

        }

        //allows for setting/updating information in the data structure
        void setItem(unsigned long index, vec3<T> vec)
        {
            mX[index] = vec.getX();
            mY[index] = vec.getY();
            mZ[index] = vec.getZ();
        }

    protected:
        T* mX = 0;
        T* mY = 0;
        T* mZ = 0;


    private:
};

#endif
