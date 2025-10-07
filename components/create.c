

#ifndef CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"

#endif
#ifndef CREATE_C
#define CREATE_C
Shape *createRectangle()
{
    Shape *new_rectangle = malloc(sizeof(Shape));
    printf("What is your x coordinates ? (TOP LEFT)\n");
    scanf("%d", &new_rectangle->rect.x);
    printf("What is your y coordinates ? (TOP LEFT)\n");
    scanf("%d", &new_rectangle->rect.y);
    printf("What is your width (RIGHT)? (NEGATIVE OPPOSITE WAYS)\n");
    scanf("%d", &new_rectangle->rect.width);
    printf("What is your height (DOWN)? (NEGATIVE OPPOSITE WAYS)\n");
    scanf("%d", &new_rectangle->rect.height);
    new_rectangle->type = RECTANGLE;
    return new_rectangle;
}

void freeRectangle(Shape *rectangle)
{
    free(rectangle);
}

Shape *createCircle()
{
    Shape *new_circle = malloc(sizeof(Shape));
    printf("What is your x coordinates ? (CENTER)\n");
    scanf("%d", &new_circle->circle.cx);
    printf("What is your y coordinates ? (CENTER)\n");
    scanf("%d", &new_circle->circle.cy);
    printf("What is your range ?\n");
    scanf("%d", &new_circle->circle.r);
    new_circle->type = CIRCLE;
    return new_circle;
}

void freeCicle(Shape *circle)
{
    free(circle);
}

Shape *createEllipse()
{
    Shape *new_ellipse = malloc(sizeof(Shape));
    printf("What is your x coordinates ? (CENTER)\n");
    scanf("%d", &new_ellipse->elli.cx);
    printf("What is your y coordinates ? (CENTER)\n");
    scanf("%d", &new_ellipse->elli.cy);
    printf("What is your range ?\n");
    scanf("%d", &new_ellipse->elli.rx);
    new_ellipse->type = ELLIPSE;
    return new_ellipse;
}

void freeEllipse(Shape *ellipse)
{
    free(ellipse);
}

Shape *createSquare()
{
    Shape *new_square = malloc(sizeof(Shape));
    printf("What is your x coordinates ?\n");
    scanf("%d", &new_square->squ.x);
    printf("What is your y coordinates ?\n");
    scanf("%d", &new_square->squ.y);
    printf("What is your width ?\n");
    scanf("%d", &new_square->squ.wh);
    new_square->type = SQUARE;
    return new_square;
}

void freeSquare(Shape *square)
{
    free(square);
}

Shape *createLine()
{
    Shape *new_line = malloc(sizeof(Shape));
    printf("What is your x1 coordinate ?\n");
    scanf("%d", &new_line->line.x1);
    printf("What is your y1 coordinate ?\n");
    scanf("%d", &new_line->line.y1);
    printf("What is your x2 coordinate ?\n");
    scanf("%d", &new_line->line.x2);
    printf("What is your y2 coordinate ?\n");
    scanf("%d", &new_line->line.y2);
    new_line->type= LINE;
    return new_line;
}

void freeLine(Shape *line)
{
    free(line);
}
#endif
