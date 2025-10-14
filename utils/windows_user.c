#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../components/list.h"
#include "../components/create.h"
#include "../config/struct.h"
#include "windows_user.h"
#include "interface_path.h"
#include "../components/get.h"
#include "../components/edit.h"
#include "../components/remove.h"


int getAnswer()
{
    int answer = -1;
    while ((answer < 0) || (answer > 6))
    {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║              MAIN MENU                 ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  1 ▸ Create a new SVG                  ║\n");
        printf("║  2 ▸ Edit an existing SVG              ║\n");
        printf("║  3 ▸ Remove an SVG                     ║\n");
        printf("║  4 ▸ Export SVG to file                ║\n");
        printf("║  5 ▸ Import SVG from file              ║\n");
        printf("║  6 ▸ Print SVG                         ║\n");
        printf("║  0 ▸ Quit                              ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("➤ Your choice: ");

        scanf("%d", &answer);
        if ((answer < 0) || (answer > 6))
        {
            printf("\n⚠️  Invalid choice! Please enter a number between 0 and 6.\n");
        }
    }
    return answer;
}

void createInterface(List *list){
    system("clear");
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║           CREATE NEW SVG SHAPE         ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1 ▸ Rectangle                         ║\n");
    printf("║  2 ▸ Square                            ║\n");
    printf("║  3 ▸ Line                              ║\n");
    printf("║  4 ▸ Circle                            ║\n");
    printf("║  5 ▸ Ellipse                           ║\n");
    printf("║  6 ▸ Polygon                           ║\n");
    printf("║  7 ▸ Polyline                          ║\n");
    printf("║  8 ▸ Path                              ║\n");
    printf("║  9 ▸ Group                             ║\n");
    printf("║  0 ▸ Back to Menu                      ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("➤ Your choice: ");

    int answer = getInt();

    switch (answer)
    {
    case 1: // RECTANGLE
    {
        Data *rectangle = createRectangle();
        list = appendList(list, rectangle);
        getList(list);
        break;
    }
    case 2: // SQUARE
    {
        Data *square = createSquare();
        list = appendList(list, square);
        getList(list);
        break;
    }
    case 3: // LINE
    {
        Data *line = createLine();
        list = appendList(list, line);
        getList(list);
        break;
    }
    case 4: // CIRCLE
    {
        Data *circle = createCircle();
        list = appendList(list, circle);
        getList(list);
        break;
    }
    case 5: // ELLIPSE
    {
        Data *ellipse = createEllipse();
        list = appendList(list, ellipse);
        getList(list);
        break;
    }
    case 6: // POLYGON
    {
        Data *poly = createShapeless(POLYGONE);
        list = appendList(list, poly);
        getList(list);
        break;
    }
    case 7: // POLYLINE
    {
        Data *pline = createShapeless(STRLINE);
        list = appendList(list, pline);
        getList(list);
        break;
    }
    case 8: // PATH
    {
        Data *path = createPath();
        path = interfacePath(path);
        list = appendList(list, path);
        getList(list);
        break;
    }
    case 9: // GROUP
    {
        Data *group = createGroup();
        group->shape.group->grouplist = userInterface();
        list = appendList(list, group);
        getList(list);
        break;
    }
    case 0:
        printf("\n↩ Returning to main menu...\n");
        break;
    default:
        printf("\n⚠️  Invalid option!\n");
        break;
    }


}

List *userInterface()
{
    system("clear");
    List *list = createList();
    int answer = getAnswer();

    printf("Answer %d\n", answer);

    while (true)
    {
        switch (answer)
        {
        case 1: // CREATE
            createInterface(list);
            break;

        case 2: // EDIT
        {
            if (list->lenght == 0)
            {
                printf("\n⚠️  No shapes to edit.\n");
                break;
            }
            printf("\n✏️  Enter the number of the shape you want to edit (0–%d): ", list->lenght - 1);
            int shape;
            do
            {
                shape = getInt();
                if (shape < 0 || shape >= list->lenght)
                    printf("Invalid number. Try again (0–%d): ", list->lenght - 1);
            } while (shape < 0 || shape >= list->lenght);

            editShape(list, shape);
            getList(list);
            break;
        }

        case 3: // REMOVE
        {
            if (list->lenght == 0)
            {
                printf("\n⚠️  No shapes to delete.\n");
                break;
            }
            printf("\n🗑️  Enter the number of the shape you want to delete (0–%d): ", list->lenght - 1);
            int shape;
            do
            {
                shape = getInt();
                if (shape < 0 || shape >= list->lenght)
                    printf("Invalid number. Try again (0–%d): ", list->lenght - 1);
            } while (shape < 0 || shape >= list->lenght);

            list = removeShape(list, shape);
            getList(list);
            printf("✅ Shape deleted successfully (simulation).\n");
            break;
        }

        case 4: // EXPORT
        {
            printf("\n💾 Exporting SVG...\n");
            // exportSVG(list);
            break;
        }

        case 5: // IMPORT
        {
            printf("\n📂 Importing SVG...\n");
            // list = importSVG();
            break;
        }

        case 6: // PRINT
        {
            printf("\n🗂️  Print SVG...\n");
            getList(list);
            break;
        }

        case 0:
            printf("\n👋 Exiting program. Goodbye!\n");
            return list;

        default:
            printf("\n⚠️  Invalid answer.\n");
            break;
        }

        printf("\nPress ENTER to continue...");
        getchar(); getchar(); // pause before clearing
        system("clear");
        answer = getAnswer();
    }
}
