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
    GROUP,
    WAYS,
    STRLINE,

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

}Ways;

typedef struct 
{

}Group;

typedef struct 
{

}Str_line;




typedef struct 
{
    union main
    {
        Rectangle rect;
        Circle cirlce;
        Line line;
        Square squ;
        Ellipse elli;
        Polygone poly;
        Str_line strline;
        Group grp;
        Ways ways;
        
    }data;
    
    

}Shape;



Shape* initShape(ShapeType type){
    Shape *shape = malloc(sizeof(Shape));
    switch (type)
    {
    case RECTANGLE: {
        int x,y,width,height;
        printf("What is your x coordinates ? (TOP LEFT)\n");
        scanf("%d",&x);
        shape->data.rect.x = x;
        printf("What is your y coordinates ? (TOP LEFT)\n");
        scanf("%d",&y);
        shape->data.rect.y = y;
        printf("What is your width (RIGHT)? (NEGATIVE OPPOSITE WAYS)\n");
        scanf("%d",&width);
        shape->data.rect.width = width;
        printf("What is your height (DOWN)? (NEGATIVE OPPOSITE WAYS)\n");
        scanf("%d",&height);
        shape->data.rect.height = height;
        return shape;
        break;
    }
    case CIRCLE: {
        return NULL;
        break;
    }
    case LINE: {
        return NULL;
        break;
    }
    case ELLIPSE: {
        return NULL;
        break;
    }
    case SQUARE: {
        return NULL;
        break;
    }
    case POLYGONE: {
        return NULL;
        break;
    }
    case GROUP: {
        return NULL;
        break;
    }
    case WAYS: {
        return NULL;
        break;
    }
    case STRLINE: {
        return NULL;
        break;
    }
    default: {
        return NULL;
        break;
    }
    
    }
}

void getCoord(Shape* shape, ShapeType type){
    switch (type)
    {
    case RECTANGLE: {
        printf("/+--| Rectangle |--+/\n");
        printf("Position (x,y) : %d,%d \n",shape->data.rect.x,shape->data.rect.y);
        printf("Width : %d \n",shape->data.rect.width);
        printf("Height : %d \n",shape->data.rect.height);
        break;
    }
    case CIRCLE: {
        break;
    }
    case LINE: {
        break;
    }
    case ELLIPSE: {
        break;
    }
    case SQUARE: {
        break;
    }
    case POLYGONE: {
        break;
    }
    case GROUP: {
        break;
    }
    case WAYS: {
        break;
    }
    case STRLINE: {
        break;
    }
    default: {
        break;
    }
    }
}


int main(void){
    Shape *shape;
    shape = initShape(RECTANGLE);
    getCoord(shape,RECTANGLE);
    return EXIT_SUCCESS;
}


