#include "include/ParaSphereStruc.h"
#include "include/sphere.h"

#include "include/matrix.h"

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
#include <thread>
#include <omp.h>



int main()
{
    const unsigned short width = 600;
    const unsigned short height = 400;
    const unsigned char coloursPerPixel = 3;
    const float invWidth = 1.0f / width;

    unsigned char* frameBuffer = new unsigned char[width * height * coloursPerPixel];
    unsigned short* pixelObjectMap = new unsigned short[width * height];

    float a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float b[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    matrix A(a, 9, 3);
    matrix B(b, 9, 3);

    matrix C = A.matrixMul(B);

    for(unsigned char i = 0; i < 9; i++)
        std::cout << C.getElement(i) << std::endl;


     for(unsigned short y = height - 1; y > 0; --y)
        for(unsigned short x = 0; x < width; x++)
        {
            frameBuffer[((y * width) + x) * coloursPerPixel + 0] = 0;
            frameBuffer[((y * width) + x) * coloursPerPixel + 1] = 0;
            frameBuffer[((y * width) + x) * coloursPerPixel + 2] = 0;

            //this value is used as an index to the last element rendered to this pixel in the PAL containing geometry
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
    unsigned int nSpheres = 10;
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


    std::ofstream ofs("fpslog", std::ofstream::out);

    unsigned int numberOfSpheres = spheres.getEndIndex();
    unsigned int stepsPerRotation = 20;
    if(stepsPerRotation > nSpheres)
    {
        std::cerr << "Error, steps per rotation cannot be more than the number of spheres, setting steps per rotation to number of sphears" << std::endl;
        stepsPerRotation = nSpheres;
    }
    int stride = numberOfSpheres / stepsPerRotation;
    unsigned char stepNum = 0;

    vec3<float> downGrav(0, -10, 0);

    while (glfwWindowShouldClose(window)== 0 && glfwGetKey(window, GLFW_KEY_Q) != GLFW_PRESS)//allows window to close on 'q' keypress
    {
        auto start = std::chrono::system_clock::now();


        //this is the simulation stage of the sim
        #pragma omp parallel for
        for(unsigned short spIdx = stepNum * stride; spIdx < (stepNum + 1) * stride; spIdx++)
        {
            vec3<float> newVec = spheres.getSphere(spIdx).getPos();
            if(newVec.getY() < 0)
                newVec.setY(height);

            newVec.setX(newVec.getX() + downGrav.getX());
            newVec.setY(newVec.getY() + downGrav.getY());
            newVec.setZ(newVec.getZ() + downGrav.getZ());
            spheres.setPos(spIdx, newVec);
        }

        //clear the frame buffer
        #pragma omp parallel for
        for(unsigned short y = height - 1; y > 0; --y)
            for(unsigned short x = 0; x < width; x++)
            {
                frameBuffer[((y * width) + x) * coloursPerPixel + 0] = 0;
                frameBuffer[((y * width) + x) * coloursPerPixel + 1] = 0;
                frameBuffer[((y * width) + x) * coloursPerPixel + 2] = 0;
            }
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        //What we have here is the intersection stage of the pipeline. There is no renderng here just intersections are tested
        #pragma omp parallel for
        for(unsigned short y = height - 1; y > 0; --y)
        {
            for(unsigned short x = 0; x < width; x++)
            {
                Ray ray(vec3<float>(0.0f,0.0f,-1.0f), vec3<float>(0.0f,0.0f,1.0f));
                //adjust the rays origin to be the new pixel position
                ray.setOrigin(vec3<float>(x,y,-1.0f));
                //set the T value for the comming intersections, this will be the max visible range and set to a power of 2 as it may be faster idk
                ray.setT(4096);

                unsigned long pixelIndex = ((y * width) + x);//the pixel coords that will be the index into the POM

                bool hasIntersection = false;//this will tell if a pixel has had an intersction this frame
                if(pixelObjectMap[pixelIndex] != 0xffff)//if last frame resulted on a map between a geometry and this pixel
                {//then we can see if the piece of geometry is still there
                    if(ray.sphereIntersect(spheres.getSphere(pixelObjectMap[pixelIndex])))
                        hasIntersection = true;

                //if we know what was intersected last frame then we can temporaly clip out some spheres
                for(unsigned short spIdx = stepNum * stride; spIdx < (stepNum + 1) * stride; spIdx++)
                {
                    if(spIdx <= numberOfSpheres)
                        if(spIdx != pixelObjectMap[pixelIndex])//if the current index isnt the thing from last frame which we just checked
                        {
                            if(ray.sphereIntersect(spheres.getSphere(spIdx)))
                            {
                                pixelObjectMap[pixelIndex] = spIdx;//the intersection is noted for rendering later
                                hasIntersection = true;
                            }
                        }
                }
                if(!hasIntersection)//if there was nothing in there then we set the pom for this pixel to no detected objects
                    pixelObjectMap[pixelIndex] = 0xffff;

                }
                else//if there the was nothing last frame then we must check all spheres
                {
                    for(unsigned short spIdx = 0; spIdx < numberOfSpheres; spIdx++)
                    {
                        if(spIdx <= numberOfSpheres)
                            if(ray.sphereIntersect(spheres.getSphere(spIdx)))
                            {
                                pixelObjectMap[pixelIndex] = spIdx;//the intersection is noted for rendering later
                                hasIntersection = true;
                            }
                    }
                }
            }
        }

        //this is the rendering stage of the pipeline, the intersections previously tested are then rendered here
        #pragma omp parallel for
        for(unsigned short y = height - 1; y > 0; --y)
            for(unsigned short x = 0; x < width; x++)
            {
                unsigned long pixelIndex = ((y * width) + x);
                unsigned short spID = pixelObjectMap[pixelIndex];
                if(spID != 0xffff)//if the pom is pointing to a valid element in the PAL
                {
                    frameBuffer[((y * width) + x) * coloursPerPixel + 0] = spheres.getSphere(spID).getColour().getX() * 100;
                    frameBuffer[((y * width) + x) * coloursPerPixel + 1] = spheres.getSphere(spID).getColour().getY() * 100;
                    frameBuffer[((y * width) + x) * coloursPerPixel + 2] = spheres.getSphere(spID).getColour().getZ() * 100;
                }
            }

        //because the index is 0'th based then we need to check agaisnt stepts per rotation -1 at number of steps is 1'th based
        if(stepNum >= stepsPerRotation -1)
        {
            stepNum = 0;
        }
        else
        {
            stepNum++;
        }

        glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, frameBuffer);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_time = end-start;
        //std::cout << "elapsed time: " << elapsed_time.count() << std::endl;
        ofs << elapsed_time.count() << "\n";
    }

    ofs.close();
    glfwTerminate();

    delete [] frameBuffer;
    delete [] pixelObjectMap;
    return 0;
}
