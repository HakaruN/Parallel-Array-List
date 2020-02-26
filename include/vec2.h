#ifndef VEC2_H
#define VEC2_H
template<typename T>
class vec2
{
   public:
        vec2(T x, T y)
        {
            mX = x;
            mY = y;
        }

        ~vec2()
        {

        }

        vec2(const vec2& other)
        {
            //copy ctor
            mX = other.mX;
            mY = other.mY;
        }

        T getX(){return mX;}
        T getY(){return mY;}

        void setX(T x){ mX = x;}
        void setY(T y){ mY = y;}


    protected:
    private:
        T mX = 0;
        T mY = 0;
};
#endif // VEC3_H


