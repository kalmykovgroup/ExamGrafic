#pragma once   
#include "Header.h"   
#include "Player.h"   
#include "Matrix.h"   

class Bot : public Player
{
private:


    int** matrix; //��������� �� ������� ����
    double** pointMatrix; //�������� ���� ��� ����
    int width;
    int height;

    std::vector<Coordinate*> Destination�oordinates; //��������� ������� ����� ��������� ������� ��� ��������
    int idxProgress; //�������� ������������ ������� ����������

    PlayerNumber playerNumber;

public:

    Bot(Matrix* matrix1, PlayerNumber playerNumber);

    void iniPointMatrix();

    virtual int getLabel() {
        return int(playerNumber);
    }


    virtual bool move(std::vector<Coordinate*>& path);

    void clearPath(std::vector<Coordinate*>& path);

    bool singleStroke(int x, int y, std::vector<Coordinate*>& path, int endMove = 0, bool dc = false);

    void findingAWayForBot(std::vector<Coordinate*>& path);

    inline Coordinate getDirection() { return *this->Destination�oordinates[this->idxProgress]; }

    double distancePoints(Coordinate a, Coordinate b);

    bool Looping�heck(std::vector<Coordinate*>& path, int x, int y);

    double calculateUtilityFactor(Coordinate start, Coordinate current, Coordinate finish);

    void findingAWayForBot(std::vector<Coordinate*>& currentPath, std::vector<Coordinate*>& savedPath, double& savedUtilityFactor);

    void showPointMatrix();

    //���� ��� ���������� ������� ��� ����� �� ����� �����
    bool CheckingForProhibition(Coordinate c);

    virtual bool isWin();
    void IncreaseProgress(std::vector<Coordinate*>& path);

    const std::type_info& GetValueType() {
        return typeid(Bot);
    }

};

