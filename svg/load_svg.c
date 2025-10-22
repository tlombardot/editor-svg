

#include <stdio.h>
#include <stdlib.h>
#include "../components/list.h"
#include "../config/struct.h"
#include "../config/color.h"
#include <string.h>


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
                int x=0, y=0, w=0, h=0;
                int rf=0,gf=0,bf=0, rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                int read = fscanf(file,
                    " x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" "
                    "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" "
                    "transform=\"translate(%d,%d) rotate(%d)",
                    &x, &y, &w, &h, &rf, &gf, &bf, &rs, &gs, &bs, &tx, &ty, &angle);

                if (read >= 7) {
                    shape->type = RECTANGLE;
                    shape->shape.rect.x = x;
                    shape->shape.rect.y = y;
                    shape->shape.rect.width = w;
                    shape->shape.rect.height = h;
                    shape->shape.rect.style.RF = rf;
                    shape->shape.rect.style.GF = gf;
                    shape->shape.rect.style.BF = bf;
                    shape->shape.rect.style.RS = rs;
                    shape->shape.rect.style.GS = gs;
                    shape->shape.rect.style.BS = bs;
                    shape->shape.rect.style.angle = angle;
                    shape->shape.rect.style.translate.x = tx;
                    shape->shape.rect.style.translate.y = ty;
                    appendList(list, shape);
                } else free(shape);
            }

            // === CIRCLE ===
            else if (tag[0] == 'c') {
                int cx=0, cy=0, r=0;
                int rf=0,gf=0,bf=0, rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                int read = fscanf(file,
                    " cx=\"%d\" cy=\"%d\" r=\"%d\" "
                    "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" "
                    "transform=\"translate(%d,%d) rotate(%d)",
                    &cx, &cy, &r, &rf, &gf, &bf, &rs, &gs, &bs, &tx, &ty, &angle);

                if (read >= 6) {
                    shape->type = CIRCLE;
                    shape->shape.circle.cx = cx;
                    shape->shape.circle.cy = cy;
                    shape->shape.circle.r = r;
                    shape->shape.circle.style.RF = rf;
                    shape->shape.circle.style.GF = gf;
                    shape->shape.circle.style.BF = bf;
                    shape->shape.circle.style.RS = rs;
                    shape->shape.circle.style.GS = gs;
                    shape->shape.circle.style.BS = bs;
                    shape->shape.circle.style.angle = angle;
                    shape->shape.circle.style.translate.x = tx;
                    shape->shape.circle.style.translate.y = ty;
                    appendList(list, shape);
                } else free(shape);
            }

            // === ELLIPSE ===
            else if (tag[0] == 'e') {
                int cx=0, cy=0, rx=0, ry=0;
                int rf=0,gf=0,bf=0, rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                int read = fscanf(file,
                    " cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" "
                    "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" "
                    "transform=\"translate(%d,%d) rotate(%d)",
                    &cx, &cy, &rx, &ry, &rf, &gf, &bf, &rs, &gs, &bs, &tx, &ty, &angle);

                if (read >= 7) {
                    shape->type = ELLIPSE;
                    shape->shape.elli.cx = cx;
                    shape->shape.elli.cy = cy;
                    shape->shape.elli.rx = rx;
                    shape->shape.elli.ry = ry;
                    shape->shape.elli.style.RF = rf;
                    shape->shape.elli.style.GF = gf;
                    shape->shape.elli.style.BF = bf;
                    shape->shape.elli.style.RS = rs;
                    shape->shape.elli.style.GS = gs;
                    shape->shape.elli.style.BS = bs;
                    shape->shape.elli.style.angle = angle;
                    shape->shape.elli.style.translate.x = tx;
                    shape->shape.elli.style.translate.y = ty;
                    appendList(list, shape);
                } else free(shape);
            }

            // === LINE ===
            else if (tag[0] == 'l') {
                int x1=0, y1=0, x2=0, y2=0;
                int rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                int read = fscanf(file,
                    " x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" "
                    "stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)",
                    &x1, &y1, &x2, &y2, &rs, &gs, &bs, &tx, &ty, &angle);

                if (read >= 7) {
                    shape->type = LINE;
                    shape->shape.line.x1 = x1;
                    shape->shape.line.y1 = y1;
                    shape->shape.line.x2 = x2;
                    shape->shape.line.y2 = y2;
                    shape->shape.line.style.RS = rs;
                    shape->shape.line.style.GS = gs;
                    shape->shape.line.style.BS = bs;
                    shape->shape.line.style.angle = angle;
                    shape->shape.line.style.translate.x = tx;
                    shape->shape.line.style.translate.y = ty;
                    appendList(list, shape);
                } else free(shape);
            }

            // === POLYGON ===
            else if (strncmp(tag, "polygon", 7) == 0) {
                char points[1024] = "";
                int rf=0,gf=0,bf=0, rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                int read = fscanf(file,
                    " points=\"%[^\"]\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)",
                    points, &rf, &gf, &bf, &rs, &gs, &bs, &tx, &ty, &angle);

                if (read >= 4) {
                    shape->type = POLYGONE;
                    shape->shape.poly = malloc(sizeof(ListPoly));
                    shape->shape.poly->style.RF = rf;
                    shape->shape.poly->style.GF = gf;
                    shape->shape.poly->style.BF = bf;
                    shape->shape.poly->style.RS = rs;
                    shape->shape.poly->style.GS = gs;
                    shape->shape.poly->style.BS = bs;
                    shape->shape.poly->style.angle = angle;
                    shape->shape.poly->style.translate.x = tx;
                    shape->shape.poly->style.translate.y = ty;

                    for (char *p = points; *p; ++p) if (*p == ',') *p = ' ';
                    char *ptr = points;
                    ListNodePoly *last = NULL;
                    while (*ptr) {
                        while (*ptr == ' ' || *ptr == '\n' || *ptr == '\r') ptr++;
                        if (!*ptr) break;
                        int x = strtol(ptr, &ptr, 10);
                        while (*ptr == ' ' || *ptr == '\n' || *ptr == '\r') ptr++;
                        int y = strtol(ptr, &ptr, 10);

                        ListNodePoly *node = malloc(sizeof(ListNodePoly));
                        node->value = malloc(sizeof(Polygone));
                        node->value->x = x;
                        node->value->y = y;
                        node->next = NULL;
                        node->previous = last;

                        if (last) last->next = node;
                        else shape->shape.poly->list = node;
                        last = node;
                        shape->shape.poly->lenght++;
                    }

                    appendList(list, shape);
                }
            }

            // === POLYLINE ===
            else if (strncmp(tag, "polyline", 8) == 0) {
                char line[1024] = "";
                fgets(line, sizeof(line), file); // lire toute la ligne

                char points[512] = "";
                int rf=0,gf=0,bf=0, rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                // lire fill facultatif et stroke + transform
                sscanf(line,
                    " points=\"%[^\"]\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)",
                    points, &rf,&gf,&bf, &rs,&gs,&bs, &tx,&ty,&angle);

                shape->type = STRLINE;
                shape->shape.poly = malloc(sizeof(ListPoly));
                shape->shape.poly->list = NULL;
                shape->shape.poly->lenght = 0;
                shape->shape.poly->style.RF = rf;
                shape->shape.poly->style.GF = gf;
                shape->shape.poly->style.BF = bf;
                shape->shape.poly->style.RS = rs;
                shape->shape.poly->style.GS = gs;
                shape->shape.poly->style.BS = bs;
                shape->shape.poly->style.angle = angle;
                shape->shape.poly->style.translate.x = tx;
                shape->shape.poly->style.translate.y = ty;

                for (char *p = points; *p; ++p) if (*p == ',') *p = ' ';
                char *ptr = points;
                ListNodePoly *last = NULL;
                while (*ptr) {
                    while (*ptr == ' ' || *ptr == '\n' || *ptr == '\r') ptr++;
                    if (!*ptr) break;
                    int x = strtol(ptr, &ptr, 10);
                    while (*ptr == ' ' || *ptr == '\n' || *ptr == '\r') ptr++;
                    int y = strtol(ptr, &ptr, 10);

                    ListNodePoly *node = malloc(sizeof(ListNodePoly));
                    node->value = malloc(sizeof(Polygone));
                    node->value->x = x;
                    node->value->y = y;
                    node->next = NULL;
                    node->previous = last;

                    if (last) last->next = node;
                    else shape->shape.poly->list = node;
                    last = node;
                    shape->shape.poly->lenght++;
                }

                appendList(list, shape);
            }

            // === PATH ===
            else if (tag[0] == 'p' && tag[1] == 'a') {
                char d[512] = "";
                int rf=0,gf=0,bf=0, rs=0,gs=0,bs=0, angle=0, tx=0, ty=0;

                int read = fscanf(file,
                    " d=\"%[^\"]\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)",
                    d, &rf, &gf, &bf, &rs, &gs, &bs, &tx, &ty, &angle);

                if (read >= 4) {
                    printf("%s",d);
                    shape->type = PATH;
                    shape->shape.path = malloc(sizeof(ListPath));
                    shape->shape.path->style.RF = rf;
                    shape->shape.path->style.GF = gf;
                    shape->shape.path->style.BF = bf;
                    shape->shape.path->style.RS = rs;
                    shape->shape.path->style.GS = gs;
                    shape->shape.path->style.BS = bs;
                    shape->shape.path->style.angle = angle;
                    shape->shape.path->style.translate.x = tx;
                    shape->shape.path->style.translate.y = ty;
                    appendList(list, shape);
                } else free(shape);
            }

            else {
                free(shape);
            }
        }
    }

    fclose(file);
    printf(YELLOW"✅ SVG imported successfully!" RESET "\n");
}