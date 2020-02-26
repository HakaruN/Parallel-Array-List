#ifndef VEC4PAL_H
#define VEC4PAL_H
#include "parallelArrayList.h"
#include "vec4.h"
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
        vec4<T> getItem(unsigned long index)
        {
            vec4<T> vec(mX[index], mY[index], mZ[index], mW[index]);
            return vec;
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
            T elementOneX = getItem(indexOne).getX();
            T elementOneY = getItem(indexOne).getY();
            T elementOneZ = getItem(indexOne).getZ();
            T elementOneW = getItem(indexOne).getW();

            T elementTwoX = getItem(indexTwo).getX();
            T elementTwoY = getItem(indexTwo).getY();
            T elementTwoZ = getItem(indexTwo).getZ();
            T elementTwoW = getItem(indexTwo).getW();

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
            vec4<T> vecOne = getItem(indexOne);
            vec4<T> vecTwo = getItem(indexTwo);

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

