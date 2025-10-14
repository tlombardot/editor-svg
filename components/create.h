#ifndef CREATE_H
#define CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"

Data *createRectangle();
void freeRectangle(Data *rectangle);
Data *createCircle();
void freeCircle(Data *circle);
Data *createEllipse();
void freeEllipse(Data *ellipse);
Data *createSquare();
void freeSquare(Data *square);
Data *createLine();
void freeLine(Data *line);
Data *createShapeless();
void freeShapeless(Data *shapeless);
Data *createPath();
void freePath(Data *path);
Data *createGroup();

#endif
