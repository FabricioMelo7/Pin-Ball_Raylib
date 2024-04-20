#pragma once
#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <raylib.h>

class GameTable
{
public:
	GameTable();
	~GameTable();
	void Draw();

private:
    Model tableModel;         
    Vector3 tablePosition;    

    Model borderFrontModel;   
    Model borderBackModel;
    Model borderLeftModel;
    Model borderRightModel;

    Mesh bumperMesh[3];       
    Model bumperModel[3];     
    Vector3 bumperPosition[3];

    void initTable();         
    void initBumpers();       

};

#endif // GAMETABLE_H

