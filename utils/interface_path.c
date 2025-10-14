
#include "../config/struct.h"
#include <stdio.h>
#include "../components/get.h"
#include "../config/path.h"


Data *interfacePath(Data *path) {
    int answer = 1;
    ListNodePath *current = path->shape.path->list;

    while (answer != 0) {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║              🧭 PATH BUILDER           ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  1 ▸ Move (M)                          ║\n");
        printf("║  2 ▸ Line (L)                          ║\n");
        printf("║  3 ▸ Horizontal Line (H)               ║\n");
        printf("║  4 ▸ Vertical Line (V)                 ║\n");
        printf("║  5 ▸ Curve (C)                         ║\n");
        printf("║  6 ▸ Short Curve (S)                   ║\n");
        printf("║  7 ▸ Quadratic Curve (Q)               ║\n");
        printf("║  8 ▸ Short Quadratic Curve (T)         ║\n");
        printf("║  9 ▸ Close Path (Z)                    ║\n");
        printf("║  0 ▸ Back to previous menu             ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("➤ Your choice: ");

        answer = getInt();

        if (answer == 9) {
            printf("\n🔒 Path closed successfully.\n");
            break;
        }

        switch (answer) {
            case 1:
                printf("\n🏁 Move command selected (M)\n");
                current = movePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 2:
                printf("\n📏 Line command selected (L)\n");
                current = linePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 3:
                printf("\n↔️  Horizontal command selected (H)\n");
                current = horizontalPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 4:
                printf("\n↕️  Vertical command selected (V)\n");
                current = verticalPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 5:
                printf("\n🎯 Curve command selected (C)\n");
                current = curvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 6:
                printf("\n⚡ Short Curve command selected (S)\n");
                current = ShortCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 7:
                printf("\n🎨 Quadratic Curve command selected (Q)\n");
                current = QuadraticCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 8:
                printf("\n✏️  Short Quadratic command selected (T)\n");
                current = ShortQuadraticPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 0:
                printf("\n↩ Returning to previous menu...\n");
                break;
            default:
                printf("\n⚠️  Invalid choice! Please select from 0–9.\n");
                break;
        }
    }

    return path;
}
