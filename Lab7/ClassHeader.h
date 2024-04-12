#ifndef CLASSHEADER_H
#define CLASSHEADER_H

#include <string>

class Shape
{

protected:
    char *name;
    float *position;
    float sideLength;

public:
    Shape()
    {
        name = new char[NAME_SIZE];
        strcpy(name, "Shape");
        position = new float[POSITION_SIZ];
        position[0] = 0;
        position[1] = 0;
        sideLength = 0;
    }

    ~Shape()
    {
        delete[] name;
        delete[] position;
    }

    float getSideLength() const
    {
        return sideLength;
    }

    float *getPosition() const
    {
        return position;
    }
};

#endif