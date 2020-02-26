#ifndef VEC1PAL_H
#define VEC1PAL_H
#include "parallelArrayList.h"
#include "vec1.h"
template<typename T>
class vec1Pal : public parallelArrayList
{
    public:
        vec1Pal(unsigned long length)
        {//take the length of the structure we want and make a new array of that length
            this->mLength = length;
            this->mX = new T[mLength];
        }

        ~vec1Pal()
        {
            delete [] mX;//delete the array that stores the 1d numbers
        }


        void addItem(T x)
        {//add item to the end and increment the end pointer
            mX[mArrayEndIndex] = x;
            mArrayEndIndex++;
        }

        void addItem(vec1<T> vec)
        {//same as above but takes in a vec1 template
            mX[mArrayEndIndex] = vec.getX();
            mArrayEndIndex++;
        }

        vec1<T> getItem(unsigned long index)
        {//will return an item from the strucure given an index into the array
            T vec1(this->mX[index]);
            return vec1;
        }

        T dot(unsigned long indexOne, unsigned long indexTwo)
        {//does a dot product on 2 1d vectors (so is basically a scalar mult)
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
