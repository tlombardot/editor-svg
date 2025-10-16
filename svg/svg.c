
#include <stdio.h>
#include "../config/struct.h"
#include "../components/list.h"

// Style colors
#define RESET       "\x1b[0m"
#define BOLD        "\x1b[1m"
#define DIM         "\x1b[2m"

#define RED         "\x1b[91m"
#define GREEN       "\x1b[92m"
#define YELLOW      "\x1b[93m"
#define BLUE        "\x1b[94m"
#define MAGENTA     "\x1b[95m"
#define CYAN        "\x1b[96m"
#define WHITE       "\x1b[97m"


void exportSVG(char *filename, List *list, int index) {
    if (list == NULL || list->lenght == 0) {
        printf(BOLD RED "✖ List is empty!" RESET "\n");
        return;
    }
    ListNode *current = list->form;
    if (list->lenght > 1){
        for (int i = 0; i < index - 1; i++)
            current = current->next;
    }
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf(BOLD RED "✖ Failed to open file!" RESET "\n");
        return;
    }

    int width = 800, height = 600;
    fprintf(file, "<svg height=\"%d\" width=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", height, width);
    // Export shapes here
    switch (current->data->type) {
        case RECTANGLE:
            fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d,%d,%d)\" />\n",
                current->data->shape.rect.x, current->data->shape.rect.y,
                current->data->shape.rect.width, current->data->shape.rect.height,
                current->data->shape.rect.style.RF, current->data->shape.rect.style.GF, current->data->shape.rect.style.BF);
            break;
        case SQUARE:
            fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" fill=\"rgb(%d,%d,%d)\" />\n",
                current->data->shape.squ.x, current->data->shape.squ.y,
                current->data->shape.squ.wh,
                current->data->shape.squ.style.RF, current->data->shape.squ.style.GF, current->data->shape.squ.style.BF);
            break;
        case CIRCLE:
            fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgb(%d,%d,%d)\" />\n",
                current->data->shape.circle.cx, current->data->shape.circle.cy,
                current->data->shape.circle.r,
                current->data->shape.circle.style.RF, current->data->shape.circle.style.GF, current->data->shape.circle.style.BF);
            break;
        case ELLIPSE:
            fprintf(file, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d,%d,%d)\" />\n",
                current->data->shape.elli.cx, current->data->shape.elli.cy,
                current->data->shape.elli.rx, current->data->shape.elli.ry,
                current->data->shape.elli.style.RF, current->data->shape.elli.style.GF, current->data->shape.elli.style.BF);
            break;
        case LINE:
            fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" />\n",
                current->data->shape.line.x1, current->data->shape.line.y1,
                current->data->shape.line.x2, current->data->shape.line.y2,
                current->data->shape.line.style.RS, current->data->shape.line.style.GS, current->data->shape.line.style.BS);
            break;
        case STRLINE:
            fprintf(file, "<polyline points=\"400,100 500,200 600,100\" stroke=\"black\" stroke-width=\"2\" fill=\"none\" />\n");
            break;
        case POLYGONE:
            fprintf(file, "<polygon points=\"700,100 800,200 900,100\" stroke=\"black\" stroke-width=\"2\" fill=\"yellow\" />\n");
            break;
        case PATH:
            fprintf(file, "<path d=\"M100,400 Q200,500 300,400 T400,300\" stroke=\"black\" stroke-width=\"2\" fill=\"none\" />\n");
            break;
        default:

            break;
    }
    fprintf(file,"<script type=\"application/ecmascript\"><![CDATA[\n");
    fprintf(file, "    setInterval(function () {\n");
          // Force le navigateur à recharger le document
    fprintf(file, "      location.reload();\n");
    fprintf(file, "    }, 1000);\n");
    fprintf(file, "  ]]></script>\n");
    fprintf(file, "</svg>\n");
    fclose(file);
}
