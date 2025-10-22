#ifndef GET_H
#define GET_H
#include "../config/struct.h"
#include "stdbool.h"

/**
 * @brief Displays the properties of a rectangle shape.
 *
 * @param rectangle Pointer to the Data structure representing the rectangle.
 * @param index Index number of the rectangle in the list.
 *
 * @details Prints position, dimensions, fill/stroke color, and rotation angle.
 */
void getRectangle(Data *rectangle, int index);

/**
 * @brief Displays the properties of a square shape.
 *
 * @param square Pointer to the Data structure representing the square.
 * @param index Index number of the square in the list.
 *
 * @details Prints position, size, fill/stroke color, and rotation angle.
 */
void getSquare(Data *square, int index);

/**
 * @brief Displays the properties of an ellipse shape.
 *
 * @param ellipse Pointer to the Data structure representing the ellipse.
 * @param index Index number of the ellipse in the list.
 *
 * @details Prints center coordinates, radii, fill/stroke color, and rotation angle.
 */
void getEllipse(Data *ellipse, int index);

/**
 * @brief Displays the properties of a circle shape.
 *
 * @param circle Pointer to the Data structure representing the circle.
 * @param index Index number of the circle in the list.
 *
 * @details Prints center coordinates, radius, fill/stroke color, and rotation angle.
 */
void getCircle(Data *circle, int index);

/**
 * @brief Displays the properties of a line shape.
 *
 * @param line Pointer to the Data structure representing the line.
 * @param index Index number of the line in the list.
 *
 * @details Prints start and end coordinates, fill/stroke color, and rotation angle.
 */
void getLine(Data *line, int index);

/**
 * @brief Displays the points and style information of a polygon or polyline.
 *
 * @param poly Pointer to the ListPoly structure containing shape data.
 * @param type Shape type (POLYGONE or STRLINE).
 * @param index Index number of the shape in the list.
 *
 * @details Prints the RGB style values and each point’s coordinates.
 */
void getShape(ListPoly *poly, ShapeType type, int index);

/**
 * @brief Displays the commands and style information of an SVG path.
 *
 * @param path Pointer to the ListPath structure containing the path data.
 * @param index Index number of the path in the list.
 *
 * @details Prints fill/stroke color, angle, and all SVG commands (M, L, H, V, C, S, Q, T).
 */
void getPath(ListPath *path, int index);

/**
 * @brief Displays a group and its contained shapes recursively.
 *
 * @param group Pointer to the Group structure to display.
 * @param depth The current depth of indentation for nested groups.
 *
 * @details Prints indentation and calls getList() on the group’s contents.
 */
void getGroup(Group *group, int depth);

/**
 * @brief Prompts the user for an integer input within a specified range.
 *
 * @param min Minimum acceptable value.
 * @param max Maximum acceptable value.
 * @return The validated integer input from the user.
 *
 * @details Displays an error message until a valid number between min and max is entered.
 */
int getInt(int min, int max);

/**
 * @brief Prompts the user to input an X coordinate.
 *
 * @return Integer value of the X coordinate (0–600).
 */
int getXCoord(void);

/**
 * @brief Prompts the user to input a Y coordinate.
 *
 * @return Integer value of the Y coordinate (0–300).
 */
int getYCoord(void);

/**
 * @brief Prompts the user to input a width value.
 *
 * @return Integer value of the width (0–200).
 */
int getWIDTHCoord(void);

/**
 * @brief Prompts the user to input a height value.
 *
 * @return Integer value of the height (0–100).
 */
int getHEIGHTCoord(void);

/**
 * @brief Prompts the user to input a range value.
 *
 * @return Integer value of the range (0–300).
 */
int getRange(void);

/**
 * @brief Prompts the user to input a single character.
 *
 * @return The character entered by the user.
 *
 * @details Reads and clears the input buffer to avoid unwanted characters.
 */
char getChar(void);

/**
 * @brief Prompts the user to input a string.
 *
 * @return Pointer to a dynamically allocated string (max length 100 chars).
 *
 * @note The returned string must be freed manually by the caller.
 */
char *getString(void);

/**
 * @brief Prompts the user for a yes/no (boolean) input.
 *
 * @return true if the user selects 'N' (No), false if 'Y' (Yes).
 *
 * @details Displays a confirmation question and validates input.
 * Used to determine whether to continue an interactive operation.
 */
bool getBool(void);


#endif
