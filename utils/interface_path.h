#ifndef PATH_I_H
#define PATH_I_H

#include "../config/struct.h"

/**
 * @brief Interactive console interface for building SVG path commands.
 *
 * @param path Pointer to a Data structure representing an SVG path.
 * @return The updated Data pointer containing all added path commands.
 *
 * @details
 * This function provides a text-based interface allowing the user to
 * construct an SVG `<path>` element step by step using various command types.
 * Each selected command appends a new node to the path’s linked list, building
 * the path dynamically based on user input.
 *
 * ### Available Path Commands:
 * | Option | SVG Command | Description                     |
 * |:------:|:-------------|:--------------------------------|
 * | 1 | **M** | Move to (sets new starting position) |
 * | 2 | **L** | Line to (draws a straight line) |
 * | 3 | **H** | Horizontal line |
 * | 4 | **V** | Vertical line |
 * | 5 | **C** | Cubic Bézier curve |
 * | 6 | **S** | Smooth cubic Bézier curve |
 * | 7 | **Q** | Quadratic Bézier curve |
 * | 8 | **T** | Smooth quadratic Bézier curve |
 * | 9 | **Z** | Close the path |
 * | 0 | **Return** | Go back to the previous menu |
 *
 * For each command, the user is prompted to enter coordinate values (X, Y, or both),
 * and the function appends a new node to the linked list of type `ListNodePath`.
 *
 * The loop continues until the user selects option 0 or closes the path (option 9).
 *
 * @note
 * - This function modifies the provided `Data` structure in-place.
 * - The number of path commands created is tracked by `path->shape.path->lenght`.
 * - The terminal screen is cleared before displaying each command menu.
 *
 * @warning
 * - The function assumes that `path` and its internal lists are already allocated.
 * - Invalid inputs are handled interactively, but malformed path data can still occur
 *   if memory allocation fails (not explicitly checked).
 *
 * @see movePath
 * @see linePath
 * @see horizontalPath
 * @see verticalPath
 * @see curvePath
 * @see ShortCurvePath
 * @see QuadraticCurvePath
 * @see ShortQuadraticPath
 */
Data *interfacePath(Data *path);

int getAnswerPath();

#endif
