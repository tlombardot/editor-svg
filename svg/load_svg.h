#ifndef IMPORT_H
#define IMPORT_H

#include "../config/struct.h"

/**
 * @brief Imports basic SVG shapes from a file into the program’s shape list.
 *
 * @param filename The path to the SVG file to import.
 * @param list Pointer to the List structure where imported shapes will be added.
 *
 * @details
 * This function parses a simple SVG file and reads supported elements
 * (`<rect>`, `<circle>`, `<ellipse>`, and `<line>`).
 * For each recognized tag, it extracts relevant attributes such as position,
 * dimensions, and color values, then dynamically allocates a corresponding
 * `Data` structure and appends it to the provided list.
 *
 * ### Supported SVG Elements:
 * - **Rectangle (`<rect>`)**
 *   - Attributes: `x`, `y`, `width`, `height`, `fill="rgb(R,G,B)"`
 * - **Circle (`<circle>`)**
 *   - Attributes: `cx`, `cy`, `r`, `fill="rgb(R,G,B)"`
 * - **Ellipse (`<ellipse>`)**
 *   - Attributes: `cx`, `cy`, `rx`, `ry`, `fill="rgb(R,G,B)"`
 * - **Line (`<line>`)**
 *   - Attributes: `x1`, `y1`, `x2`, `y2`, `stroke="rgb(R,G,B)"`
 *
 * Unsupported tags are ignored, and memory for temporary shape allocations
 * is freed accordingly.
 *
 * @note
 * - The parser assumes a clean and consistent SVG format without nested tags or
 *   extra whitespace between attributes.
 * - Imported shapes only store basic geometry and color data (fill or stroke),
 *   without advanced transformations or styles.
 *
 * @warning
 * - If the file cannot be opened, an error message is displayed and no shapes
 *   are imported.
 * - The function does not perform full XML parsing—only minimal sequential scanning.
 *
 * @see appendList
 */
void importSVG(char *filename, List *list);

#endif
