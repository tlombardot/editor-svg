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
    ShapeType type;

}Rectangle;

typedef struct
{
    int cx, cy, r;
    ShapeType type;
}Circle;

typedef struct
{
    int x1, y1, x2, y2;
    ShapeType type;
}Line;

typedef struct 
{
    int x, y, wh;
    ShapeType type;
}Square;

typedef struct 
{
    int cx, cy, rx, ry;
    ShapeType type;
}Ellipse;

typedef struct 
{

    ShapeType type;
}Polygone;

typedef struct 
{
    ShapeType type;
}Ways;

typedef struct 
{
    ShapeType type;
}Group;

typedef struct 
{
    ShapeType type;
}Str_line;




typedef 
    union main
    {
        Rectangle rect;
        Circle circle;
        Line line;
        Square squ;
        Ellipse elli;
        Polygone poly;
        Str_line strline;
        Group grp;
        Ways ways;
        
    }Shape;