#include "vec3.h"
#include "vec1.h"
#include "sphere.h"
#include <math.h>

class Ray
{
    public:
        Ray(vec3<float> origin, vec3<float> direction)
            :mOrigin(origin), mDirection(direction)
            {
            mT = 99999999;
            }



        inline vec3<float> getOrigin(){return mOrigin;}
        inline vec3<float> getDirection(){return mDirection;}

        inline void setOrigin(vec3<float> origin){ mOrigin = origin;}
        inline void setDirection(vec3<float> direction){mDirection = direction;}
        inline void setT(float t){mT = t;}

        inline bool sphereIntersect(sphere s)
        {


            vec3<float> L = s.getPos() - mOrigin;
            float tca = L.dot(mDirection);

            if(tca < 0)
                return false;
            float d2 = L.dot(L) - tca * tca;

            if(d2 > s.getRadius().getX() * 2)
                return false;

            float thc = sqrt(s.getRadius().getX() * 2 - d2);
            float t0 = tca - thc;
            float t1 = tca + thc;

            if(t0 > t1)
                std::swap(t0, t1);

            if(t0 < 0)//if t0 is less than zero, check for t1
                t0 = t1;

            if(t0 < 0)//if t1 is < 0, no intersect
                return false;

            const float EPSILON = 0.00001;
            if(t0 <= mT + EPSILON)
                {
                    mT = t0;
                    return true;
                }

            return false;

        }


    private:
        float mT;
        vec3<float> mOrigin;
        vec3<float> mDirection;
};
