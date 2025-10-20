#include "../config/struct.h"
#include "../components/get.h"
#include "../config/path.h"
#include "windows_user.h"
#include "../config/color.h"

Data *interfacePath(Data *path) {
    system("clear");
    int answer = 1;
    ListNodePath *current = path->shape.path->list;

    while (answer != 0) {
        printf(YELLOW"\n█▀█  ▄▀█  ▀█▀  █░█  █▄▄  █░█  █  █░░  █▀▄\n");
        printf("█▀▀  █▀█  ░█░  █▀█  █▄█  █▄█  █  █▄▄  █▄▀\n\n");
        HeaderLine();
        printf( YELLOW"\n(1)..............................Move (M)\n");
        printf("(2)..............................Line (L)\n");
        printf("(3)...................Horizontal Line (H)\n");
        printf("(4).....................Vertical Line (V)\n");
        printf("(5).............................Curve (C)\n");
        printf("(6).......................Short Curve (S)\n");
        printf("(7)...................Quadratic Curve (Q)\n");
        printf("(8).............Short Quadratic Curve (T)\n");
        printf("(9)........................Close Path (Z)\n");
        printf(MAGENTA"(0).................Back to previous menu\n\n");
        HeaderLine();
        printf(YELLOW"\nINPUT> "RESET);

        answer = getInt(0,9);

        if (answer == 9) {
            printf(WHITE "\nPath closed successfully.\n" RESET);
            break;
        }

        switch (answer) {
            case 1:
                printf(WHITE "\nMove command selected (M)\n" RESET);
                current = movePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 2:
                printf(WHITE "\nLine command selected (L)\n" RESET);
                current = linePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 3:
                printf(WHITE "\nHorizontal command selected (H)\n" RESET);
                current = horizontalPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 4:
                printf(WHITE "\nVertical command selected (V)\n" RESET);
                current = verticalPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 5:
                printf(WHITE "\nCurve command selected (C)\n" RESET);
                current = curvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 6:
                printf(WHITE "\nShort Curve command selected (S)\n" RESET);
                current = ShortCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 7:
                printf(WHITE "\nQuadratic Curve command selected (Q)\n" RESET);
                current = QuadraticCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 8:
                printf(WHITE "\nShort Quadratic command selected (T)\n" RESET);
                current = ShortQuadraticPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 0:
                printf(WHITE "\nReturning to previous menu...\n" RESET);
                break;
            default:
                printf(CYAN "ERROR> " RESET WHITE "Invalid choice! Please select 0–9.\n");
                break;
        }
    }

    return path;
}
