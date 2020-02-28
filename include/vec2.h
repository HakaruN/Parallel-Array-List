#ifndef VEC2_H
#define VEC2_H
template<typename T>
class vec2
{
   public:
        inline vec2<float> operator + (vec2<float> other){return vec2(mX + other.getX(), mY + other.getY());}
        inline vec2<float> operator - (vec2<float> other){return vec2(mX - other.getX(), mY - other.getY());}
        inline vec2<float> operator * (float other){return vec2<float>(mX * other, mY * other);}
        inline vec2<float> operator / (float other){return vec2<float>(mX / other, mY / other);}

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

        inline vec2<T> normalise()
        {
            float magnitude = (float)sqrt(
            mX * mX +
            mY * mY
            );
            return(vec2<T>(
            mX / magnitude,
            mY / magnitude
            ));
        }


    protected:
    private:
        T mX = 0;
        T mY = 0;
};
#endif // VEC3_H


