#ifndef SET_H
#define  SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"

/**
 * @brief Allocates memory for a new generic shape (Data structure).
 *
 * @return Pointer to a newly allocated Data structure.
 *
 * @details
 * This function allocates memory for a shape container (`Data`)
 * without initializing any specific shape type.
 * Used for basic shapes such as rectangles, circles, squares, lines, and ellipses.
 */
Data *allocateMemory(void);

/**
 * @brief Allocates memory for a new polygon or polyline shape.
 *
 * @return Pointer to a newly allocated Data structure prepared for polygon data.
 *
 * @details
 * Allocates memory for the Data structure, its internal `ListPoly`,
 * and the first `ListNodePoly` in the polygon linked list.
 * Used for shapes of type `POLYGONE` and `STRLINE`.
 */
Data *allocateMemoryPoly(void);

/**
 * @brief Allocates memory for a new SVG path shape.
 *
 * @return Pointer to a newly allocated Data structure prepared for path data.
 *
 * @details
 * Allocates memory for the Data structure, its internal `ListPath`,
 * the first `ListNodePath`, and the initial `Path` command.
 * Used for shapes of type `PATH`.
 */
Data *allocateMemoryPath(void);

/**
 * @brief Allocates memory for a new SVG group container.
 *
 * @return Pointer to a newly allocated Data structure prepared for group data.
 *
 * @details
 * Allocates memory for the Data structure and its associated `Group` structure.
 * Used for shapes of type `GROUP`.
 */
Data *allocateMemoryGroup(void);


#endif
