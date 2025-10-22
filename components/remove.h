#include "list.h"
#include "../config/struct.h"
/**
 * @brief Removes a shape from the list at a specified index.
 *
 * @param list Pointer to the List structure containing all shapes.
 * @param id Index of the shape to remove (0-based).
 * @return Pointer to the updated List structure after removal.
 *
 * @details
 * This function deletes a specific shape from the linked list based on its index.
 * It first checks whether the list is empty, then traverses to the correct node.
 * Depending on the shape type, it calls the appropriate memory release function:
 * - freeRectangle()
 * - freeCircle()
 * - freeLine()
 * - freeSquare()
 * - freeEllipse()
 * - freeShapeless() (for polygons and polylines)
 * - freePath()
 *
 * The node is then safely removed from the list, and pointers are updated accordingly.
 * If the list becomes empty after removal, a new empty list is automatically created.
 *
 * @note Prints status messages for success or invalid input.
 * Make sure to handle the returned list pointer, as it may change when removing the first element.
 */
List *removeShape(List *list, int id);
