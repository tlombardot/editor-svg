#include <stdbool.h>
#include <stdio.h>
#include "../components/list.h"
#include "../components/create.h"
#include "../config/struct.h"
#include "windows_user.h"
#include "interface_path.h"

int getAnswer()
{
    int answer;
    while ((answer <= 0) || (answer > 6))
    {
        printf("What do you want to do ?\n 1 - Create a SVG\n 2 - Edit a SVG\n 3 - Remove a SVG\n 4 - Export SVG\n 5 - Import SVG\n 6 - Quit\nAnswer : ");
        scanf("%d", &answer);
        if ((answer <= 0) || (answer > 6))
        {
            printf("Error!\n");
        }
    }
    return answer;
}


List *userInterface()
{
    List *list = createList();
    int answer = getAnswer();
    printf("Welcome !\n");
    while (answer != 6)
    {
        switch (answer)
        {
        case 1:
            printf("What do you want to create ?\n 1 - Rectangle\n 2 - Square\n 3 - Line\n 4 - Circle\n 5 - Ellipse\n 6 - Polygone\n 7 - Polyline\n 8 - Path\n 9 - Group\n Answer : ");
            scanf("%d", &answer);
            switch (answer)
            {
            case 1:
                Data *rectangle = createRectangle();
                list = appendList(list, rectangle);
                getList(list);
                break;
            case 2:
                Data *square = createSquare();
                list = appendList(list, square);
                getList(list);
                break;
            case 3:
                Data *line = createLine();
                list = appendList(list, line);
                getList(list);
                break;
            case 4:
                Data *circle = createCircle();
                list = appendList(list, circle);
                getList(list);
                break;
            case 5:
                Data *ellipse = createEllipse();
                list = appendList(list, ellipse);
                getList(list);
                break;
            case 6:
                Data *poly = createShapeless(POLYGONE);
                list = appendList(list, poly);
                getList(list);
                break;
            case 7:
                Data *strline = createShapeless(STRLINE);
                list = appendList(list, strline);
                getList(list);
                break;
            case 8:
                Data *path = createPath();
                path = interfacePath(path);
                list = appendList(list, path);
                getList(list);
                break;
            case 9:
                Data *group = createGroup();
                group->shape.group->grouplist = userInterface();
                list = appendList(list, group);
                getList(list);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("Press number of the shape you want to edit\n");

        default:
            break;
        }
        answer = getAnswer();
    }
    return list;
}
