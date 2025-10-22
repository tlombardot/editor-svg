

#include "struct.h"


/**
 * @brief Adds a "Move To" (M) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath (the last node in the path list).
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'M' (move to) SVG command.
 * Prompts the user for X and Y coordinates using getXCoord() and getYCoord().
 * Links the new node to the existing path.
 */
ListNodePath *movePath(ListNodePath *path);

/**
 * @brief Adds a "Line To" (L) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'L' (line to) SVG command.
 * Prompts the user for X and Y coordinates and appends the node to the list.
 */
ListNodePath *linePath(ListNodePath *path);

/**
 * @brief Adds a "Horizontal Line To" (H) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'H' command,
 * prompting the user for the new X coordinate only.
 */
ListNodePath *horizontalPath(ListNodePath *path);

/**
 * @brief Adds a "Vertical Line To" (V) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'V' command,
 * prompting the user for the new Y coordinate only.
 */
ListNodePath *verticalPath(ListNodePath *path);

/**
 * @brief Adds a "Cubic Bezier Curve" (C) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'C' command.
 * Prompts the user for three control points (x1,y1, x2,y2, x3,y3)
 * defining the cubic Bezier curve.
 */
ListNodePath *curvePath(ListNodePath *path);

/**
 * @brief Adds a "Smooth Cubic Bezier Curve" (S) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'S' command.
 * Prompts the user for two pairs of coordinates (x1,y1, x2,y2)
 * defining the control and end points of the smooth curve.
 */
ListNodePath *ShortCurvePath(ListNodePath *path);

/**
 * @brief Adds a "Quadratic Bezier Curve" (Q) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'Q' command.
 * Prompts the user for two pairs of coordinates (x1,y1, x2,y2)
 * defining the control and end points of the quadratic curve.
 */
ListNodePath *QuadraticCurvePath(ListNodePath *path);

/**
 * @brief Adds a "Smooth Quadratic Bezier Curve" (T) command to an SVG path.
 *
 * @param path Pointer to the current ListNodePath.
 * @return Pointer to the previous node (the same as the input path).
 *
 * @details
 * Allocates a new path node representing the 'T' command.
 * Prompts the user for one pair of coordinates (x,y) defining the end point
 * of the smooth quadratic curve.
 */
ListNodePath *ShortQuadraticPath(ListNodePath *path);

