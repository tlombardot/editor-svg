
#include "../config/struct.h"
#include "list.h"


/**
 * @brief Edits the X coordinate of a given SVG shape.
 *
 * @param data Pointer to the Data structure representing the shape to modify.
 *
 * @details Depending on the shape type (rectangle, circle, ellipse, etc.),
 * this function prompts the user to input a new X coordinate value.
 * For polygon and polyline shapes, it allows choosing which vertex to modify.
 */
void editX(Data *data);

/**
 * @brief Edits the Y coordinate of a given SVG shape.
 *
 * @param data Pointer to the Data structure representing the shape to modify.
 *
 * @details The function displays the current shape, then prompts the user
 * to enter a new Y coordinate depending on the shape type.
 */
void editY(Data *data);

/**
 * @brief Edits the rotation angle of a given SVG shape.
 *
 * @param data Pointer to the Data structure representing the shape to modify.
 *
 * @details Prompts the user to enter a new rotation angle (0–360°).
 * Applies the change to the shape’s style field.
 */
void editAngle(Data *data);

/**
 * @brief Edits the fill color of a given SVG shape.
 *
 * @param data Pointer to the Data structure representing the shape to modify.
 *
 * @details Allows the user to input new RGB color values (0–255) for the fill style.
 * The changes are applied directly to the shape’s style data.
 */
void editFill(Data *data);

/**
 * @brief Edits the stroke (outline) color of a given SVG shape.
 *
 * @param data Pointer to the Data structure representing the shape to modify.
 *
 * @details Prompts the user to enter new RGB values (0–255) for the stroke color.
 * Updates the corresponding style fields of the shape.
 */
void editStroke(Data *data);

/**
 * @brief Edits the translation (position offset) of a given SVG shape.
 *
 * @param data Pointer to the Data structure representing the shape to modify.
 *
 * @details Prompts the user to input new X and Y translation values.
 * Updates the shape’s transformation style accordingly.
 */
void editTranslate(Data *data);

/**
 * @brief Opens an interactive editing menu for a specific shape in a list.
 *
 * @param ListShape Pointer to the list of shapes.
 * @param index Index of the shape to be edited within the list.
 *
 * @details Displays a menu allowing the user to modify the X/Y coordinates,
 * fill color, stroke color, translation, or rotation angle of the selected shape.
 * Returns to the main menu when the user chooses option 0.
 */
void editShape(List *ListShape, int index);
