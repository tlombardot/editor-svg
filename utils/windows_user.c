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
#include "../config/color.h"
#include "../svg/load_svg.h"

// Sleep function (ms)
void sleep_ms(int milliseconds) {
    clock_t start = clock();
    clock_t end = start + (milliseconds * (CLOCKS_PER_SEC / 1000));
    while (clock() < end) { }
}


void moveCursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
    fflush(stdout);
}

// Header / Separator
void HeaderLine() {
    printf( YELLOW "─────────────────────────────────────────\n" RESET);
}

// === MAIN MENU ===
int getAnswer() {
    int answer = -1;

    while (answer < 0 || answer > 6) {
        system("clear");
        printf("\n");
            printf(YELLOW"  █▀▄▀█ ▄▀█ █ █▄░█  █▀▄▀█ █▀▀ █▄░█ █░█\n");
            printf("  █░▀░█ █▀█ █ █░▀█  █░▀░█ ██▄ █░▀█ █▄█\n\n");
            HeaderLine();
            printf("\n");
            printf(YELLOW"(1)..................Create new SVG shape\n");
            printf(YELLOW"(2).....................Edit existing SVG\n");
            printf(YELLOW"(3)............................Remove SVG\n");
            printf(YELLOW"(4)....................Export SVG to file\n");
            printf(YELLOW"(5)..................Import SVG from file\n");
            printf(YELLOW"(6)......................Display SVG list\n");
            printf(MAGENTA"(0)..........................Exit program\n\n");
            HeaderLine();
            printf("\n");
        printf( YELLOW "INPUT> " RESET);
        if(scanf("%d", &answer) != 1) {
            while(getchar() != '\n'); // clear invalid input
            printf(MAGENTA "\nERROR> Invalid input! Only numbers 0–6.\n\n" RESET);
            sleep_ms(600);
            answer = -1;
            continue;
        }
        while(getchar() != '\n'); // Clear input buffer

        if (answer < 0 || answer > 6) {
            printf(MAGENTA "\nERROR> Selection out of range! Choose 0–6.\n\n" RESET);
            sleep_ms(600);
        }
    }
    return answer;
}

