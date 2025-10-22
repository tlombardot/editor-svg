#ifndef EXPORT_H
#define EXPORT_H

#include <stdio.h>
#include "../config/struct.h"
#include "../components/list.h"

/**
 * @brief Exports a single SVG shape from the list to an SVG file.
 *
 * @param filename The name (or path) of the output SVG file.
 * @param list Pointer to the List structure containing all shapes.
 * @param index The index of the shape to export (0-based).
 *
 * @details
 * This function creates an SVG file and writes the shape at the specified
 * index in the list into it. The exported SVG file includes a header
 * (`<svg>...</svg>`) and one shape element representing the selected shape.
 *
 * ### Supported SVG Elements:
 * - **Rectangle (`<rect>`)** — exports `x`, `y`, `width`, `height`, and `fill`.
 * - **Square (`<rect>`)** — exports `x`, `y`, `width`, and `fill`.
 * - **Circle (`<circle>`)** — exports `cx`, `cy`, `r`, and `fill`.
 * - **Ellipse (`<ellipse>`)** — exports `cx`, `cy`, `rx`, `ry`, and `fill`.
 * - **Line (`<line>`)** — exports `x1`, `y1`, `x2`, `y2`, and `stroke`.
 * - **Polyline (`<polyline>`)** and **Polygon (`<polygon>`)** —
 *   use fixed example coordinates (placeholder values).
 * - **Path (`<path>`)** — uses a sample `d` attribute with predefined commands.
 *
 * @note
 * - Only the selected shape at the given index is exported.
 * - Colors are written in the `rgb(R,G,B)` format based on the shape’s style.
 * - The output SVG has a default canvas size of **800×600 pixels**.
 *
 * @warning
 * - If the list is empty or the file cannot be opened, an error message is printed,
 *   and the function returns without writing any data.
 * - Shape types not explicitly supported are ignored.
 *
 * @see importSVG
 */
void exportSVG(char *filename, List *list, int index);

#endif