
#include <stdio.h>
#include "../config/struct.h"
#include "../components/list.h"
#include "../config/color.h"


void exportSVG(char *filename, List *list, int index) {
    if (list == NULL || list->lenght == 0) {
        printf(BOLD MAGENTA "List is empty!" RESET "\n");
        return;
    }
    ListNode *current = list->form;
    if (list->lenght > 1){
        for (int i = 0; i < index; i++)
            current = current->next;
    }
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf(BOLD MAGENTA "Failed to open file!" RESET "\n");
        return;
    }

    int width = 800, height = 600;
    fprintf(file,"<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 600 300\" xmlns=\"http://www.w3.org/2000/svg\">\n",width,height);
    Style style;
    char transform[128];
    // Export shapes here
    switch (current->data->type) {
        case RECTANGLE:
            style = current->data->shape.rect.style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file,
                "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" "
                "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" "
                "transform=\"%s\" />\n",
                current->data->shape.rect.x, current->data->shape.rect.y,
                current->data->shape.rect.width, current->data->shape.rect.height,
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;
        case SQUARE:
            style = current->data->shape.squ.style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file,
                "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" "
                "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" "
                "transform=\"%s\" />\n",
                current->data->shape.squ.x, current->data->shape.squ.y,
                current->data->shape.squ.wh, current->data->shape.squ.wh,
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;

        case CIRCLE:
            style = current->data->shape.circle.style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file,
                "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" "
                "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" "
                "transform=\"%s\" />\n",
                current->data->shape.circle.cx, current->data->shape.circle.cy,
                current->data->shape.circle.r,
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;

        case ELLIPSE:
            style = current->data->shape.elli.style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file,
                "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" "
                "fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" "
                "transform=\"%s\" />\n",
                current->data->shape.elli.cx, current->data->shape.elli.cy,
                current->data->shape.elli.rx, current->data->shape.elli.ry,
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;

        case LINE:
            style = current->data->shape.line.style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file,
                "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" "
                "stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" transform=\"%s\" />\n",
                current->data->shape.line.x1, current->data->shape.line.y1,
                current->data->shape.line.x2, current->data->shape.line.y2,
                style.RS, style.GS, style.BS,
                transform);
            break;

        case POLYGONE:
            style = current->data->shape.poly->style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file, "<polygon points=\"");
            ListNodePoly *polyNode = current->data->shape.poly->list;
            while (polyNode) {
                fprintf(file, "%d,%d ", polyNode->value->x, polyNode->value->y);
                polyNode = polyNode->next;
            }
            fprintf(file,
                "\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" transform=\"%s\" />\n",
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;


        case STRLINE:
            style = current->data->shape.poly->style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file, "<polyline points=\"");
            ListNodePoly *lineNode = current->data->shape.poly->list;
            while (lineNode) {
                fprintf(file, "%d,%d ", lineNode->value->x, lineNode->value->y);
                lineNode = lineNode->next;
            }
            fprintf(file,
                "\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" transform=\"%s\" />\n",
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;

        case PATH:
            style = current->data->shape.path->style;
            sprintf(transform, "translate(%d,%d) rotate(%d)",
                    style.translate.x, style.translate.y, style.angle);
            fprintf(file, "<path d=\"");
            ListNodePath *pathNode = current->data->shape.path->list;
            while (pathNode) {
                char c = pathNode->path->orderType;
                switch (c) {
                    case 'M':
                        fprintf(file, "M%d,%d ", pathNode->path->order.mv.x, pathNode->path->order.mv.y);
                        break;
                    case 'L':
                        fprintf(file, "L%d,%d ", pathNode->path->order.lp.x, pathNode->path->order.lp.y);
                        break;
                    case 'H':
                        fprintf(file, "H%d ", pathNode->path->order.h.x);
                        break;
                    case 'V':
                        fprintf(file, "V%d ", pathNode->path->order.v.y);
                        break;
                    case 'C':
                        fprintf(file, "C%d,%d %d,%d %d,%d ",
                                pathNode->path->order.c.x1, pathNode->path->order.c.y1,
                                pathNode->path->order.c.x2, pathNode->path->order.c.y2,
                                pathNode->path->order.c.x3, pathNode->path->order.c.y3);
                        break;
                    case 'S':
                        fprintf(file, "S%d,%d %d,%d ",
                                pathNode->path->order.sc.x1, pathNode->path->order.sc.y1,
                                pathNode->path->order.sc.x2, pathNode->path->order.sc.y2);
                        break;
                    case 'Q':
                        fprintf(file, "Q%d,%d %d,%d ",
                                pathNode->path->order.qc.x1, pathNode->path->order.qc.y1,
                                pathNode->path->order.qc.x2, pathNode->path->order.qc.y2);
                        break;
                    case 'T':
                        fprintf(file, "T%d,%d ",
                                pathNode->path->order.sq.x, pathNode->path->order.sq.y);
                        break;
                    default:
                        break;
                }
                pathNode = pathNode->next;
            }
            fprintf(file,
                "\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"2\" transform=\"%s\" />\n",
                style.RF, style.GF, style.BF,
                style.RS, style.GS, style.BS,
                transform);
            break;
        default:

            break;
    }
    fprintf(file, "</svg>\n");
    fclose(file);
}
