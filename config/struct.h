#ifndef STRUCT_H
#define STRUCT_H

typedef enum
{
    CIRCLE,
    RECTANGLE,
    ELLIPSE,
    SQUARE,
    LINE,
    POLYGONE,
    GROUP,
    PATH,
    STRLINE,

} ShapeType;

typedef struct
{
    int x, y, width, height;

} Rectangle;

typedef struct
{
    int cx, cy;
    unsigned int r;

} Circle;

typedef struct
{
    int x1, y1, x2, y2;

} Line;

typedef struct
{
    int x, y, wh;

} Square;

typedef struct
{
    int cx, cy, rx, ry;

} Ellipse;

typedef struct
{
    int x;
    int y;

} Polygone;

typedef struct
{

} Path;

typedef struct
{

} Group;

typedef struct
{

} Str_line;

typedef struct ListNodePoly
{
    Polygone *value;
    struct ListNodePoly *next;
    struct ListNodePoly *previous;
}ListNodePoly;

typedef struct ListPoly
{
    ListNodePoly *list;
    int lenght;
}ListPoly;

typedef union main
{
    Rectangle rect;
    Circle circle;
    Line line;
    Square squ;
    Ellipse elli;
    ListPoly *poly;
    Str_line strline;
    Group grp;
    Path path;


} Shape;

typedef struct {
    ShapeType type;
    Shape *shape;
}Data;


typedef struct ListNode
{
    Data *data;
    struct ListNode *next;
    struct ListNode *previous;


} ListNode;

typedef struct
{
    ListNode *form;
    int lenght;

} List;


#endif
