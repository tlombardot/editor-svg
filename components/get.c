
#include "../config/struct.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void getRectangle(Data *rectangle) {
  printf("/+--| Rectangle |--+/\n");
  printf("Position (x : %d, y : %d)\n", rectangle->shape->rect.x,
         rectangle->shape->rect.y);
  printf("Width : %d \n", rectangle->shape->rect.width);
  printf("Height : %d \n", rectangle->shape->rect.height);
}

void getSquare(Data *square) {
  printf("/+--| Square |--+/\n");
  printf("Position (x : %d, y : %d)\n", square->shape->squ.x,
         square->shape->squ.y);
  printf("Weight & Height : %d \n", square->shape->squ.wh);
}

void getEllipse(Data *ellipse) {
  printf("/+--| Ellipse |--+/\n");
  printf("Position (x : %d, y : %d)\n", ellipse->shape->elli.cx,
         ellipse->shape->elli.cy);
  printf("Rayon : %d (x) & Rayon : %d (y)\n", ellipse->shape->elli.rx,
         ellipse->shape->elli.ry);
}
/*
 * Get value of Circle
 */

void getCircle(Data *circle) {
  printf("/+--| Circle |--+/\n");
  printf("Position (x : %d, y : %d)\n", circle->shape->circle.cx,
         circle->shape->circle.cy);
  printf("Rayon : %d \n", circle->shape->circle.r);
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
int getInt(void) {
  int variable;
  bool isFinish = false;
  while (isFinish != true) {
    scanf("%d", &variable);
    if (variable >= 1) {
      isFinish = true;
    } else {
      printf("Valeur Inconnu ! \nRecommencez !\n");
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
