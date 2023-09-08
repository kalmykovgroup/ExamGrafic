#pragma once 
#include "Header.h"

class Player
{

public:

	virtual int getLabel() = 0;
	virtual bool move(std::vector<Coordinate*>& path) = 0;
	virtual bool isWin() = 0; 
	virtual const std::type_info& GetValueType() = 0;
};