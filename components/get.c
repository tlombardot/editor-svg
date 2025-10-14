
#include "get.h"
#include "../config/struct.h"
#include <stdbool.h>
#include <stdio.h>


void getRectangle(Data *rectangle, int index) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║            🟥 RECTANGLE #%d             ║\n", index);
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Position : (x = %d, y = %d)\n", rectangle->shape.rect.x, rectangle->shape.rect.y);
    printf("║ Width    : %d\n", rectangle->shape.rect.width);
    printf("║ Height   : %d\n", rectangle->shape.rect.height);
    printf("║ Fill     : %d / %d / %d\n", rectangle->shape.rect.style.RF, rectangle->shape.rect.style.GF, rectangle->shape.rect.style.BF);
    printf("║ Stroke   : %d / %d / %d\n", rectangle->shape.rect.style.RS, rectangle->shape.rect.style.GS, rectangle->shape.rect.style.BS);
    printf("║ Angle    : %d°\n", rectangle->shape.rect.style.angle);
    printf("╚════════════════════════════════════════╝\n");
}

void getSquare(Data *square, int index) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║            ⬛ SQUARE #%d                ║\n", index);
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Position : (x = %d, y = %d)\n", square->shape.squ.x, square->shape.squ.y);
    printf("║ Size     : %d (width = height)\n", square->shape.squ.wh);
    printf("║ Fill     : %d / %d / %d\n", square->shape.squ.style.RF, square->shape.squ.style.GF, square->shape.squ.style.BF);
    printf("║ Stroke   : %d / %d / %d\n", square->shape.squ.style.RS, square->shape.squ.style.GS, square->shape.squ.style.BS);
    printf("║ Angle    : %d°\n", square->shape.squ.style.angle);
    printf("╚════════════════════════════════════════╝\n");
}

void getEllipse(Data *ellipse, int index) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║            🟣 ELLIPSE #%d               ║\n", index);
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Center : (x = %d, y = %d)\n", ellipse->shape.elli.cx, ellipse->shape.elli.cy);
    printf("║ Radius : %d (x-axis), %d (y-axis)\n", ellipse->shape.elli.rx, ellipse->shape.elli.ry);
    printf("║ Fill   : %d / %d / %d\n", ellipse->shape.elli.style.RF, ellipse->shape.elli.style.GF, ellipse->shape.elli.style.BF);
    printf("║ Stroke : %d / %d / %d\n", ellipse->shape.elli.style.RS, ellipse->shape.elli.style.GS, ellipse->shape.elli.style.BS);
    printf("║ Angle  : %d°\n", ellipse->shape.elli.style.angle);
    printf("╚════════════════════════════════════════╝\n");
}

void getCircle(Data *circle, int index) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║             🔵 CIRCLE #%d               ║\n", index);
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Center : (x = %d, y = %d)\n", circle->shape.circle.cx, circle->shape.circle.cy);
    printf("║ Radius : %d\n", circle->shape.circle.r);
    printf("║ Fill   : %d / %d / %d\n", circle->shape.circle.style.RF, circle->shape.circle.style.GF, circle->shape.circle.style.BF);
    printf("║ Stroke : %d / %d / %d\n", circle->shape.circle.style.RS, circle->shape.circle.style.GS, circle->shape.circle.style.BS);
    printf("║ Angle  : %d°\n", circle->shape.circle.style.angle);
    printf("╚════════════════════════════════════════╝\n");
}

void getLine(Data *line, int index) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║              ➖ LINE #%d                ║\n", index);
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Start : (x1 = %d, y1 = %d)\n", line->shape.line.x1, line->shape.line.y1);
    printf("║ End   : (x2 = %d, y2 = %d)\n", line->shape.line.x2, line->shape.line.y2);
    printf("║ Fill  : %d / %d / %d\n", line->shape.line.style.RF, line->shape.line.style.GF, line->shape.line.style.BF);
    printf("║ Stroke: %d / %d / %d\n", line->shape.line.style.RS, line->shape.line.style.GS, line->shape.line.style.BS);
    printf("║ Angle : %d°\n", line->shape.line.style.angle);
    printf("╚════════════════════════════════════════╝\n");
}

