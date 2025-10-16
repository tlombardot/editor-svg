#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../components/list.h"
#include "../components/create.h"
#include "../config/struct.h"
#include "windows_user.h"
#include "interface_path.h"
#include "../components/get.h"
#include "../components/edit.h"
#include "../components/remove.h"
#include "../svg/svg.h"

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

// Sleep function (ms)
void sleep_ms(int milliseconds) {
    clock_t start = clock();
    clock_t end = start + (milliseconds * (CLOCKS_PER_SEC / 1000));
    while (clock() < end) { }
}

// Slow print effect
void slowPrint(const char *text, int delay_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        sleep_ms(delay_ms);
    }
}

// Header / Separator
void HeaderLine() {
    printf(DIM CYAN "───────────────────────────────────────────────\n" RESET);
}

// === MAIN MENU ===
int getAnswer() {
    int answer = -1;

    while (answer < 0 || answer > 6) {
        system("clear");

        slowPrint(DIM CYAN "system> " RESET WHITE "booting main interface...\n", 3);
        sleep_ms(300);
        slowPrint(DIM CYAN "system> " RESET WHITE "ready.\n\n", 3);

        HeaderLine();
        slowPrint(BOLD CYAN "          ██████ MAIN MENU ██████          \n\n", 3);
        slowPrint(YELLOW " [1] " MAGENTA "Create a new SVG shape\n", 3);
        slowPrint(YELLOW " [2] " MAGENTA "Edit an existing SVG\n", 3);
        slowPrint(YELLOW " [3] " MAGENTA "Remove an SVG\n", 3);
        slowPrint(YELLOW " [4] " MAGENTA "Export SVG to file\n", 3);
        slowPrint(YELLOW " [5] " MAGENTA "Import SVG from file\n", 3);
        slowPrint(YELLOW " [6] " MAGENTA "Display current SVG list\n", 3);
        slowPrint(YELLOW " [0] " RED "Exit program\n\n" RESET,3);
        HeaderLine();

        printf(BOLD CYAN "INPUT> " RESET);
        if(scanf("%d", &answer) != 1) {
            while(getchar() != '\n'); // clear invalid input
            slowPrint(RED "\nERROR> Invalid input! Only numbers 0–6.\n\n" RESET, 2);
            sleep_ms(600);
            answer = -1;
            continue;
        }
        while(getchar() != '\n'); // Clear input buffer

        if (answer < 0 || answer > 6) {
            slowPrint(RED "\nERROR> Selection out of range! Choose 0–6.\n\n" RESET, 2);
            sleep_ms(600);
        }
    }

    return answer;
}

// === CREATE INTERFACE ===
void createInterface(List *list) {
    system("clear");
    slowPrint(DIM CYAN "system> " RESET WHITE "entering CREATE mode...\n\n", 3);
    HeaderLine();
    slowPrint(BOLD CYAN "          ┌── SELECT SHAPE ──┐\n\n" RESET, 3);

    slowPrint(BOLD YELLOW " [1] " MAGENTA "Rectangle\n", 3);
    slowPrint(YELLOW " [2] " MAGENTA "Square\n", 3);
    slowPrint(YELLOW " [3] " MAGENTA "Line\n", 3);
    slowPrint(YELLOW " [4] " MAGENTA "Circle\n", 3);
    slowPrint(YELLOW " [5] " MAGENTA "Ellipse\n", 3);
    slowPrint(YELLOW " [6] " MAGENTA "Polygon\n", 3);
    slowPrint(YELLOW " [7] " MAGENTA "Polyline\n", 3);
    slowPrint(YELLOW " [8] " MAGENTA "Path\n", 3);
    slowPrint(YELLOW " [9] " MAGENTA "Group\n", 3);
    slowPrint(YELLOW " [0] " RED "Back to Main Menu\n\n" RESET,3);

    HeaderLine();
    printf(BOLD CYAN "INPUT> " RESET);
    int answer = getInt();

    Data *shape = NULL;
    switch (answer) {
        case 1: shape = createRectangle(); break;
        case 2: shape = createSquare(); break;
        case 3: shape = createLine(); break;
        case 4: shape = createCircle(); break;
        case 5: shape = createEllipse(); break;
        case 6: shape = createShapeless(POLYGONE); break;
        case 7: shape = createShapeless(STRLINE); break;
        case 8: shape = createPath(); shape = interfacePath(shape); break;
        case 9:
            shape = createGroup();
            shape->shape.group->grouplist = userInterface();
            break;
        case 0:
            slowPrint(CYAN "\nsystem> " RESET WHITE "returning to main menu...\n", 2);
            sleep_ms(500);
            return;
        default:
            slowPrint(RED "\nsystem> " RESET WHITE "unknown selection.\n", 2);
            return;
    }

    if (shape != NULL) {
        list = appendList(list, shape);
        slowPrint(GREEN "\nsystem> " RESET WHITE "shape created successfully.\n", 3);
    }

    HeaderLine();
    getList(list);
}

