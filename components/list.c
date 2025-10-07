

#ifndef CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"

#endif

/*
Créer une liste vide et initialisé
*/
List *createList(void)
{
    List *ListShape = malloc(sizeof(List));
    ListShape->form = malloc(sizeof(ListNode));
    ListShape->form->shape = malloc(sizeof(Shape));
    ListShape->lenght = 0;
    return ListShape;
}

/*
Ajout n'importe quel forme dans la liste
*/
List *appendList(List *list, Shape *shape)
{
    if (list->lenght == 0)
    {
        list->form->shape = shape;
        list->lenght++;
        return list;
    }
    ListNode *current = list->form;
    while (current->next != NULL)
    {
        current = current->next;
    }
    ListNode *newnode = malloc(sizeof(ListNode));
    newnode->shape = shape;
    newnode->previous = current;
    current->next = newnode;
    list->lenght++;

    return list;
}
/*
Récupère tout les infos de la liste
*/

void getList(List *list)
{
    ListNode *current = list->form;
    for (int i = 0; i < list->lenght; i++)
    {
    switch (current->shape->type)
    {
    case RECTANGLE:
        printf("/+--| Rectangle |--+/\n");
        printf("Position (x : %d, y : %d)\n", current->shape->rect.x, current->shape->rect.y);
        printf("Width : %d \n", current->shape->rect.width);
        printf("Height : %d \n", current->shape->rect.height);
        current = current->next;
        break;
    case SQUARE:
        printf("/+--| Square |--+/\n");
        printf("Position (x : %d, y : %d)\n", current->shape->squ.x, current->shape->squ.y);
        printf("Weight & Height : %d \n", current->shape->squ.wh);
        break;
    case LINE:

        break;
    case CIRCLE:
        printf("/+--| Circle |--+/\n");
        printf("Position (x : %d, y : %d)\n", current->shape->circle.cx, current->shape->circle.cy);
        printf("Rayon : %d \n", current->shape->circle.r);
        break;
    case ELLIPSE:
        printf("/+--| Ellipse |--+/\n");
        printf("Position (x : %d, y : %d)\n", current->shape->elli.cx, current->shape->elli.cy);
        printf("Rayon : %d (x) & Rayon : %d (y)\n", current->shape->elli.rx, current->shape->elli.ry);
        break;
    case POLYGONE:

        break;

    case PATH:

        break;
    default:
        break;
    }
    }
}
