#ifndef VEC1_H
#define VEC1_H
template<typename T>
class vec1
{//the vec1 is just a single number but ive made a class for it for consistency, its a template so could be a number of any type
    public:
        vec1(T x)
        {
            mX = x;
        }

        ~vec1()
        {
            //nothing needs cleaning up yet (that i know of)
        }

        vec1(const vec1& other)
        {//copy ctor
            mX = other.mX;
        }

        T getX(){return mX;}
        void setX(T x){ mX = x;}


    protected:
    private:
        T mX = 0;
};
#endif // VEC3_H

