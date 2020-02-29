#ifndef VEC4PAL_H
#define VEC4PAL_H
#include "parallelArrayList.h"
#include "vec4.h"
#include <iostream>
template<typename T>
class vec4Pal : public parallelArrayList
{
    public:
        vec4Pal(unsigned long length)
        {
            this->mLength = length;
            this->mX = new T[mLength];
            this->mY = new T[mLength];
            this->mZ = new T[mLength];
            this->mW = new T[mLength];
        }

        ~vec4Pal()
        {
            delete [] mX;
            delete [] mY;
            delete [] mZ;
            delete [] mW;
        }

        vec4Pal(const vec4Pal& other)
        {
            ~vec4Pal();
            mX = other.mX;
            mY = other.mY;
            mZ = other.mZ;
            mW = other.mW;
        }

        void addItem(T x, T y, T z, T w)
        {
            mX[mArrayEndIndex] = x;
            mY[mArrayEndIndex] = y;
            mZ[mArrayEndIndex] = z;
            mW[mArrayEndIndex] = w;
            mArrayEndIndex++;
        }

        void addItem(vec4<T> vec)
        {
            mX[mArrayEndIndex] = vec.getX();
            mY[mArrayEndIndex] = vec.getY();
            mZ[mArrayEndIndex] = vec.getZ();
            mW[mArrayEndIndex] = vec.getW();
            mArrayEndIndex++;
        }

        //allows for getting an item out of the data structure
        vec4<T> getVec(unsigned long index)
        {
            vec4<T> vec(mX[index], mY[index], mZ[index], mW[index]);
            return vec;
        }

        T* getArray(unsigned char arrayID)
        {
            if(arrayID == 0)
            {
                return mX;
            }
            else if(arrayID == 1)
            {
                return mY;
            }
            else if(arrayID == 3)
            {
                return mZ;
            }
            else if(arrayID == 4)
            {
                return mW;
            }
            else
            {
                std::cout << "Error, incorrect array ID requested from PAL4, ID: " << arrayID << std::endl;
                return nullptr;
            }
        }

        //allows for setting/updating information in the data structure
        void setItem(unsigned long index, vec4<T> vec)
        {
            mX[index] = vec.getX();
            mY[index] = vec.getY();
            mZ[index] = vec.getZ();
            mW[index] = vec.getW();
        }

        //passing the index for two elements and will return the dot of those elements
        T dot(unsigned long indexOne, unsigned long indexTwo)
        {
            T elementOneX = getVec(indexOne).getX();
            T elementOneY = getVec(indexOne).getY();
            T elementOneZ = getVec(indexOne).getZ();
            T elementOneW = getVec(indexOne).getW();

            T elementTwoX = getVec(indexTwo).getX();
            T elementTwoY = getVec(indexTwo).getY();
            T elementTwoZ = getVec(indexTwo).getZ();
            T elementTwoW = getVec(indexTwo).getW();

            T returnVec =
            (elementOneX * elementTwoX) +
            (elementOneY * elementTwoY) +
            (elementOneZ * elementTwoZ) +
            (elementOneW * elementTwoW);
            return returnVec;
        }

        //passing the index for two elements and will return the 3d cross prod in 4d form (leaving W-dim as 0)
        vec4<T> cross(unsigned long indexOne, unsigned long indexTwo)
        {
            vec4<T> vecOne = getVec(indexOne);
            vec4<T> vecTwo = getVec(indexTwo);

            T elementOneX = vecOne.getX();
            T elementOneY = vecOne.getY();
            T elementOneZ = vecOne.getZ();
            //std::cout << "Elements: " << elementOneX << ", " << elementOneY << ", " << elementOneZ << std::endl;


            T elementTwoX = vecTwo.getX();
            T elementTwoY = vecTwo.getY();
            T elementTwoZ = vecTwo.getZ();
            //std::cout << "Elements: " << elementTwoX << ", " << elementTwoY << ", " << elementTwoZ << std::endl;

            vec4<T> normalVec(
            (elementOneY * elementTwoZ - elementOneZ * elementTwoY),
            (elementOneZ * elementTwoX - elementOneX * elementTwoZ),
            (elementOneX * elementTwoY - elementOneY * elementTwoX),
            0
            );


            /*std::cout<< "Normal Vector4 - X:" << normalVec.getX() << " Y: "
            << normalVec.getY() << " Z: " << normalVec.getZ() << std::endl;*/
            return normalVec;

        }

    protected:
        T* mX = 0;
        T* mY = 0;
        T* mZ = 0;
        T* mW = 0;

    private:
};
#endif

