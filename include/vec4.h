#ifndef VEC4_H
#define VEC4_H

template<typename T>
class vec4
{
    vec3<T> operator + (const vec3<T>& other)
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

        T getX(){return mX;}
        T getY(){return mY;}
        T getZ(){return mZ;}
        T getW(){return mW;}

        void setX(T x){ mX = x;}
        void setY(T y){ mY = y;}
        void setZ(T z){ mZ = z;}
        void setW(T w){ mW = w;}


    protected:
    private:
        T mX = 0, mY = 0, mZ = 0, mW = 0;
};

#endif // VEC3_H

