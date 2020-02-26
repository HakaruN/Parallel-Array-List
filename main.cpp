#include <iostream>
#include "include/ParaSphereStruc.h"

#include "include/vec1Pal.h"
#include "include/vec2Pal.h"
#include "include/vec3Pal.h"
#include "include/vec4Pal.h"


using namespace std;
int main()
{
    vec1Pal<float> vec1s(10);
    vec2Pal<float> vec2s(10);
    vec3Pal<float> vec3s(10);
    vec4Pal<float> vec4s(10);

    for(int i = 0; i < 7; i++)
    {
        vec1<float> vecOne(i);
        vec2<float> vecTwo(i, i + 1);
        vec3<float> vecThree(i, i + 1, i + 2);
        vec4<float> vecFour(i, i + 1, i + 2, i + 3);

        vec1s.addItem(vecOne);
        vec2s.addItem(vecTwo);
        vec3s.addItem(vecThree);
        vec4s.addItem(vecFour);
    }

    vec4s.cross(2,3);
    unsigned long palLength = vec3s.getEndIndex();
    std::cout << "number of vectors: " << palLength << std::endl;

    std::cout << std::endl;
    for(unsigned long i = 0; i < palLength; i++)
    {
        //vec3<float> vec(0,0,0);
        //vec = vec3s.getItem(i);

        std::cout<< std::endl << "Vector index: " << i << std::endl;
        vec1<float> vecOne = vec1s.getItem(i);
        std::cout << "Vec1 - X: " << vec1s.getItem(i) << std::endl;

        vec2<float> vecTwo = vec2s.getItem(i);
        std::cout << "Vec2 - X: " << vecTwo.getX() << ", Y: " << vecTwo.getY() << std::endl;

        vec3<float> vecThree = vec3s.getItem(i);
        std::cout << "Vec3 - X: " << vecThree.getX() << ", Y: " << vecThree.getY() << ", Z: " << vecThree.getZ() << std::endl;

        vec4<float> vecFour = vec4s.getItem(i);
        std::cout << "Vec4 - X: " << vecFour.getX() << ", Y: " << vecFour.getY() << ", Z: " << vecFour.getZ() << ", W: " << vecFour.getW() << std::endl;

    }

    return 0;
}
