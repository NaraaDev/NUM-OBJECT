#include <iostream>
#include <cmath>

#include "ClassHeader.h"

#define PI 3.14

using namespace std;

class Circle : public Shape
{

private:
    static constexpr int NAME_SIZE = 7;
    static constexpr int POSITION_SIZE = 2;

public:
    Circle()
    {
        name = new char[NAME_SIZE];
        strcpy(name, "circle");
        position = new float[POSITION_SIZE];
        position[0] = position[1] = sideLength = 0;
    }

    Circle(float radius, float x, float y)
    {
        name = new char[7];
        strcpy(name, "circle");
        position = new float[2];
        sideLength = radius;
        position[0] = x;
        position[1] = y;
    }
    ~Circle()
    {
        delete[] name;
        delete[] position;
    }
    float findSize() const
    {
        return PI * sideLength * sideLength;
    }

    float findPerimeter() const
    {
        return 2 * PI * sideLength;
    }

    void setSideLength(float sideLength)
    {
        if (sideLength <= 0)
            return;
        this->sideLength = sideLength;
    }

    float getSideLength() const
    {
        return this->sideLength;
    }

    void setPosition(float x, float y)
    {
        position[0] = x;
        position[1] = y;
    }
};

class Square : public Shape
{
private:
    static constexpr int NAME_SIZE = 7;
    static constexpr int POSITION_SIZE = 8;

    void calculatePosition(float x, float y)
    {
        position[0] = x;
        position[1] = y;
        position[2] = x;
        position[3] = y - sideLength;
        position[4] = x + sideLength;
        position[5] = y - sideLength;
        position[6] = x + sideLength;
        position[7] = y;
    }

public:
    Square()
    {
        name = new char[NAME_SIZE];
        strcpy(name, "square");
        position = new float[POSITION_SIZE];
        sideLength = 0;
        for (int i = 0; i < 8; i++)
        {
            position[i] = 0;
        }
    }

    Square(float sideLength, float x, float y)
    {
        name = new char[7];
        strcpy(name, "square"); 
        position = new float[8];
        this->sideLength = sideLength;
        calculatePosition(x, y);
    }
    ~Square()
    {
        delete[] name;
        delete[] position;
    }
    float findSize() const
    {
        return sideLength * sideLength;
    }

    float findPerimeter() const
    {
        return 4 * sideLength;
    }

    void setPosition(float x, float y)
    {
        calculatePosition(x, y);
    }

    void setSideLength(float sideLength)
    {
        if (sideLength <= 0)
            return;
        this->sideLength = sideLength;
        setPosition(position[0], position[1]);
    }
};

class Triangle : public Shape
{
private:
    static constexpr int NAME_SIZE = 9;
    static constexpr int POSITION_SIZE = 6;
    float SQRT3 = sqrt(3);

    void calculatePosition(float x, float y)
    {
        position[0] = x;
        position[1] = y;
        position[2] = x - sideLength / 2;
        position[3] = y - sideLength / 2 * SQRT3;
        position[4] = x + sideLength / 2;
        position[5] = y - sideLength / 2 * SQRT3;
    }

public:
    Triangle()
    {
        name = new char[NAME_SIZE];
        position = new float[POSITION_SIZE];
        strcpy(name, "triangle");
        for (int i = 0; i < POSITION_SIZE; i++)
        {
            position[i] = 0;
        }
    }

    Triangle(float sideLength, float x, float y)
    {
        name = new char[9];
        strcpy(name, "triangle");
        position = new float[6];
        this->sideLength = sideLength;
        calculatePosition(x, y);
    }
    ~Triangle()
    {
        delete[] name;
        delete[] position;
    }
    float findSize() const
    {
        return (sideLength * sideLength * sqrt(3)) / 4;
    }

    float findPerimeter() const
    {
        return 3 * sideLength;
    }

    void setPosition(float x, float y)
    {
        calculatePosition(x, y);
    }

    void setSideLength(float sideLength)
    {
        if (sideLength <= 0)
            return;
        this->sideLength = sideLength;
        setPosition(position[0], position[1]);
    }
};

int main()
{
    Square square(10, 0, 0);
    Circle circle(10, 0, 0);
    Triangle triangle(10, 0, 0);

    cout << "Дугуйн хэмжээ: " << circle.findSize() << '\n';
    cout << "Дугуйн периметр: " << circle.findPerimeter() << '\n';

    circle.setPosition(1, 1);
    circle.setSideLength(11);

    cout << "Дугуйн хэмжээ: " << circle.findSize() << '\n';
    cout << "Дугуйн периметр: " << circle.findPerimeter() << '\n';

    cout << "Дөрвөлжингийн хэмжээ: " << square.findSize() << '\n';
    cout << "Дөрвөлжингийн периметр: " << square.findPerimeter() << '\n';

    square.setPosition(1, 1);
    square.setSideLength(11);

    cout << "Дөрвөлжингийн хэмжээ: " << square.findSize() << '\n';
    cout << "Дөрвөлжингийн периметр: " << square.findPerimeter() << '\n';

    cout << "Гурвалжингийн хэмжээ: " << triangle.findSize() << '\n';
    cout << "Гурвалжингийн периметр: " << triangle.findPerimeter() << '\n';

    triangle.setPosition(1, 1);
    triangle.setSideLength(11);

    cout << "Гурвалжингийн хэмжээ: " << triangle.findSize() << '\n';
    cout << "Гурвалжингийн периметр: " << triangle.findPerimeter() << '\n';
    float *positions = triangle.getPosition();
    cout << "Тэнхлэг: " << '\n';
    for (int i = 0; i < 6; i += 2)
        cout << positions[i] << ' ' << positions[i + 1] << '\n';
}