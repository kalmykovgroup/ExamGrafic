#include "Matrix.h"  
using namespace std;

Matrix::Matrix(int width, int height) : field{ new int* [height] }, width{ width }, height{ height } {
    for (int i = 0; i < height; i++) //Создаем матрицу
        field[i] = new int[width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->field[i][j] = 0;     //Инициализитруем ее
}

 

void Matrix::move(vector<Coordinate*>& path)
{
    int idxXStart = path[0]->x;
    int idxYStart = path[0]->y;
    
    int idxXEnd = path[path.size() - 1]->x;
    int idxYEnd = path[path.size() - 1]->y;

    int tmpNum = field[idxYStart][idxXStart];
      
    field[idxYStart][idxXStart] = 0;
    field[idxYEnd][idxXEnd] = tmpNum;
}

void Matrix::setFigures(int countFigures)
{
    int preWidth = 1, preHeight = 1;

    int width_ = 1, height_ = 1;

    int finalWidth, finalHeight;

    while (true) { //Находим оптимальное рассположение фигур
        if (width_ * height_ == countFigures || width_ * height_ > countFigures)
            break;
        else {
            preWidth = width_;
            preHeight = height_;
        }

        if (width_ == height_)
            width_++;
        else
            height_++;

    }

    int res1 = countFigures - preWidth * preHeight;
    int res2 = width_ * height_ - countFigures;
    if (res1 > res2) {
        finalWidth = width_;
        finalHeight = height_;
    }
    else {
        finalWidth = preWidth;
        finalHeight = preHeight;
    }
    int count = 0;
    int flag = false;
    for (int i = 0; i < height; i++) {
        if (flag) break;
        for (int j = 0; j < finalWidth; j++) {
            this->field[i][j] = PlayerNumber::One;
            if (++count == countFigures) { flag = true; break; }
        }
    }

    count = 0;
    flag = false;
    for (int i = height - 1; i != 0; i--) {
        if (flag) break;
        for (int j = 0; j < finalWidth; j++) {
            this->field[i][width - 1 - j] = PlayerNumber::Two;
            if (++count == countFigures) { flag = true; break; }
        }
    }


}


