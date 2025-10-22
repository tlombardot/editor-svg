#ifndef CREATE_H
#define CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"

/**
 * @brief Creates a new rectangle shape.
 *
 * @return Pointer to a newly allocated Data structure representing the rectangle.
 *
 * @details Initializes the rectangle’s coordinates, dimensions, and style attributes
 * (fill, stroke, angle, translation). The shape type is set to RECTANGLE.
 */
Data *createRectangle(void);

/**
 * @brief Frees the memory allocated for a rectangle shape.
 *
 * @param rectangle Pointer to the rectangle Data structure to free.
 */
void freeRectangle(Data *rectangle);

/**
 * @brief Creates a new circle shape.
 *
 * @return Pointer to a newly allocated Data structure representing the circle.
 *
 * @details Prompts for the circle’s center coordinates and radius.
 * Initializes style attributes (fill, stroke, angle, translation).
 * The shape type is set to CIRCLE.
 */
Data *createCircle(void);

/**
 * @brief Frees the memory allocated for a circle shape.
 *
 * @param circle Pointer to the circle Data structure to free.
 */
void freeCircle(Data *circle);

/**
 * @brief Creates a new ellipse shape.
 *
 * @return Pointer to a newly allocated Data structure representing the ellipse.
 *
 * @details Initializes the ellipse’s center coordinates and radii,
 * as well as style attributes (fill, stroke, angle, translation).
 * The shape type is set to ELLIPSE.
 */
Data *createEllipse(void);

/**
 * @brief Frees the memory allocated for an ellipse shape.
 *
 * @param ellipse Pointer to the ellipse Data structure to free.
 */
void freeEllipse(Data *ellipse);

/**
 * @brief Creates a new square shape.
 *
 * @return Pointer to a newly allocated Data structure representing the square.
 *
 * @details Initializes the square’s coordinates and width/height,
 * along with style attributes (fill, stroke, angle, translation).
 * The shape type is set to SQUARE.
 */
Data *createSquare(void);

/**
 * @brief Frees the memory allocated for a square shape.
 *
 * @param square Pointer to the square Data structure to free.
 */
void freeSquare(Data *square);

/**
 * @brief Creates a new line shape.
 *
 * @return Pointer to a newly allocated Data structure representing the line.
 *
 * @details Initializes the line’s start and end coordinates,
 * and sets its stroke, angle, and translation style attributes.
 * The shape type is set to LINE.
 */
Data *createLine(void);

/**
 * @brief Frees the memory allocated for a line shape.
 *
 * @param line Pointer to the line Data structure to free.
 */
void freeLine(Data *line);

/**
 * @brief Creates a new polygon vertex.
 *
 * @return Pointer to a newly allocated Polygone structure containing X and Y coordinates.
 *
 * @details Represents a single point in a polygon or polyline structure.
 */
Polygone *createPolygon(void);

/**
 * @brief Creates a new polygon or polyline shape.
 *
 * @param type The shape type, either POLYGONE or STRLINE.
 * @return Pointer to a newly allocated Data structure representing the shape.
 *
 * @details Interactively builds a list of polygon points.
 * Initializes style attributes (stroke, fill, angle, translation).
 * The shape type is set according to the given parameter.
 */
Data *createShapeless(ShapeType type);

/**
 * @brief Frees the memory allocated for a polygon or polyline shape.
 *
 * @param shapeless Pointer to the Data structure representing the shape to free.
 *
 * @details Frees each vertex in the polygon list, then releases the shape itself.
 */
void freeShapeless(Data *shapeless);

/**
 * @brief Creates a new SVG path shape.
 *
 * @return Pointer to a newly allocated Data structure representing the path.
 *
 * @details Initializes the starting “move to” command (M) with coordinates,
 * sets default styles (stroke, fill, angle, translation),
 * and initializes the linked list for subsequent path commands.
 */
Data *createPath(void);

/**
 * @brief Frees the memory allocated for a path shape.
 *
 * @param path Pointer to the Data structure representing the path to free.
 *
 * @details Frees each node in the path’s linked list and then releases the shape.
 */
void freePath(Data *path);

/**
 * @brief Creates a new SVG group container.
 *
 * @return Pointer to a newly allocated Data structure representing the group.
 *
 * @details Initializes an empty group with depth set to zero.
 * The shape type is set to GROUP.
 */
Data *createGroup(void);


#endif
