#pragma once 
#include "Header.h" 
#include "Player.h" 
#include "Matrix.h"  

class User : public Player
{

private:
    PlayerNumber playerNumber;
    int** matrix;
    int width;
    int height;

    std::vector<Coordinate*> DestinationÑoordinates; //Êîðäèíàòû êîòîðûå íóæíî çàïîëíèòü ôèøêàìè äëÿ âûéãðûøà


public:

    User(Matrix* matrix, PlayerNumber playerNumber);

    virtual int getLabel() { return (int)this->playerNumber; }

    void getData(Coordinate* c, int flag = false);

    virtual bool move(std::vector<Coordinate*>& path);
  
    bool checkingMove(int label, std::vector<Coordinate*>& path, Coordinate* finish);
    bool findingAWay(std::vector<Coordinate*>& path, Coordinate* finish);
    bool findingAWay(std::vector<Coordinate*>& path, Coordinate* finish, Coordinate* newPlace);
    virtual bool isWin();

    const std::type_info& GetValueType() {
        return typeid(User);
    }
};