void getShape(ListNodePoly *poly, ShapeType type) {
    printf("\n╔════════════════════════════════════════╗\n");
    switch (type) {
        case POLYGONE:
            printf("║           🔷 POLYGON POINTS             ║\n");
            break;
        case STRLINE:
            printf("║          🔹 POLYLINE POINTS             ║\n");
            break;
        default:
            printf("║            UNKNOWN SHAPE               ║\n");
            break;
    }
    printf("╠════════════════════════════════════════╣\n");

    ListNodePoly *current = poly;
    int i = 1;
    while (current != NULL) {
        printf("║ Point #%d → (x = %d, y = %d)\n", i, current->value->x, current->value->y);
        current = current->next;
        i++;
    }
    printf("╚════════════════════════════════════════╝\n");
}

void getPath(ListNodePath *path) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║              🧭 PATH COMMANDS          ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Order sequence:                        \n║   ");

    ListNodePath *current = path;
    while (current != NULL) {
        char c = current->path->orderType;
        switch (c) {
            case 'M': printf("M %d %d  ", current->path->order.mv.x, current->path->order.mv.y); break;
            case 'L': printf("L %d %d  ", current->path->order.lp.x, current->path->order.lp.y); break;
            case 'H': printf("H %d  ", current->path->order.h.x); break;
            case 'V': printf("V %d  ", current->path->order.v.y); break;
            case 'C': printf("C %d %d  %d %d  %d %d  ",
                current->path->order.c.x1, current->path->order.c.y1,
                current->path->order.c.x2, current->path->order.c.y2,
                current->path->order.c.x3, current->path->order.c.y3);
                break;
            case 'S': printf("S %d %d  %d %d  ",
                current->path->order.sc.x1, current->path->order.sc.y1,
                current->path->order.sc.x2, current->path->order.sc.y2);
                break;
            case 'Q': printf("Q %d %d  %d %d  ",
                current->path->order.qc.x1, current->path->order.qc.y1,
                current->path->order.qc.x2, current->path->order.qc.y2);
                break;
            case 'T': printf("T %d %d  ",
                current->path->order.sq.x, current->path->order.sq.y);
                break;
            default: break;
        }
        current = current->next;
    }
    printf("\n╚════════════════════════════════════════╝\n");
}

int getInt(void) {
    int variable;
    bool isFinish = false;
    while (!isFinish) {
        if (scanf("%d", &variable) == 1 && variable >= 0 && variable <= 200) {
            isFinish = true;
        } else {
            printf("⚠️  Invalid value! Try again.\n");
            while (getchar() != '\n'); // clear input buffer
        }
    }
    return variable;
}

// --- Input Functions ---

int getXCoord() {
    int variable;
    printf("\n┌─────────────────────────────┐\n");
    printf("│  ✦ Enter the X coordinate:  │\n");
    printf("└─────────────────────────────┘\n> ");
    variable = getInt();
    return variable;
}

int getYCoord() {
    int variable;
    printf("\n┌─────────────────────────────┐\n");
    printf("│  ✦ Enter the Y coordinate:  │\n");
    printf("└─────────────────────────────┘\n> ");
    variable = getInt();
    return variable;
}

int getWIDTHCoord() {
    int variable;
    printf("\n┌─────────────────────────────┐\n");
    printf("│  ✦ Enter the width:         │\n");
    printf("└─────────────────────────────┘\n> ");
    variable = getInt();
    return variable;
}

int getHEIGHTCoord() {
    int variable;
    printf("\n┌─────────────────────────────┐\n");
    printf("│  ✦ Enter the height:        │\n");
    printf("└─────────────────────────────┘\n> ");
    variable = getInt();
    return variable;
}

int getRange() {
    int variable;
    printf("\n┌─────────────────────────────┐\n");
    printf("│  ✦ Enter the range:         │\n");
    printf("└─────────────────────────────┘\n> ");
    variable = getInt();
    return variable;
}

// --- Character Input ---

char getChar() {
    char var;
    scanf(" %c", &var);
    return var;
}

// --- Boolean Prompt ---

bool getBool() {
    char answer;
    bool valid = false;

    while (!valid) {
        printf("\n╭──────────────────────────────╮\n");
        printf("│  ↺ Continue the process ?    │\n");
        printf("│  (Y = yes / N = no)          │\n");
        printf("╰──────────────────────────────╯\n> ");

        answer = getChar();

        if (answer == 'y' || answer == 'Y') {
            valid = true;
            return false; // Continue
        }
        else if (answer == 'n' || answer == 'N') {
            valid = true;
            return true; // Stop
        }
        else {
            printf("\n⚠️  Invalid input! Please type 'y' or 'n'.\n");
        }
    }
    return false;
}
