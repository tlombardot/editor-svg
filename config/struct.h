#ifndef STRUCT_H
#define STRUCT_H

/**
 * @file struct.h
 * @brief Core data structures for SVG shape representation and management.
 *
 * This header defines all data types used throughout the SVG editing system,
 * including geometric primitives, styling options, shape containers,
 * lists, and grouping mechanisms.
 */

/* -------------------------------------------------------------------------- */
/*                                 ENUM TYPES                                 */
/* -------------------------------------------------------------------------- */

/**
 * @brief Enumeration of all supported SVG shape types.
 */
typedef enum
{
    CIRCLE,     /**< Circle shape */
    RECTANGLE,  /**< Rectangle shape */
    ELLIPSE,    /**< Ellipse shape */
    SQUARE,     /**< Square shape */
    LINE,       /**< Line shape */
    POLYGONE,   /**< Polygon shape */
    GROUP,      /**< Group container */
    PATH,       /**< SVG Path shape */
    STRLINE     /**< Polyline shape */
} ShapeType;

/* -------------------------------------------------------------------------- */
/*                                STYLE STRUCTS                               */
/* -------------------------------------------------------------------------- */

/**
 * @brief Translation transformation for shapes.
 */
typedef struct Translate {
    int x;  /**< Horizontal translation */
    int y;  /**< Vertical translation */
} Translate;

/**
 * @brief Styling information for SVG shapes.
 *
 * Includes fill and stroke colors, rotation angle, and translation data.
 */
typedef struct Style {
    int RS, GS, BS;  /**< Stroke color (RGB) */
    int RF, GF, BF;  /**< Fill color (RGB) */
    int angle;       /**< Rotation angle in degrees */
    Translate translate; /**< Translation transformation */
} Style;

/* -------------------------------------------------------------------------- */
/*                                SHAPE TYPES                                 */
/* -------------------------------------------------------------------------- */

/**
 * @brief Rectangle shape data.
 */
typedef struct {
    int x, y;          /**< Top-left corner coordinates */
    int width, height; /**< Dimensions */
    Style style;       /**< Styling information */
} Rectangle;

/**
 * @brief Circle shape data.
 */
typedef struct {
    int cx, cy;        /**< Center coordinates */
    unsigned int r;    /**< Radius */
    Style style;       /**< Styling information */
} Circle;

/**
 * @brief Line shape data.
 */
typedef struct {
    int x1, y1;        /**< Start point coordinates */
    int x2, y2;        /**< End point coordinates */
    Style style;       /**< Styling information */
} Line;

/**
 * @brief Square shape data.
 */
typedef struct {
    int x, y;          /**< Top-left corner coordinates */
    int wh;            /**< Width and height (equal for square) */
    Style style;       /**< Styling information */
} Square;

/**
 * @brief Ellipse shape data.
 */
typedef struct {
    int cx, cy;        /**< Center coordinates */
    int rx, ry;        /**< Radii (horizontal and vertical) */
    Style style;       /**< Styling information */
} Ellipse;

/* -------------------------------------------------------------------------- */
/*                                  PATH DATA                                 */
/* -------------------------------------------------------------------------- */

/**
 * @brief Move command (M) for SVG path.
 */
typedef struct Move {
    int x, y;
} Move;

/**
 * @brief Line command (L) for SVG path.
 */
typedef struct LinePath {
    int x, y;
} LinePath;

/**
 * @brief Horizontal line command (H) for SVG path.
 */
typedef struct Horizontal {
    int x;
} Horizontal;

/**
 * @brief Vertical line command (V) for SVG path.
 */
typedef struct Vertical {
    int y;
} Vertical;

/**
 * @brief Cubic Bezier curve (C) for SVG path.
 */
typedef struct Curve {
    int x1, y1, x2, y2, x3, y3;
} Curve;

/**
 * @brief Smooth cubic Bezier curve (S) for SVG path.
 */
typedef struct ShortCurve {
    int x1, y1, x2, y2;
} ShortCurve;

/**
 * @brief Quadratic Bezier curve (Q) for SVG path.
 */
typedef struct QuadraticCurve {
    int x1, y1, x2, y2;
} QuadraticCurve;

/**
 * @brief Smooth quadratic Bezier curve (T) for SVG path.
 */
typedef struct ShortQuadratic {
    int x, y;
} ShortQuadratic;

/**
 * @brief Union representing a generic path command.
 */
typedef union Order {
    Move mv;
    LinePath lp;
    Horizontal h;
    Vertical v;
    Curve c;
    ShortCurve sc;
    QuadraticCurve qc;
    ShortQuadratic sq;
} Order;

/**
 * @brief Represents a single SVG path element (command and parameters).
 */
typedef struct Path {
    Order order;     /**< Command data */
    char orderType;  /**< Command letter (e.g., 'M', 'L', 'C', etc.) */
} Path;

/**
 * @brief Linked list node for path commands.
 */
typedef struct ListNodePath {
    Path *path;                  /**< Pointer to path command */
    struct ListNodePath *next;   /**< Next node in the list */
    struct ListNodePath *previous; /**< Previous node in the list */
} ListNodePath;

/**
 * @brief Linked list container for SVG path data.
 */
typedef struct ListPath {
    ListNodePath *list;  /**< Head of path node list */
    int lenght;          /**< Number of path commands */
    Style style;         /**< Path styling */
} ListPath;

/* -------------------------------------------------------------------------- */
/*                               POLYGON DATA                                 */
/* -------------------------------------------------------------------------- */

/**
 * @brief Polygon point coordinates.
 */
typedef struct {
    int x; /**< X coordinate */
    int y; /**< Y coordinate */
} Polygone;

/**
 * @brief Linked list node for polygon or polyline points.
 */
typedef struct ListNodePoly {
    Polygone *value;            /**< Pointer to polygon vertex */
    struct ListNodePoly *next;  /**< Next node */
    struct ListNodePoly *previous; /**< Previous node */
} ListNodePoly;

/**
 * @brief Linked list container for polygon or polyline data.
 */
typedef struct ListPoly {
    ListNodePoly *list;  /**< Head of polygon node list */
    int lenght;          /**< Number of points */
    Style style;         /**< Shape styling */
} ListPoly;

/* -------------------------------------------------------------------------- */
/*                               GROUPING DATA                                */
/* -------------------------------------------------------------------------- */

typedef struct Group Group;

/**
 * @brief Union representing any supported shape type.
 */
typedef union Shape {
    Rectangle rect;
    Circle circle;
    Line line;
    Square squ;
    Ellipse elli;
    ListPoly *poly;
    ListPath *path;
    Group *group;
} Shape;

/**
 * @brief Container for any SVG shape, including its type and data.
 */
typedef struct {
    ShapeType type; /**< Shape category */
    Shape shape;    /**< Shape data */
} Data;

/* -------------------------------------------------------------------------- */
/*                               LIST MANAGEMENT                              */
/* -------------------------------------------------------------------------- */

/**
 * @brief Node in the linked list of created shapes.
 */
typedef struct ListNode {
    Data *data;               /**< Pointer to shape data */
    struct ListNode *next;    /**< Next node in the list */
    struct ListNode *previous;/**< Previous node in the list */
} ListNode;

/**
 * @brief Linked list container for all shapes.
 */
typedef struct {
    ListNode *form; /**< Head of shape node list */
    int lenght;     /**< Number of shapes in the list */
} List;

/**
 * @brief Group container for nested shapes.
 */
struct Group {
    List *grouplist; /**< List of shapes inside the group */
    int depth;       /**< Nesting level of the group */
};

#endif /* STRUCT_H */
