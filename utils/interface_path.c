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
        HeaderLine();
        slowPrint(CYAN "PATH BUILDER\n" RESET, 1);
        HeaderLine();
        slowPrint(WHITE " [1] Move (M)\n", 1);
        slowPrint(" [2] Line (L)\n", 1);
        slowPrint(" [3] Horizontal Line (H)\n", 1);
        slowPrint(" [4] Vertical Line (V)\n", 1);
        slowPrint(" [5] Curve (C)\n", 1);
        slowPrint(" [6] Short Curve (S)\n", 1);
        slowPrint(" [7] Quadratic Curve (Q)\n", 1);
        slowPrint(" [8] Short Quadratic Curve (T)\n", 1);
        slowPrint(" [9] Close Path (Z)\n", 1);
        slowPrint(" [0] Back to previous menu\n", 1);
        HeaderLine();
        slowPrint(CYAN "INPUT> " RESET, 1);

        answer = getInt();

        if (answer == 9) {
            slowPrint(WHITE "\nPath closed successfully.\n" RESET, 2);
            break;
        }

        switch (answer) {
            case 1:
                slowPrint(WHITE "\nMove command selected (M)\n" RESET, 2);
                current = movePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 2:
                slowPrint(WHITE "\nLine command selected (L)\n" RESET, 2);
                current = linePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 3:
                slowPrint(WHITE "\nHorizontal command selected (H)\n" RESET, 2);
                current = horizontalPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 4:
                slowPrint(WHITE "\nVertical command selected (V)\n" RESET, 2);
                current = verticalPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 5:
                slowPrint(WHITE "\nCurve command selected (C)\n" RESET, 2);
                current = curvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 6:
                slowPrint(WHITE "\nShort Curve command selected (S)\n" RESET, 2);
                current = ShortCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 7:
                slowPrint(WHITE "\nQuadratic Curve command selected (Q)\n" RESET, 2);
                current = QuadraticCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 8:
                slowPrint(WHITE "\nShort Quadratic command selected (T)\n" RESET, 2);
                current = ShortQuadraticPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 0:
                slowPrint(WHITE "\nReturning to previous menu...\n" RESET, 2);
                break;
            default:
                slowPrint(CYAN "ERROR> " RESET WHITE "Invalid choice! Please select 0–9.\n", 2);
                break;
        }
    }

    return path;
}
