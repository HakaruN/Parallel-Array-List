#include "include/ParaSphereStruc.h"
#include "include/sphere.h"

#include "include/vec1Pal.h"
#include "include/vec2Pal.h"
#include "include/vec3Pal.h"
#include "include/vec4Pal.h"

#include <iostream>
#include <ctime>
#include <cstdlib>



using namespace std;
int main()
{
    ParaSphereStruc spheres(1000);
    /*  Data structure testing stuff
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
        std::cout << "Vec1 - X: " << vec1s.getItem(i).getX() << std::endl;

        vec2<float> vecTwo = vec2s.getItem(i);
        std::cout << "Vec2 - X: " << vecTwo.getX() << ", Y: " << vecTwo.getY() << std::endl;

        vec3<float> vecThree = vec3s.getItem(i);
        std::cout << "Vec3 - X: " << vecThree.getX() << ", Y: " << vecThree.getY() << ", Z: " << vecThree.getZ() << std::endl;

        vec4<float> vecFour = vec4s.getItem(i);
        std::cout << "Vec4 - X: " << vecFour.getX() << ", Y: " << vecFour.getY() << ", Z: " << vecFour.getZ() << ", W: " << vecFour.getW() << std::endl;

    }
    */


    std::srand(std::time(nullptr));
    for(unsigned short s = 0; s < 20; s++)
    {
        vec3<float> pos(//generate random positions for each sphere with a range between -10 and 10
        (float)std::rand()/(RAND_MAX + 1u) * 20 - 10,
        (float)std::rand()/(RAND_MAX + 1u) * 20 - 10,
        (float)std::rand()/(RAND_MAX + 1u) * 20 - 10
        );

        vec3<float> colour(//generate random colour values with the colours ranging between 0 and 255
        (float)std::rand()/(RAND_MAX + 1u) * 255,
        (float)std::rand()/(RAND_MAX + 1u) * 255,
        (float)std::rand()/(RAND_MAX + 1u) * 255
        );

        vec1<float> radius (//generate a radius between 0 and 10
        (float)std::rand()/(RAND_MAX + 1u) * 10
        );

        spheres.addItem(pos, colour, radius);




    }

    for(unsigned int i = 0; i < 20; i++)
    {
        sphere s = spheres.getItem(i);
        vec3<float> pos = s.getPos();
        vec3<float> colour = s.getColour();
        vec1<float> radius = s.getRadius();

        std::cout << "Pos: " << pos.getX() << ", " << pos.getY() << ", " << pos.getZ() << std::endl;
        std::cout << "Colour: " << colour.getX() << ", " << colour.getY() << ", " << colour.getZ() << std::endl;
        std::cout << "Radius: " << radius.getX() << std::endl;
        std::cout << std::endl;

    }

    return 0;
}
