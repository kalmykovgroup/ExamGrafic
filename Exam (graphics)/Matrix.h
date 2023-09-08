#pragma once  

#include "Header.h" 
#include "Coordinate.h"   

class Matrix {

private:

    int** field;  //������� ����

    int width;  //������� ����
    int height;

public:

    Matrix(int width, int height);

    int getWidth() { return this->width; }
    int getHeight() { return this->height; }
    int** getArray() { return this->field; }

    void move(std::vector<Coordinate*>& path);

    void setFigures(int countFigures);
};