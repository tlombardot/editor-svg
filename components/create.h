#ifndef CREATE_H
#define CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"

Data *createRectangle();
void freeRectangle(Data *rectangle);
Data *createCircle();
void freeCicle(Data *circle);
Data *createEllipse();
void freeEllipse(Data *ellipse);
Data *createSquare();
void freeSquare(Data *square);
Data *createLine();
void freeLine(Data *line);
Data *createShapeless();
Data *createPath();
Data *createGroup();

#endif
