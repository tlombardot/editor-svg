
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"



/**
 * @brief Creates an empty list of shapes.
 *
 * @return Pointer to a newly allocated List structure.
 *
 * @details Initializes an empty list with a single allocated node and length set to zero.
 * Used to store all created SVG shapes in memory.
 */
List *createList(void);

/**
 * @brief Appends a new shape to the end of the list.
 *
 * @param list Pointer to the existing List structure.
 * @param data Pointer to the Data structure representing the shape to add.
 * @return Pointer to the updated List structure.
 *
 * @details Adds a new node containing the provided shape to the end of the linked list.
 * If the list is empty, the first node is initialized with the shape data.
 */
List *appendList(List *list, Data *data);

/**
 * @brief Displays all shapes currently stored in the list.
 *
 * @param list Pointer to the List structure containing the shapes.
 *
 * @details Iterates through the list and calls the corresponding get function
 * (e.g., getRectangle, getCircle, getShape, etc.) for each shape type.
 * Prints all shape information in order.
 */
void getList(List *list);

/**
 * @brief Frees all memory associated with a list of shapes.
 *
 * @param list Pointer to the List structure to free.
 *
 * @details Frees every node and the associated Data structures,
 * then frees the List structure itself.
 * Should be called when the program terminates or the list is no longer needed.
 */
void freeList(List *list);
