#ifndef GET_H
#define GET_H
#include "../config/struct.h"
#include "stdbool.h"

void getRectangle(Data *rectangle);
void getSquare(Data *square);
void getEllipse(Data *ellipse);
void getCircle(Data *circle);
int getInt();
int getXCoord();
int getYCoord();
int getWIDTHCoord();
int getHEIGHTCoord();
int getRange();
void getShape(ListNodePoly *poly, ShapeType type);
char getChar();
bool getBool();

#endif
