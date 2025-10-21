
#include "get.h"
#include "../config/struct.h"
#include <stdbool.h>
#include <stdio.h>
#include "../utils/windows_user.h"
#include "../config/color.h"




// === PRINT SHAPES ===
void getRectangle(Data *rectangle, int index) {
    printf(BOLD CYAN "■ RECTANGLE #%d\n" RESET, index);
    printf(BOLD WHITE " Pos: " RESET "(%d, %d)  " BOLD WHITE "W/H: " RESET "%d/%d\n",
           rectangle->shape.rect.x, rectangle->shape.rect.y,
           rectangle->shape.rect.width, rectangle->shape.rect.height);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
           rectangle->shape.rect.style.RF, rectangle->shape.rect.style.GF, rectangle->shape.rect.style.BF,
           rectangle->shape.rect.style.RS, rectangle->shape.rect.style.GS, rectangle->shape.rect.style.BS,
           rectangle->shape.rect.style.angle);
    HeaderLine();
}

void getSquare(Data *square, int index) {
    printf(BOLD CYAN "■ SQUARE #%d\n" RESET, index);
    printf(BOLD WHITE " Pos: " RESET "(%d, %d)  " BOLD WHITE "Size: " RESET "%d\n",
           square->shape.squ.x, square->shape.squ.y, square->shape.squ.wh);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
           square->shape.squ.style.RF, square->shape.squ.style.GF, square->shape.squ.style.BF,
           square->shape.squ.style.RS, square->shape.squ.style.GS, square->shape.squ.style.BS,
           square->shape.squ.style.angle);
    HeaderLine();
}

void getEllipse(Data *ellipse, int index) {
    printf(BOLD CYAN "● ELLIPSE #%d\n" RESET, index);
    printf(BOLD WHITE " Center: " RESET "(%d, %d)  " BOLD WHITE "Radius: " RESET "%d/%d\n",
           ellipse->shape.elli.cx, ellipse->shape.elli.cy,
           ellipse->shape.elli.rx, ellipse->shape.elli.ry);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
           ellipse->shape.elli.style.RF, ellipse->shape.elli.style.GF, ellipse->shape.elli.style.BF,
           ellipse->shape.elli.style.RS, ellipse->shape.elli.style.GS, ellipse->shape.elli.style.BS,
           ellipse->shape.elli.style.angle);
    HeaderLine();
}

void getCircle(Data *circle, int index) {
    printf(BOLD CYAN "● CIRCLE #%d\n" RESET, index);
    printf(BOLD WHITE " Center: " RESET "(%d, %d)  " BOLD WHITE "Radius: " RESET "%d\n",
           circle->shape.circle.cx, circle->shape.circle.cy, circle->shape.circle.r);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
           circle->shape.circle.style.RF, circle->shape.circle.style.GF, circle->shape.circle.style.BF,
           circle->shape.circle.style.RS, circle->shape.circle.style.GS, circle->shape.circle.style.BS,
           circle->shape.circle.style.angle);
    HeaderLine();
}

void getLine(Data *line, int index) {
    printf(BOLD CYAN "─ LINE #%d\n" RESET, index);
    printf(BOLD WHITE " Start: " RESET "(%d, %d)  " BOLD WHITE "End: " RESET "(%d, %d)\n",
           line->shape.line.x1, line->shape.line.y1,
           line->shape.line.x2, line->shape.line.y2);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
           line->shape.line.style.RF, line->shape.line.style.GF, line->shape.line.style.BF,
           line->shape.line.style.RS, line->shape.line.style.GS, line->shape.line.style.BS,
           line->shape.line.style.angle);
    HeaderLine();
}

void getShape(ListPoly *poly, ShapeType type, int index) {
    if(type == POLYGONE) printf(BOLD MAGENTA "▲ POLYGON POINTS #%d\n" RESET, index);
    else if(type == STRLINE) printf(BOLD MAGENTA "─ POLYLINE POINTS #%d\n" RESET, index);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
        poly->style.RF, poly->style.GF, poly->style.BF,
        poly->style.RS, poly->style.GS, poly->style.BS,
        poly->style.angle);
    int i = 1;
    ListNodePoly *current = poly->list;
    while(current) {
        printf(BOLD WHITE " Point #%d: " RESET "(x=%d, y=%d)\n", i, current->value->x, current->value->y);
        current = current->next; i++;
    }
    HeaderLine();
}

