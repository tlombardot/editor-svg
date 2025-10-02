#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{
    CIRCLE,
    RECTANGLE,
    ELLIPSE,
    SQUARE,
    LINE,
    POLYGONE,

}ShapeType;


typedef struct
{
    int x, y, width, height;

}Rectangle;

typedef struct
{
    int cx, cy, r;
}Circle;

typedef struct
{
    int x1, y1, x2, y2;
}Line;

typedef struct 
{
    int x, y, wh;
}Square;

typedef struct 
{
    
}Ellipse;

typedef struct 
{
    
}Polygone;

typedef struct 
{
    union
    {
        Rectangle rect;
        Circle circle;
        Line line;
        Square square;
        Ellipse elli;
        Polygone poly;
    }data;
    
}Shape;


void initShape(Shape *shape,ShapeType type){
    switch (type)
    {
    case RECTANGLE:
        /* code */
        break;
    case CIRCLE:
        /* code */
        break;
    case LINE:
        /* code */
        break;
    case ELLIPSE:
        /* code */
        break;
    case SQUARE:
        /* code */
        break;
    case POLYGONE:
        /* code */
        break;
    default:
        break;
    }
}







int main (void){
}
