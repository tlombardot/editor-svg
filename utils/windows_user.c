#include <stdbool.h>
#include <stdio.h>
#include "../components/list.h"
#include "../components/create.h"
#include "../config/struct.h"
#include "windows_user.h"

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

void userInterface()
{
    List *list = createList();
    int answer = getAnswer();
    printf("Welcome !\n");
    while (answer != 6)
    {
        switch (answer)
        {
        case 1:
            printf("What do you want to create ?\n 1 - Rectangle\n 2 - Square\n 3 - Line\n 4 - Circle\n 5 - Ellipse\nAnswer : ");
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
                Data *poly = createShapeless();
                list = appendList(list, poly);
                getList(list);
            default:
                break;
            }
            break;

        default:
            break;
        }
        answer = getAnswer();
    }
    return;
}