void getPath(ListPath *path, int index) {
    printf( YELLOW "✦ PATH COMMANDS #%d\n" RESET, index);
    printf(BOLD WHITE " Fill: " RESET "%d/%d/%d  " BOLD WHITE "Stroke: " RESET "%d/%d/%d  " BOLD WHITE "Angle: " RESET "%d°\n",
        path->style.RF, path->style.GF, path->style.BF,
        path->style.RS, path->style.GS, path->style.BS,
        path->style.angle);
    ListNodePath *cur = path->list;
    while(cur) {
        char c = cur->path->orderType;
        switch(c) {
            case 'M': printf("M %d %d  ", cur->path->order.mv.x, cur->path->order.mv.y); break;
            case 'L': printf("L %d %d  ", cur->path->order.lp.x, cur->path->order.lp.y); break;
            case 'H': printf("H %d  ", cur->path->order.h.x); break;
            case 'V': printf("V %d  ", cur->path->order.v.y); break;
            case 'C': printf("C %d %d %d %d %d %d  ",
                              cur->path->order.c.x1, cur->path->order.c.y1,
                              cur->path->order.c.x2, cur->path->order.c.y2,
                              cur->path->order.c.x3, cur->path->order.c.y3); break;
            case 'S': printf("S %d %d %d %d  ",
                              cur->path->order.sc.x1, cur->path->order.sc.y1,
                              cur->path->order.sc.x2, cur->path->order.sc.y2); break;
            case 'Q': printf("Q %d %d %d %d  ",
                              cur->path->order.qc.x1, cur->path->order.qc.y1,
                              cur->path->order.qc.x2, cur->path->order.qc.y2); break;
            case 'T': printf("T %d %d  ", cur->path->order.sq.x, cur->path->order.sq.y); break;
            default: break;
        }
        cur = cur->next;
    }
    printf("\n");
    HeaderLine();
}

void getGroup(Group *group, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("Group\n");
    HeaderLine();
    group->depth ++;
    getList(group->grouplist);
}



// === INTEGRER INPUT ===
int getInt(int min, int max) {
    int value;

    while (true) {

        if (scanf("%d", &value) == 1 && value >= min && value <= max) {
            while(getchar() != '\n');
            return value;
        } else {
            while(getchar() != '\n');
            printf(BOLD MAGENTA "Invalid input!" RESET " Please enter a number " BOLD YELLOW "%d–%d" RESET "\n",min, max);
        }
    }
}

// X/Y/Width/Height/Range inputs
int getXCoord() { printf(BOLD MAGENTA "X> " RESET); return getInt(0,600); }
int getYCoord() { printf(BOLD MAGENTA "Y> " RESET); return getInt(0,300); }
int getWIDTHCoord() { printf(BOLD YELLOW "WIDTH> " RESET); return getInt(0,200); }
int getHEIGHTCoord() { printf(BOLD YELLOW "HEIGHT> " RESET); return getInt(0,100); }
int getRange() { printf(BOLD GREEN "RANGE> " RESET); return getInt(0,300); }

// Char input
char getChar() {
    char c;
    scanf(" %c", &c);
    while(getchar() != '\n');
    return c;
}

char *getString() {
    char *stri = malloc(sizeof(char) * 100);
    scanf(" %s", stri);
    return  stri;
}

// Boolean prompt
bool getBool() {
    while(true) {
        printf(BOLD YELLOW "Continue ? (Y(/N): " RESET);
        char c = getChar();
        if(c == 'y' || c == 'Y') return false;
        else if(c == 'n' || c == 'N') return true;
        else printf(BOLD MAGENTA "Invalid choice!" RESET YELLOW " Enter Y(es) or N(o).\n");
    }
}
