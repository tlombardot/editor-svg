

#include "get.h"
#include <stdio.h>
#include <stdlib.h>
#include "../config/struct.h"


/*
Create List NULL
*/
List *createList(void)
{
    List *ListShape = malloc(sizeof(List));
    ListShape->form = malloc(sizeof(ListNode));
    ListShape->form->data = malloc(sizeof(Data));
    ListShape->form->next = NULL;
    ListShape->form->previous = NULL;
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
        list->form->next = NULL;
        list->form->previous = NULL;
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
    if(list->lenght == 0)
    {
        printf("No shape in the list\n");
        return;
    }
    ListNode *current = list->form;
    for (int i = 0; i < list->lenght; i++)
    {
    switch (current->data->type)
    {
    case RECTANGLE:
        getRectangle(current->data, i);
        break;
    case SQUARE:
        getSquare(current->data, i);
        break;
    case LINE:
        getLine(current->data, i);
        break;
    case CIRCLE:
        getCircle(current->data, i);
        break;
    case ELLIPSE:
        getEllipse(current->data, i);
        break;
    case POLYGONE:
        ListPoly *currentPoly = current->data->shape.poly;
        getShape(currentPoly,current->data->type, i);
        break;
    case STRLINE:
        ListPoly *currentLineStr = current->data->shape.poly;
        getShape(currentLineStr,current->data->type, i);
        break;
    case PATH:
        ListPath *currentPath = current->data->shape.path;
        getPath(currentPath, i);
        break;
    case GROUP :
            Group *group = current->data->shape.group;
            getGroup(group, group->depth);
        break;
    default:
        printf("Unknown shape type\n");
        break;
    }
    current = current->next;
    }
}


void freeList(List *list)
{
    ListNode *current = list->form;
    ListNode *next;
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}
