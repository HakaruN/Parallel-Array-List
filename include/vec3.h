#ifndef VEC3_H
#define VEC3_H

template<typename T>
class vec3
{
    public:
        inline vec3<float> operator + (vec3<float> other){return vec3(mX + other.getX(), mY + other.getY(),mZ + other.getZ());}
        inline vec3<float> operator - (vec3<float> other){return vec3(mX - other.getX(), mY - other.getY(),mZ - other.getZ());}
        inline vec3<float> operator * (float other){return vec3<float>(mX * other, mY * other, mZ * other);}
        inline vec3<float> operator / (float other){return vec3<float>(mX / other, mY / other, mZ / other);}

        vec3(T x, T y, T z)
        {
            mX = x;
            mY = y;
            mZ = z;
        }

        ~vec3()
        {

        }

        vec3(const vec3& other)
        {
    //copy ctor
            mX = other.mX;
            mY = other.mY;
            mZ = other.mZ;
        }

        inline T getX(){return mX;}
        inline T getY(){return mY;}
        inline T getZ(){return mZ;}

        inline void setX(T x){ mX = x;}
        inline void setY(T y){ mY = y;}
        inline void setZ(T z){ mZ = z;}

        inline vec3<T> normalise()
        {
            float magnitude = (float)sqrt(
            mX * mX +
            mY * mY
            );
            return(vec3<T>(
            mX / magnitude,
            mY / magnitude,
            mZ / magnitude
            ));
        }


    protected:
    private:
        T mX = 0, mY = 0, mZ = 0;
};

#endif // VEC3_H
