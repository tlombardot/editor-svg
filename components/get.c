
#include "get.h"
#include "../config/struct.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void getRectangle(Data *rectangle, int index) {
  printf("/+--| Rectangle |--+/ --- %d ---\n", index);
  printf("Position (x : %d, y : %d)\n", rectangle->shape.rect.x,
         rectangle->shape.rect.y);
  printf("Width : %d \n", rectangle->shape.rect.width);
  printf("Height : %d \n", rectangle->shape.rect.height);
  printf("Fill : %d/%d/%d \n",rectangle->shape.rect.style.RF,rectangle->shape.rect.style.GF,rectangle->shape.rect.style.BF);
  printf("Stroke : %d/%d/%d \n",rectangle->shape.rect.style.RS,rectangle->shape.rect.style.GS,rectangle->shape.rect.style.BS);
  printf("Angle : %d \n",rectangle->shape.rect.style.angle);
}

void getSquare(Data *square, int index) {
  printf("/+--| Square |--+/ --- %d ---\n", index);
  printf("Position (x : %d, y : %d)\n", square->shape.squ.x,
         square->shape.squ.y);
  printf("Weight & Height : %d \n", square->shape.squ.wh);
  printf("Fill : %d/%d/%d \n",square->shape.squ.style.RF,square->shape.squ.style.GF,square->shape.squ.style.BF);
  printf("Stroke : %d/%d/%d \n",square->shape.squ.style.RS,square->shape.squ.style.GS,square->shape.squ.style.BS);
  printf("Angle : %d \n",square->shape.squ.style.angle);
}

void getEllipse(Data *ellipse, int index) {
  printf("/+--| Ellipse |--+/ --- %d ---\n", index);
  printf("Position (x : %d, y : %d)\n", ellipse->shape.elli.cx,
         ellipse->shape.elli.cy);
  printf("Rayon : %d (x) & Rayon : %d (y)\n", ellipse->shape.elli.rx,
         ellipse->shape.elli.ry);
  printf("Fill : %d/%d/%d \n",ellipse->shape.elli.style.RF,ellipse->shape.elli.style.GF,ellipse->shape.elli.style.BF);
  printf("Stroke : %d/%d/%d \n",ellipse->shape.elli.style.RS,ellipse->shape.elli.style.GS,ellipse->shape.elli.style.BS);
  printf("Angle : %d \n",ellipse->shape.elli.style.angle);
}
/*
 * Get value of Circle
 */

void getCircle(Data *circle, int index) {
  printf("/+--| Circle |--+/ --- %d ---\n", index);
  printf("Position (x : %d, y : %d)\n", circle->shape.circle.cx,
         circle->shape.circle.cy);
  printf("Rayon : %d \n", circle->shape.circle.r);
  printf("Fill : %d/%d/%d \n",circle->shape.circle.style.RF,circle->shape.circle.style.GF,circle->shape.circle.style.BF);
  printf("Stroke : %d/%d/%d \n",circle->shape.circle.style.RS,circle->shape.circle.style.GS,circle->shape.circle.style.BS);
  printf("Angle : %d \n",circle->shape.circle.style.angle);
}

void getLine(Data *line, int index) {
  printf("/+--| Line |--+/ --- %d ---\n", index);
  printf("Position (x1 : %d, y1 : %d)\n", line->shape.line.x1,
         line->shape.line.y1);
  printf("Position (x2 : %d, y2 : %d)\n", line->shape.line.x2,
         line->shape.line.y2);
  printf("Fill : %d/%d/%d \n",line->shape.line.style.RF,line->shape.line.style.GF,line->shape.line.style.BF);
  printf("Stroke : %d/%d/%d \n",line->shape.line.style.RS,line->shape.line.style.GS,line->shape.line.style.BS);
  printf("Angle : %d \n",line->shape.line.style.angle);
}

/*
 * Get value of Polygon or Polyline
 */

void getShape(ListNodePoly *poly, ShapeType type){
    switch (type) {
        case POLYGONE:
                printf("/+--| Polygon |--+/\n");
            break;
        case STRLINE :
            printf("/+--| Polyline |--+\n");
        default:
            break;
    }
    ListNodePoly *current = poly;
    while (current != NULL){
        printf("Position (x : %d, y : %d)\n", current->value->x, current->value->y);
        current = current->next;
    }
}

void getPath(ListNodePath *path){
    printf("/+--| Path |--+\n");
    ListNodePath *current = path;
    printf("Order : ");
    while (current != NULL){
        switch (current->path->orderType) {
            case 'M':
                printf(" %c %d %d ", current->path->orderType, current->path->order.mv.x, current->path->order.mv.y);
                break;
            case 'L':
                printf(" %c %d %d ", current->path->orderType, current->path->order.lp.x, current->path->order.lp.y);
                break;
            case 'H':
                printf(" %c %d ", current->path->orderType, current->path->order.h.x);
                break;
            case 'V':
                printf(" %c %d  ", current->path->orderType, current->path->order.v.y);
                break;
            case 'C':
                printf(" %c ", current->path->orderType);
                printf(" %d %d ",  current->path->order.c.x1, current->path->order.c.y1);
                printf(" %d %d ",  current->path->order.c.x2, current->path->order.c.y2);
                printf(" %d %d ",  current->path->order.c.x3, current->path->order.c.y3);
                break;
            case 'S':
                printf(" %c ", current->path->orderType);
                printf(" %d %d ",  current->path->order.sc.x1, current->path->order.sc.y1);
                printf(" %d %d ",  current->path->order.sc.x2, current->path->order.sc.y2);
                break;
            case 'Q':
                printf(" %c ", current->path->orderType);
                printf(" %d %d ",  current->path->order.qc.x1, current->path->order.qc.y1);
                printf(" %d %d ",  current->path->order.qc.x2, current->path->order.qc.y2);
                break;
            case 'T':
                printf(" %c ", current->path->orderType);
                printf(" %d %d ",  current->path->order.sq.x, current->path->order.sq.y);
                break;
            default:
                break;
        }
        current = current->next;
    }
    printf("\n");
}
int getInt(void) {
  int variable;
  bool isFinish = false;
  while (isFinish != true) {
    scanf("%d", &variable);
    if ((variable >= 0) && (variable <= 200)) {
      isFinish = true;
    } else {
      printf("Value Unknow ! \nRetry !\n");
    }
  }
  return variable;
}

int getXCoord() {
  int variable;
  printf("What is your x coordinates ?\n");
  variable = getInt();
  return variable;
}
int getYCoord() {
  int variable;
  printf("What is your y coordinates ?\n");
  variable = getInt();
  return variable;
}
int getWIDTHCoord() {
  int variable;
  printf("What is your width ?\n");
  variable = getInt();
  return variable;
}
int getHEIGHTCoord() {
  int variable;
  printf("What is your height ?\n");
  variable = getInt();
  return variable;
}
int getRange() {
  int variable;
  printf("What is your range ?\n");
  variable = getInt();
  return variable;
}

char getChar(){
    char var;
    scanf(" %c",&var );
    return var;
}

bool getBool(){
    char answer;
    bool var = false;
    while (var != true) {
        printf("Do you want to continue ? y or n ?\n");
        answer = getChar();
        if (answer == 'y' || answer =='Y') {
            var = true;
            return false;
        }else if (answer == 'n' || answer == 'N') {
            var = true;
            return true;
        }else {
            printf("Mauvaise valeur !\n");
            var = false;
        }
    }
    return var;
}
