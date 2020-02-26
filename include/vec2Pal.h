#ifndef VEC2PAL_H
#define VEC2PAL_H
#include "parallelArrayList.h"
#include "vec2.h"
template<typename T>
class vec2Pal : public parallelArrayList
{
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

        vec2<T> getItem(unsigned long index)
        {

            vec2<T> vec(mX[index], mY[index]);
            return vec;

        }

        T dot(unsigned long indexOne, unsigned long indexTwo)
        {
            T elementOneX = getItem(indexOne).getX();
            T elementOneY = getItem(indexOne).getY();

            T elementTwoX = getItem(indexTwo).getX();
            T elementTwoY = getItem(indexTwo).getY();

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
