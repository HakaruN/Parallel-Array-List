#ifndef VEC1_H
#define VEC1_H
template<typename T>
class vec1
{
    public:
        vec1(T x)
        {
            mX = x;
        }

        ~vec1()
        {

        }

        vec1(const vec1& other)
        {
    //copy ctor
            mX = other.mX;
        }

        T getX(){return mX;}

        void setX(T x){ mX = x;}


    protected:
    private:
        T mX = 0;
};
#endif // VEC3_H

