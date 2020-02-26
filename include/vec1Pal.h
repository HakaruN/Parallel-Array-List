#ifndef VEC1PAL_H
#define VEC1PAL_H
#include "parallelArrayList.h"
#include "vec1.h"
template<typename T>
class vec1Pal : public parallelArrayList
{
    public:
        vec1Pal(unsigned long length)
        {
            this->mLength = length;
            this->mX = new T[mLength];
        }

        ~vec1Pal()
        {
            delete [] mX;
        }


        void addItem(T x)
        {
            mX[mArrayEndIndex] = x;
            mArrayEndIndex++;
        }

        void addItem(vec1<T> vec)
        {
            mX[mArrayEndIndex] = vec.getX();
            mArrayEndIndex++;
        }

        T getItem(unsigned long index)
        {
            T vec1(this->mX[index]);
            return vec1;
        }

        T dot(unsigned long indexOne, unsigned long indexTwo)
        {
            T elementOne = getItem(indexOne);
            T elementTwo = getItem(indexTwo);
            T dotProd = (elementOne * elementTwo);
            return dotProd;
        }

        //allows for setting/updating information in the data structure
        void setItem(unsigned long index, vec1<T> vec)
        {
            mX[index] = vec.getX();
        }
    protected:
        T* mX = 0;


    private:
};


#endif
