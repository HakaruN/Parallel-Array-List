#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class matrix
{
    public:
        matrix(float* elements, unsigned short size, unsigned short width)
        {

            mMatrixSize = size;
            mWidth = width;
            mHeight = size / width;
            for(unsigned int i = 0; i < size; i++)
            {
                mMatrix[i] = elements[i];
                std::cout << mMatrix[i] << ",";
            }
            std::cout << std::endl;
        }

        //getters and setters
        inline float getElement(unsigned short i)
        {
            return mMatrix[i];
        }
        inline float getElement(unsigned short i, unsigned short j)
        {
            return mMatrix[(j * mWidth) + i];
        }
        inline void setElement(unsigned short i, float value)
        {
            mMatrix[i] = value;
        }
        inline void setElement(unsigned short i, unsigned short j, float value)
        {
            mMatrix[(j * mWidth) + i] = value;
        }

        inline int getRows(){return mWidth;}
        inline int getColumns(){return mHeight;}

        inline matrix matrixMul(matrix B)
        {
            unsigned short BRows = B.getRows();
            unsigned short BCols = B.getColumns();
            unsigned short CRows = mHeight;
            unsigned short CCols = BCols;

            float C[CRows * CCols] = {0};

            for(int ARow = 0; ARow < mHeight; ARow++)
            {
                for(int BCol = 0; BCol < BCols; BCol++)
                {
                    for(int CEntry = 0; CEntry < mWidth; CEntry++)
                    {
                        //C[(ARow * ARows)+ BCol] +=  A[(ARow * ACols)+ CEntry] * B[(CEntry * ARows) + BCol];
                        C[(ARow * mHeight)+ BCol] +=  mMatrix[((ARow * mWidth)+ CEntry)] * B.getElement((CEntry * mHeight) + BCol);
                    }
                }
            }
            return matrix(C, (CRows * CCols), CCols);
        }

        inline void matrixMulAcc(matrix B)
        {
            unsigned short BRows = B.getRows();
            unsigned short BCols = B.getColumns();

            for(int ARow = 0; ARow < mHeight; ARow++)
            {
                for(int BCol = 0; BCol < BCols; BCol++)
                {
                    for(int CEntry = 0; CEntry < mWidth; CEntry++)
                    {
                         mMatrix[(ARow * mHeight)+ BCol] +=  this->getElement((ARow * mWidth)+ CEntry) * B.getElement((CEntry * mHeight) + BCol);
                    }
                }
            }
        }


    private:
        unsigned short mHeight;
        unsigned short mMatrixSize;
        unsigned short mWidth;
        float mMatrix[];

};

#endif
