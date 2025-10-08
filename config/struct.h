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

/*
 * Path Struct
 */

typedef enum
{
    M,
    L,
    H,
    V,
    Z,
    C,
    Q,
    S,
    T,
    A,

} PathOrder;

typedef struct
{
    int x,y;
    PathOrder order;

} Path;

typedef struct ListNodePath
{
    Path *path;
    struct ListNodePath *next;
    struct ListNodePath *previous;

} ListNodePath;

typedef struct ListPath
{
    ListNodePath *list;
    int lenght;

} ListPath;

/*
 * Polygon Struct
 */

typedef struct
{
    int x;
    int y;

} Polygone;

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

/*
 * Main Struct
 */

typedef union main
{
    Rectangle rect;
    Circle circle;
    Line line;
    Square squ;
    Ellipse elli;
    ListPoly *poly;
    ListPath *path;


} Shape;

typedef struct {
    ShapeType type;
    Shape *shape;
}Data;

/*
 * Group type form
 */
typedef struct
{
    Data *form;
} Group;


/*
 * List ongoing create shape in order
 */
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