// === CREATE INTERFACE ===
void createInterface(List *list) {
    system("clear");
    printf("\n");
    printf( YELLOW"    █▀ █░█ ▄▀█ █▀█ █▀▀  █▀█ █▀█ ▀█▀\n");
    printf(YELLOW"    ▄█ █▀█ █▀█ █▀▀ ██▄  █▄█ █▀▀ ░█░\n\n"RESET);
    HeaderLine();
    printf("\n");
    printf(YELLOW"(1).............................Rectangle\n");
    printf(YELLOW"(2)................................Square\n");
    printf(YELLOW"(3)..................................Line\n");
    printf(YELLOW"(4)................................Circle\n");
    printf(YELLOW"(5)...............................Ellipse\n");
    printf(YELLOW"(6)...............................Polygon\n");
    printf(YELLOW"(7)..............................Polyline\n");
    printf(YELLOW"(8)..................................Path\n");
    printf(YELLOW"(9).................................Group\n");
    printf(MAGENTA"(0).....................Back to Main Menu\n\n");
    HeaderLine();
    printf("\n");
    printf(YELLOW "INPUT> " RESET);
    int answer = getInt(0,9);
    if (answer == 1){
        moveCursor(7, 1);
        printf(BLINK_SLOW YELLOW"(1).............................Rectangle\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 2){
        moveCursor(8, 1);
        printf(BLINK_SLOW YELLOW"(2)................................Square\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 3){
        moveCursor(9, 1);
        printf(BLINK_SLOW YELLOW"(3)..................................Line\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 4){
        moveCursor(10, 1);
        printf(BLINK_SLOW YELLOW"(4)................................Circle\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 5){
        moveCursor(11, 1);
        printf(BLINK_SLOW YELLOW"(5)...............................Ellipse\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 6){
        moveCursor(12, 1);
        printf(BLINK_SLOW YELLOW"(6)...............................Polygon\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 7){
        moveCursor(13, 1);
        printf(BLINK_SLOW YELLOW"(7)..............................Polyline\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 8){
        moveCursor(14, 1);
        printf(BLINK_SLOW YELLOW"(8)..................................Path\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 9){
        moveCursor(15, 1);
        printf(BLINK_SLOW YELLOW"(9).................................Group\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }else if(answer == 0){
        moveCursor(16, 1);
        printf(BLINK_SLOW MAGENTA"(0).....................Back to Main Menu\n"RESET);
        moveCursor(20, 1);
        if (getBool() == true){return createInterface(list);}
    }

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
            printf(YELLOW "\nsystem> " RESET WHITE "returning to main menu...\n");
            sleep_ms(500);
            return;
        default:
            printf(MAGENTA "\nsystem> " RESET WHITE "unknown selection.\n");
            return;
    }

    if (shape != NULL) {
        list = appendList(list, shape);
        printf(YELLOW "\nsystem> " RESET WHITE "shape created successfully.\n");
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
                    printf(MAGENTA "system> " RESET BLUE "no shapes to edit.\n");
                    break;
                }
                printf(RESET WHITE "shape index to edit (0–%d): ", list->lenght - 1);
                do {
                    choice_edit = getInt(0,list->lenght-1);
                    if (choice_edit < 0 || choice_edit >= list->lenght) {
                        printf(MAGENTA "system> " RESET WHITE "invalid input.\n");
                    }
                }while (choice_edit < 0 || choice_edit >= list->lenght);
                editShape(list, choice_edit);
                break;

            case 3:
                int choice_remove;
                if (list->lenght == 0) {
                    printf(MAGENTA "system> " RESET WHITE "no shapes to delete.\n");
                    break;
                }
                printf(YELLOW "INPUT> " RESET WHITE "shape index to remove (0–%d): ", list->lenght - 1);
                do {
                    choice_remove = getInt(0, list->lenght-1);
                    if (choice_remove < 0 || choice_remove >= list->lenght) {
                        printf(MAGENTA "system> " RESET WHITE "invalid input.\n");
                    }
                }while (choice_remove < 0 || choice_remove >= list->lenght );
                list = removeShape(list, choice_remove);
                printf(YELLOW "system> " RESET WHITE "shape removed successfully.\n");
                break;

            case 4:
                if (list->lenght == 0) {
                    printf(MAGENTA "system> " RESET WHITE "no shapes to export.\n");
                    break;
                }
                int choice_export;
                do {
                    printf(YELLOW "INPUT> " RESET WHITE "shape index to export (0–%d): ", list->lenght - 1);
                    choice_export = getInt(0, list->lenght-1);
                    if (choice_export < 0 || choice_export >= list->lenght) {
                        printf(MAGENTA "system> " RESET WHITE "invalid input.\n");
                    }
                }while (choice_export < 0 || choice_export >= list->lenght);
                printf(YELLOW"INPUT>"RESET WHITE" What's your file name : ");
                char *filename = getString();
                printf(YELLOW "system> " RESET WHITE "exporting SVG to file...\n");
                exportSVG(filename, list, choice_export);
                free(filename);
                while(getchar() != '\n');
                break;

            case 5:
                printf(YELLOW"INPUT>"RESET WHITE" What's your file name : ");
                char *choice_import = getString();
                printf(YELLOW "system> " RESET WHITE "importing SVG from file...\n");
                importSVG(choice_import, list);
                while(getchar() != '\n');
                free(choice_import);
                break;

            case 6:
                printf(YELLOW "system> " RESET WHITE "displaying SVG list...\n\n");
                getList(list);
                break;

            case 0:
                return list;
            default:
                printf(MAGENTA "system> " RESET WHITE "invalid input.\n");
                break;
        }

        printf(YELLOW "\npress ENTER to continue..." RESET);
        getchar();
        answer = getAnswer();
    }
}
