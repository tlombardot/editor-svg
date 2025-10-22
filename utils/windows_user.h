#ifndef WINDOWS_USER
#define WINDOWS_USER

#include "../components/list.h"
/**
 * @brief Pauses the program for a specified duration in milliseconds.
 *
 * @param milliseconds Duration to sleep, in milliseconds.
 *
 * @note Uses busy-waiting with the clock() function (not ideal for long waits).
 */
void sleep_ms(int milliseconds);

/**
 * @brief Moves the terminal cursor to a specific row and column.
 *
 * @param row The target row position (1-based index).
 * @param col The target column position (1-based index).
 *
 * @note Uses ANSI escape sequences for cursor movement.
 */
void moveCursor(int row, int col);

/**
 * @brief Prints a decorative header or separator line.
 *
 * @note Used to visually separate interface sections in the terminal.
 */
void HeaderLine(void);

/**
 * @brief Displays the main menu and waits for the user's choice.
 *
 * @return An integer between 0 and 6 representing the selected option.
 *
 * @details The menu options include creating, editing, removing, importing, exporting,
 * and displaying SVG shapes, or exiting the program.
 * Invalid inputs are handled with error messages and input clearing.
 */
int getAnswer(void);

/**
 * @brief Displays the "Create Shape" interface for the user to choose and create SVG elements.
 *
 * @param list Pointer to a List structure containing existing SVG shapes.
 *
 * @details Allows users to select a specific SVG shape type (e.g., rectangle, circle, polygon),
 * create it via the corresponding creation function, and append it to the list.
 * If the user selects "0", the function returns to the main menu.
 */
void createInterface(List *list);

/**
 * @brief Launches the main user interface for the SVG editor.
 *
 * @return Pointer to the List structure containing all created SVG shapes.
 *
 * @details Provides an interactive menu to create, edit, remove, export, import,
 * and display SVG shapes. Handles user inputs and manages list operations.
 * The function runs in a loop until the user chooses to exit.
 */
List *userInterface(void);


#endif
