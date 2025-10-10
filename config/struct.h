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

 typedef struct Move{
     int x,y;
 } Move;

 typedef struct LinePath{
     int x,y;
 } LinePath;

 typedef struct Horizontal{
     int x;
 } Horizontal;

 typedef struct Vertical{
     int y;
 } Vertical;

 typedef struct Curve{
     int x1, y1, x2, y2, x3, y3;

 } Curve;

 typedef struct ShortCurve{
     int x1, y1, x2, y2;

 } ShortCurve;

 typedef struct QuadraticCurve {
     int x1, y1, x2, y2;

 } QuadraticCurve;

 typedef struct ShortQuadratic{
     int x,y;

 } ShortQuadratic;


typedef union Order
{
    Move mv;
    LinePath lp;
    Horizontal h;
    Vertical v;
    Curve c;
    ShortCurve sc;
    QuadraticCurve qc;
    ShortQuadratic sq;

} Order;

typedef struct Path{
    Order order;
    char orderType;
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

typedef union Shape
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
    Shape shape;
}Data;

/*
 * Group type form
 */
typedef struct
{
    Data form;
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
