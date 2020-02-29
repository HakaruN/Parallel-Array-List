#include "include/ParaSphereStruc.h"
#include "include/sphere.h"

#include "include/vec1Pal.h"
#include "include/vec2Pal.h"
#include "include/vec3Pal.h"
#include "include/vec4Pal.h"

#include "include/ray.h"

#include <GL/glew.h>
#include "libs/glfw/include/glfw3.h"
#include <GL/gl.h>

#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <math.h>



int main()
{
    const unsigned short width = 800;
    const unsigned short height = 600;
    const unsigned char coloursPerPixel = 3;

    unsigned char* frameBuffer = new unsigned char[width * height * coloursPerPixel];
    unsigned short* pixelObjectMap = new unsigned short[width * height];


     for(unsigned short y = 0; y < height; y++)
        for(unsigned short x = 0; x < width; x++)
        {
            frameBuffer[((y * width) + x) * coloursPerPixel + 0] = 0;
            frameBuffer[((y * width) + x) * coloursPerPixel + 1] = 0;
            frameBuffer[((y * width) + x) * coloursPerPixel + 2] = 0;

            //this value is used as an index to the last element rendered to this pixel in the PAL containing geometry
            //
            pixelObjectMap[((y * width) + x)] = 0xffff;
        }



    #ifdef DEBUG
    std::cout << glfwGetVersionString() << std::endl;
    #endif // debug

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Error initing glfw" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout<< "Error creating window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Error initing glew" << std::endl;
        return -2;
    }

    glewExperimental = GL_TRUE;

    glfwWindowHint(GLFW_SAMPLES, 4);//4x AA
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//opengl 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//dont want old openGL


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//setting texture repeate mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//texture filtering



    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);//ensure we can capture keypresses
    /* Loop until the user closes the window */

    std::srand(std::time(nullptr));//makes a seed for the random func
    unsigned int nSpheres = 25;
    ParaSphereStruc spheres(nSpheres);//declare a structure to hold 1000 spheres


for(unsigned short s = 0; s < nSpheres; s++)
    {
        vec3<float> pos(//generate random positions for each sphere with a range between -10 and 10
        (float)std::rand()/(RAND_MAX + 1u) * width,
        (float)std::rand()/(RAND_MAX + 1u) * height,
        (float)std::rand()/(RAND_MAX + 1u) * 200 - 10
        );
        vec3<float> colour(//generate random colour values with the colours ranging between 0 and 255
        (float)std::rand()/(RAND_MAX + 1u) * 255,
        (float)std::rand()/(RAND_MAX + 1u) * 255,
        (float)std::rand()/(RAND_MAX + 1u) * 255
        );
        vec1<float> radius (//generate a radius between 0 and 10
        (float)std::rand()/(RAND_MAX + 1u) * 2000
        );
        spheres.addItem(pos, colour, radius);

    }
/*
    for(unsigned int i = 0; i < nSpheres; i++)
    {
        sphere s = spheres.getVec(i);
        vec3<float> pos = s.getPos();
        vec3<float> colour = s.getColour();
        vec1<float> radius = s.getRadius();
        std::cout << "Pos: " << pos.getX() << ", " << pos.getY() << ", " << pos.getZ() << std::endl;
        std::cout << "Colour: " << colour.getX() << ", " << colour.getY() << ", " << colour.getZ() << std::endl;
        std::cout << "Radius: " << radius.getX() << std::endl;
        std::cout << std::endl;
    }

     //Data structure testing stuff
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
        //vec = vec3s.getVec(i);

        std::cout<< std::endl << "Vector index: " << i << std::endl;
        vec1<float> vecOne = vec1s.getVec(i);
        std::cout << "Vec1 - X: " << vec1s.getVec(i).getX() << std::endl;

        vec2<float> vecTwo = vec2s.getVec(i);
        std::cout << "Vec2 - X: " << vecTwo.getX() << ", Y: " << vecTwo.getY() << std::endl;

        vec3<float> vecThree = vec3s.getVec(i);
        std::cout << "Vec3 - X: " << vecThree.getX() << ", Y: " << vecThree.getY() << ", Z: " << vecThree.getZ() << std::endl;

        vec4<float> vecFour = vec4s.getVec(i);
        std::cout << "Vec4 - X: " << vecFour.getX() << ", Y: " << vecFour.getY() << ", Z: " << vecFour.getZ() << ", W: " << vecFour.getW() << std::endl;

    }
*/


    std::ofstream ofs("fpslog", std::ofstream::out);

    bool evenness = false;

    int stepsPerRotation = 4;
    int stride = spheres.getEndIndex() / stepsPerRotation;
    #ifdef DBUG
    std::cout << stepsPerRotation << " steps per rotation, each step is " << stride << " big and it coveres " << spheres.getEndIndex() << " spheres." << std::endl;
    #endif // DBUG

    unsigned char stenNum = 0;
    vec3<float> downGrav(0, -50, 0);


    while (glfwWindowShouldClose(window)== 0 && glfwGetKey(window, GLFW_KEY_Q) != GLFW_PRESS)//allows window to close on 'q' keypress
    {

        auto start = std::chrono::system_clock::now();
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //What we have here is the intersection stage of the pipeline. There is no renderng here just intersections are tested
        Ray ray(vec3<float>(0.0f,0.0f,-1.0f), vec3<float>(0.0f,0.0f,1.0f));
        for(unsigned int idx = 0; idx < width*height; idx++)
        {
            unsigned int x = idx % width;
            unsigned int y = trunc(((float)idx/width));


            ray.setOrigin(vec3<float>(x,y,-1.0f));
            ray.setT(4096);
            if(pixelObjectMap[((y * width) + x)] != 0xffff)//if the pom is pointing to a valid element in the PAL
                bool hits = ray.sphereIntersect(spheres.getVec(pixelObjectMap[((y * width) + x)]));

            for(unsigned short sp = stenNum * stride; sp < (stenNum + 1) * stride; sp++)
            {
                if(sp != pixelObjectMap[((y * width) + x)])//if the current index isnt the thing from last frame which we havn't already checked
                {
                    if(ray.sphereIntersect(spheres.getVec(sp)))
                        pixelObjectMap[((y * width) + x)] = sp;//the intersection is noted for rendering later
                }
            }
        }

        //this is the rendering stage of the pipeline, the intersections previously tested are then rendered here
        for(unsigned int idx = 0; idx < width*height; idx++)
        {
            unsigned int x = idx % width;
            unsigned int y = trunc(((float)idx/width));
            unsigned short sp = pixelObjectMap[((y * width) + x)];
            if(sp != 0xffff)//if the pom is pointing to a valid element in the PAL
            {
                frameBuffer[((y * width) + x) * coloursPerPixel + 0] = spheres.getVec(sp).getColour().getX() * 100;
                frameBuffer[((y * width) + x) * coloursPerPixel + 1] = spheres.getVec(sp).getColour().getY() * 100;
                frameBuffer[((y * width) + x) * coloursPerPixel + 2] = spheres.getVec(sp).getColour().getZ() * 100;
            }
        }



        if(stenNum >= stepsPerRotation)
        {
            stenNum = 0;
        }
        else
        {
            stenNum++;
        }


        glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, frameBuffer);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_time = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        //std::cout << "elapsed time: " << elapsed_time.count() << std::endl;
        ofs << elapsed_time.count() << "\n";
    }

    ofs.close();
    glfwTerminate();





    delete [] frameBuffer;
    return 0;
}
