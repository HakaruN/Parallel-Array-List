#ifndef VEC4_H
#define VEC4_H
#include <math.h>

template<typename T>
class vec4
{
    vec4<T> operator + (const vec4<T>& other)
    {
        vec3<T> returnVec;

        //perform the add
        returnVec.setX(other.getX() + mX);
        returnVec.setY(other.getY() + mY);
        returnVec.setZ(other.getZ() + mZ);
        returnVec.setW(other.getW() + mW);

        return returnVec;
    }

    public:
        inline vec4<float> operator + (vec4<float> other){return vec4(mX + other.getX(), mY + other.getY(),mZ + other.getZ(), mW + other.getW());}
        inline vec4<float> operator - (vec4<float> other){return vec4(mX - other.getX(), mY - other.getY(),mZ - other.getZ(), mW - other.getW());}
        inline vec4<float> operator * (float other){return vec4<float>(mX * other, mZ * other, mY * other, mW * other);}
        inline vec4<float> operator / (float other){return vec4<float>(mX / other, mZ / other, mY / other, mW / other);}

        vec4(T x, T y, T z, T w)
        {
            mX = x;
            mY = y;
            mZ = z;
            mW = w;
        }

        ~vec4()
        {

        }

        vec4(const vec4& other)
        {
    //copy ctor
            mX = other.mX;
            mY = other.mY;
            mZ = other.mZ;
            mW = other.mW;
        }

        inline T* getX(){return &mX;}
        inline T* getY(){return &mY;}
        inline T* getZ(){return &mZ;}
        inline T* getW(){return &mW;}

        inline void setX(T x){ mX = x;}
        inline void setY(T y){ mY = y;}
        inline void setZ(T z){ mZ = z;}
        inline void setW(T w){ mW = w;}

        inline vec4<T> normalise()
        {
            float magnitude = (float)sqrt(
            mX * mX +
            mY * mY +
            mZ * mZ +
            mW * mW
            );
            return(vec4<T>(
            mX / magnitude,
            mY / magnitude,
            mZ / magnitude,
            mW / magnitude
            ));
        }


    protected:
    private:
        T mX = 0, mY = 0, mZ = 0, mW = 0;
};

#endif // VEC3_H

