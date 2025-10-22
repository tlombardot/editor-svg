#include "../config/struct.h"


/**
 * @brief Prompts the user to create a fill color style for a shape.
 *
 * @param style Pointer to a Style structure where fill values will be stored.
 * @return The updated Style structure containing the new fill color values.
 *
 * @details
 * Interactively asks the user for RGB values (0–255) for the fill color.
 * Updates the fields `RF`, `GF`, and `BF` of the Style structure and displays confirmation messages.
 */
Style createFillStyle(Style *style);

/**
 * @brief Prompts the user to create a stroke (outline) color style for a shape.
 *
 * @param style Pointer to a Style structure where stroke values will be stored.
 * @return The updated Style structure containing the new stroke color values.
 *
 * @details
 * Interactively asks the user for RGB values (0–255) for the stroke color.
 * Updates the fields `RS`, `GS`, and `BS` of the Style structure and prints feedback to the console.
 */
Style createStrokeStyle(Style *style);

/**
 * @brief Prompts the user to define a rotation angle for a shape.
 *
 * @param style Pointer to a Style structure where the rotation angle will be stored.
 * @return The updated Style structure with the assigned rotation angle.
 *
 * @details
 * Requests a rotation angle value from the user (0–360 degrees)
 * and updates the `angle` field in the Style structure.
 */
Style createAngleStyle(Style *style);

/**
 * @brief Prompts the user to define translation (position offset) values for a shape.
 *
 * @param style Pointer to a Style structure containing the current translation values.
 * @return A Translate structure containing the updated X and Y translation offsets.
 *
 * @details
 * Asks the user to provide translation values (X: 0–200, Y: 0–100).
 * Updates the `translate` field in the Style structure and displays a confirmation message.
 */
Translate createTranslateStyle(Style *style);
