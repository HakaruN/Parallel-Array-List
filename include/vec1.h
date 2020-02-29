#ifndef VEC1_H
#define VEC1_H
template<typename T>
class vec1
{//the vec1 is just a single number but ive made a class for it for consistency, its a template so could be a number of any type
    public:
        inline vec1<float> operator + (vec1<float> other){return vec1(mX + other.getX());}
        inline vec1<float> operator - (vec1<float> other){return vec1(mX - other.getX());}
        inline vec1<float> operator * (float other){return vec1<float>(mX * other);}
        inline vec1<float> operator / (float other){return vec1<float>(mX / other);}

        vec1(T x)
        {
            mX = x;
        }

        vec1(const vec1& other)
        {
            mX = other.mX;
        }


        T getX(){return mX;}
        void setX(T x){ mX = x;}

        inline vec1<T> normalise()
        {
            float magnitude = (float)sqrt(
            mX * mX
            );

            return(vec1<T>(
            mX / magnitude
            ));
        }


    protected:
    private:
        T mX = 0;
};
#endif // VEC3_H

