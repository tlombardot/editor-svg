
#include "../components/get.h"
#include "../config/struct.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../config/allocate.h"
#include "../config/style.h"

Data *createRectangle() {
  Data *new_rectangle = allocateMemory();
  new_rectangle->shape.rect.x = getXCoord();
  new_rectangle->shape.rect.y = getYCoord();
  new_rectangle->shape.rect.width = getWIDTHCoord();
  new_rectangle->shape.rect.height = getHEIGHTCoord();
  new_rectangle->shape.rect.style = createFillStyle(&new_rectangle->shape.rect.style);
  new_rectangle->shape.rect.style = createStrokeStyle(&new_rectangle->shape.rect.style);
  new_rectangle->shape.rect.style = createAngleStyle(&new_rectangle->shape.rect.style);
  new_rectangle->shape.rect.style.translate = createTranslateStyle(&new_rectangle->shape.rect.style);
  new_rectangle->type = RECTANGLE;
  return new_rectangle;
}

void freeRectangle(Data *rectangle) { free(rectangle); }

Data *createCircle() {
  Data *new_circle = allocateMemory();
  new_circle->shape.circle.cx = getXCoord();
  new_circle->shape.circle.cy = getYCoord();
  new_circle->shape.circle.r = getRange();
  new_circle->shape.circle.style = createFillStyle(&new_circle->shape.circle.style);
  new_circle->shape.circle.style = createStrokeStyle(&new_circle->shape.circle.style);
  new_circle->shape.circle.style = createAngleStyle(&new_circle->shape.circle.style);
  new_circle->shape.circle.style.translate = createTranslateStyle(&new_circle->shape.circle.style);
  new_circle->type = CIRCLE;
  return new_circle;
}

void freeCircle(Data *circle) { free(circle); }

Data *createEllipse() {
  Data *new_ellipse = allocateMemory();
  new_ellipse->shape.elli.cx = getXCoord();
  new_ellipse->shape.elli.cy = getYCoord();
  new_ellipse->shape.elli.rx = getRange();
  new_ellipse->shape.elli.ry = getRange();
  new_ellipse->shape.elli.style = createFillStyle(&new_ellipse->shape.elli.style);
  new_ellipse->shape.elli.style = createStrokeStyle(&new_ellipse->shape.elli.style);
  new_ellipse->shape.elli.style = createAngleStyle(&new_ellipse->shape.elli.style);
  new_ellipse->shape.elli.style.translate = createTranslateStyle(&new_ellipse->shape.elli.style);
  new_ellipse->type = ELLIPSE;
  return new_ellipse;
}

void freeEllipse(Data *ellipse) { free(ellipse); }

Data *createSquare() {
  Data *new_square = allocateMemory();
  new_square->shape.squ.x = getXCoord();
  new_square->shape.squ.y = getYCoord();
  new_square->shape.squ.wh = getWIDTHCoord();
  new_square->shape.squ.style = createFillStyle(&new_square->shape.squ.style);
  new_square->shape.squ.style = createStrokeStyle(&new_square->shape.squ.style);
  new_square->shape.squ.style = createAngleStyle(&new_square->shape.squ.style);
  new_square->shape.squ.style.translate = createTranslateStyle(&new_square->shape.squ.style);
  new_square->type = SQUARE;
  return new_square;
}

void freeSquare(Data *square) { free(square); }

Data *createLine() {
  Data *new_line = allocateMemory();
  new_line->shape.line.x1 = getXCoord();
  new_line->shape.line.y1 = getYCoord();
  new_line->shape.line.x2 = getXCoord();
  new_line->shape.line.y2 = getYCoord();
  new_line->shape.line.style = createStrokeStyle(&new_line->shape.line.style);
  new_line->shape.line.style = createAngleStyle(&new_line->shape.line.style);
  new_line->shape.line.style.translate = createTranslateStyle(&new_line->shape.line.style);
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
  Data *new_poly = allocateMemoryPoly();
  new_poly->shape.poly->lenght = 0;
  ListNodePoly *current = new_poly->shape.poly->list;
  bool isFinish = false;
  new_poly->shape.poly->list->value = createPolygon();
  new_poly->shape.poly->lenght++;
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
      new_poly->shape.poly->lenght++;
      }
  }
    new_poly->shape.poly->style = createStrokeStyle(&new_poly->shape.poly->style);
    new_poly->shape.poly->style = createFillStyle(&new_poly->shape.poly->style);
    new_poly->shape.poly->style = createAngleStyle(&new_poly->shape.poly->style);
    new_poly->shape.poly->style.translate = createTranslateStyle(&new_poly->shape.poly->style);
  new_poly->type = type;
  return new_poly;
}

void freeShapeless(Data *shapeless) {
    ListNodePoly *current = shapeless->shape.poly->list;
    while (current != NULL) {
        ListNodePoly *next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(shapeless);
}

Data *createPath(){
    Data* new_path = allocateMemoryPath();
    new_path->shape.path->list->path->order.mv.x = getXCoord();
    new_path->shape.path->list->path->order.mv.y = getYCoord();
    new_path->shape.path->style = createStrokeStyle(&new_path->shape.path->style);
    new_path->shape.path->style = createFillStyle(&new_path->shape.path->style);
    new_path->shape.path->style = createAngleStyle(&new_path->shape.path->style);
    new_path->shape.path->style.translate = createTranslateStyle(&new_path->shape.path->style);
    new_path->shape.path->list->path->orderType = 'M';
    new_path->shape.path->lenght = 0;
    new_path->type = PATH;
    return new_path;
}
void freePath(Data *path) {
    ListNodePath *current = path->shape.path->list;
    ListNodePath *next;
    while (current != NULL) {
        next = current->next;
        free(current->path);
        free(current);
        current = next;
    }
    free(path);
}

Data *createGroup(){
    Data *new_group = allocateMemoryGroup();
    new_group->type = GROUP;
    new_group->shape.group->depth = 0;
    return new_group;
}