// === MAIN USER INTERFACE ===
List *userInterface() {
    List *list = createList();
    int answer = getAnswer();

    while (true) {
        system("clear");
        switch (answer) {
            case 1: createInterface(list); break;

            case 2:
                int choice_edit;
                if (list->lenght == 0) {
                    slowPrint(RED "system> " RESET BLUE "no shapes to edit.\n", 2);
                    break;
                }
                printf(RESET WHITE "shape index to edit (0–%d): ", list->lenght - 1);
                do {
                    choice_edit = getInt();
                    slowPrint(RED "system> " RESET WHITE "invalid input.\n", 2);
                }while (choice_edit < 0 || choice_edit >= list->lenght);
                editShape(list, choice_edit);
                break;

            case 3:
                int choice_remove;
                if (list->lenght == 0) {
                    slowPrint(RED "system> " RESET WHITE "no shapes to delete.\n", 2);
                    break;
                }
                printf(BOLD CYAN "INPUT> " RESET WHITE "shape index to remove (0–%d): ", list->lenght - 1);
                do {
                    choice_remove = getInt();
                    slowPrint(RED "system> " RESET WHITE "invalid input.\n", 2);
                }while (choice_remove < 0 || choice_remove >= list->lenght);
                list = removeShape(list, choice_remove);
                slowPrint(GREEN "system> " RESET WHITE "shape removed successfully.\n", 2);
                break;

            case 4:
                if (list->lenght == 0) {
                    slowPrint(RED "system> " RESET WHITE "no shapes to export.\n", 2);
                    break;
                }
                int choice_export;
                do {
                    printf(BOLD CYAN "INPUT> " RESET WHITE "shape index to export (0–%d): ", list->lenght - 1);
                    choice_export = getInt();
                    if (choice_export < 0 || choice_export >= list->lenght) {
                        slowPrint(RED "system> " RESET WHITE "invalid input.\n", 2);
                    }
                }while (choice_export < 0 || choice_export >= list->lenght);
                slowPrint(CYAN "system> " RESET WHITE "exporting SVG to file...\n", 2);
                exportSVG("test.svg", list, choice_export);
                break;

            case 5:
                slowPrint(CYAN "system> " RESET WHITE "importing SVG from file...\n", 2);
                break;

            case 6:
                slowPrint(CYAN "system> " RESET WHITE "displaying SVG list...\n\n", 2);
                getList(list);
                break;

            case 0:
                system("clear");
                slowPrint(DIM CYAN "system> " RESET WHITE "shutting down...\n", 3);
                sleep_ms(500);
                slowPrint(BLUE "goodbye user.\n" RESET, 3);
                system("clear");
                freeList(list);
                HeaderLine();
                slowPrint(GREEN"|                MEMORY FREED                 |\n"RESET, 3);
                HeaderLine();
                return NULL;
            default:
                slowPrint(RED "system> " RESET WHITE "invalid input.\n", 2);
                break;
        }

        slowPrint(DIM CYAN "\npress ENTER to continue..." RESET, 1);
        getchar();
        answer = getAnswer();
    }
}
