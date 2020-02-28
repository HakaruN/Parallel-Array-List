#ifndef VEC2PAL_H
#define VEC2PAL_H
#include "parallelArrayList.h"
#include "vec2.h"
#include <iostream>
template<typename T>
class vec2Pal : public parallelArrayList
{//the vec2Pal is a structure where each element of a vector (X and Y) are stored in parallel arrays, this means that all the X's in the structure are contiguous and all the Y's are contiguous in memory

    public:
        vec2Pal(unsigned long length)
        {
            this->mLength = length;
            this->mX = new T[mLength];
            this->mY = new T[mLength];
        }

        ~vec2Pal()
        {
            delete [] mX;
            delete [] mY;
        }

        void addItem(T x, T y)
        {
            mX[mArrayEndIndex] = x;
            mY[mArrayEndIndex] = y;
            mArrayEndIndex++;

        }

        void addItem(vec2<T> vec)
        {
            mX[mArrayEndIndex] = vec.getX();
            mY[mArrayEndIndex] = vec.getY();
            mArrayEndIndex++;
        }

        vec2<T> getVec(unsigned long index)
        {

            vec2<T> vec(mX[index], mY[index]);
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
            else
            {
                std::cout << "Error, incorrect array ID requested from PAL2, ID: " << arrayID << std::endl;
                return nullptr;
            }
        }

        T dot(unsigned long indexOne, unsigned long indexTwo)
        {
            T elementOneX = getVec(indexOne).getX();
            T elementOneY = getVec(indexOne).getY();

            T elementTwoX = getVec(indexTwo).getX();
            T elementTwoY = getVec(indexTwo).getY();

            T returnVec = (elementOneX * elementTwoX) + (elementOneY * elementTwoY);
            return returnVec;
        }

        //allows for setting/updating information in the data structure
        void setItem(unsigned long index, vec2<T> vec)
        {
            mX[index] = vec.getX();
            mY[index] = vec.getY();
        }

    protected:
        T* mX = 0;
        T* mY = 0;


    private:
};
#endif
