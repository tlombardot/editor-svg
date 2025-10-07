#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"

Shape *createRectangle();
void freeRectangle(Shape *rectangle);
Shape *createCircle();
void freeCicle(Shape *circle);
Shape *createEllipse();
void freeEllipse(Shape *ellipse);
Shape *createSquare();
void freeSquare(Shape *square);
Shape *createLine();
void freeLine(Shape *line);
