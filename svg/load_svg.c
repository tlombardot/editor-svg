

#include <stdio.h>
#include <stdlib.h>
#include "../components/list.h"
#include "../config/struct.h"
#include "../config/color.h"


void importSVG(char *filename, List *list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf(MAGENTA "Failed to open SVG file!" RESET "\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '<') {
            char tag[16];
            int i = 0;
            while ((ch = fgetc(file)) != EOF && ch != ' ' && ch != '>') {
                if (i < 15) tag[i++] = ch;
            }
            tag[i] = '\0';
            Data *shape = malloc(sizeof(Data));
            // RECTANGLE
            if (tag[0] == 'r' && tag[1] == 'e') {
                int x, y, w, h, rf, gf, bf;
                if (fscanf(file, " x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d,%d,%d)",
                    &x, &y, &w, &h, &rf, &gf, &bf) == 7) {

                    shape->type = RECTANGLE;
                    shape->shape.rect.x = x;
                    shape->shape.rect.y = y;
                    shape->shape.rect.width = w;
                    shape->shape.rect.height = h;
                    shape->shape.rect.style.RF = rf;
                    shape->shape.rect.style.GF = gf;
                    shape->shape.rect.style.BF = bf;
                    appendList(list, shape);
                }
            }
            // CIRCLE
            else if (tag[0] == 'c') {
                int cx, cy, r, rf, gf, bf;
                if (fscanf(file, " cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgb(%d,%d,%d)",
                    &cx, &cy, &r, &rf, &gf, &bf) == 6) {

                    shape->type = CIRCLE;
                    shape->shape.circle.cx = cx;
                    shape->shape.circle.cy = cy;
                    shape->shape.circle.r = r;
                    shape->shape.circle.style.RF = rf;
                    shape->shape.circle.style.GF = gf;
                    shape->shape.circle.style.BF = bf;
                    appendList(list, shape);
                }
            }
            // ELLIPSE
            else if (tag[0] == 'e') {
                int cx, cy, rx, ry, rf, gf, bf;
                if (fscanf(file, " cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d,%d,%d)",
                    &cx, &cy, &rx, &ry, &rf, &gf, &bf) == 7) {

                    shape->type = ELLIPSE;
                    shape->shape.elli.cx = cx;
                    shape->shape.elli.cy = cy;
                    shape->shape.elli.rx = rx;
                    shape->shape.elli.ry = ry;
                    shape->shape.elli.style.RF = rf;
                    shape->shape.elli.style.GF = gf;
                    shape->shape.elli.style.BF = bf;
                    appendList(list, shape);
                }
            }
            // LINE
            else if (tag[0] == 'l') {
                int x1, y1, x2, y2, rs, gs, bs;
                if (fscanf(file, " x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"rgb(%d,%d,%d)",
                    &x1, &y1, &x2, &y2, &rs, &gs, &bs) == 7) {

                    shape->type = LINE;
                    shape->shape.line.x1 = x1;
                    shape->shape.line.y1 = y1;
                    shape->shape.line.x2 = x2;
                    shape->shape.line.y2 = y2;
                    shape->shape.line.style.RS = rs;
                    shape->shape.line.style.GS = gs;
                    shape->shape.line.style.BS = bs;
                    appendList(list, shape);
                }
            }
            else {
                free(shape);
            }
        }
    }

    fclose(file);
    printf(YELLOW"SVG imported successfully!" RESET "\n");
}