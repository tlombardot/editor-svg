#ifndef GET_H
#define GET_H
#include "../config/struct.h"
#include "stdbool.h"

void getRectangle(Data *rectangle, int index);
void getSquare(Data *square, int index);
void getEllipse(Data *ellipse, int index);
void getCircle(Data *circle, int index);
int getInt(int min, int max);
int getXCoord();
int getYCoord();
int getWIDTHCoord();
int getHEIGHTCoord();
int getRange();
void getShape(ListNodePoly *poly, ShapeType type, int index);
void getPath(ListNodePath *path, int index);
char getChar();
bool getBool();
void getLine(Data *line, int index);
char *getString();
void getGroup(Group *group);

#endif
