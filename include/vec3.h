#ifndef VEC3_H
#define VEC3_H

template<typename T>
class vec3
{
    public:
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

        T getX(){return mX;}
        T getY(){return mY;}
        T getZ(){return mZ;}

        void setX(T x){ mX = x;}
        void setY(T y){ mY = y;}
        void setZ(T z){ mZ = z;}


    protected:
    private:
        T mX = 0, mY = 0, mZ = 0;
};

#endif // VEC3_H
