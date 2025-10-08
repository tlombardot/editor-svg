
#include "../components/get.h"
#include "../config/struct.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../config/set.h"

Data *createRectangle() {
  Data *new_rectangle = setMalloc();
  new_rectangle->shape->rect.x = getXCoord();
  new_rectangle->shape->rect.y = getYCoord();
  new_rectangle->shape->rect.width = getWIDTHCoord();
  new_rectangle->shape->rect.height = getHEIGHTCoord();
  new_rectangle->type = RECTANGLE;
  return new_rectangle;
}

void freeRectangle(Data *rectangle) { free(rectangle); }

Data *createCircle() {
  Data *new_circle = setMalloc();
  new_circle->shape->circle.cx = getXCoord();
  new_circle->shape->circle.cx = getYCoord();
  new_circle->shape->circle.r = getRange();
  new_circle->type = CIRCLE;
  return new_circle;
}

void freeCicle(Data *circle) { free(circle); }

Data *createEllipse() {
  Data *new_ellipse = setMalloc();
  new_ellipse->shape->elli.cx = getXCoord();
  new_ellipse->shape->elli.cy = getYCoord();
  new_ellipse->shape->elli.rx = getRange();
  new_ellipse->shape->elli.ry = getRange();
  new_ellipse->type = ELLIPSE;
  return new_ellipse;
}

void freeEllipse(Data *ellipse) { free(ellipse); }

Data *createSquare() {
  Data *new_square = setMalloc();
  new_square->shape->squ.x = getXCoord();
  new_square->shape->squ.y = getYCoord();
  new_square->shape->squ.wh = getWIDTHCoord();
  new_square->type = SQUARE;
  return new_square;
}

void freeSquare(Data *square) { free(square); }

Data *createLine() {
  Data *new_line = setMalloc();
  new_line->shape->line.x1 = getXCoord();
  new_line->shape->line.y1 = getYCoord();
  new_line->shape->line.x2 = getXCoord();
  new_line->shape->line.y2 = getYCoord();
  new_line->type = LINE;
  return new_line;
}

void freeLine(Data *line) { free(line); }

Polygone *createPolygon() {
  Polygone *poly = malloc(sizeof(Polygone));
  poly->x = getXCoord();
  poly->y = getYCoord();
  return poly;
}

Data *createShapeless(ShapeType type) {
  Data *new_poly = setMallocPoly();
  ListNodePoly *current = new_poly->shape->poly->list;
  bool isFinish = false;
  new_poly->shape->poly->list->value = createPolygon();
  new_poly->shape->poly->lenght++;
  while (isFinish != true) {
      isFinish = getBool();
      if (isFinish == true){
          break;
      }else {
      ListNodePoly *newNode = malloc(sizeof(ListNodePoly));
      newNode->value = createPolygon();
      newNode->next = NULL;
      newNode->previous = current;
      current->next = newNode;
      current = current->next;
      new_poly->shape->poly->lenght++;
      }
  }
  new_poly->type = type;
  return new_poly;
}

Data *createPath(){
    Data* new_path = malloc(sizeof(Data));
    return new_path;
}
