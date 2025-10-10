

#include "get.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"


/*
Create List NULL
*/
List *createList(void)
{
    List *ListShape = malloc(sizeof(List));
    ListShape->form = malloc(sizeof(ListNode));
    ListShape->form->data = malloc(sizeof(Data));
    ListShape->lenght = 0;
    return ListShape;
}

/*
Add a shape to the list
*/
List *appendList(List *list, Data *data)
{
    if (list->lenght == 0)
    {
        list->form->data = data;
        list->lenght++;
        return list;
    }
    ListNode *current = list->form;
    while (current->next != NULL)
    {
        current = current->next;
    }
    ListNode *newnode = malloc(sizeof(ListNode));
    newnode->data = data;
    newnode->previous = current;
    current->next = newnode;
    newnode->next = NULL;
    list->lenght++;

    return list;
}
/*
Get all shape in the list
*/

void getList(List *list)
{
    ListNode *current = list->form;
    for (int i = 0; i < list->lenght; i++)
    {
    switch (current->data->type)
    {
    case RECTANGLE:
        getRectangle(current->data);
        break;
    case SQUARE:
        getSquare(current->data);
        break;
    case LINE:
        getLine(current->data);
        break;
    case CIRCLE:
        getCircle(current->data);
        break;
    case ELLIPSE:
        getEllipse(current->data);
        break;
    case POLYGONE:
        ListNodePoly *currentPoly = current->data->shape.poly->list;
        getShape(currentPoly,current->data->type);
        break;
    case STRLINE:
        ListNodePoly *currentLineStr = current->data->shape.poly->list;
        getShape(currentLineStr,current->data->type);
        break;
    case PATH:
        ListNodePath *currentPath = current->data->shape.path->list;
        getPath(currentPath);
        break;
    case GROUP :
        break;
    default:
        printf("Unknown shape type\n");
        break;
    }
    current = current->next;
    }
}
