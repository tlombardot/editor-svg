

#include "get.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../config/struct.h"


/*
Créer une liste vide et initialisé
*/
List *createList(void)
{
    List *ListShape = malloc(sizeof(List));
    ListShape->form = malloc(sizeof(ListNode));
    ListShape->form->data = malloc(sizeof(Data));
    ListShape->form->data->shape = malloc(sizeof(Shape));
    ListShape->lenght = 0;
    return ListShape;
}

/*
Ajout n'importe quel forme dans la liste
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
    newnode->data = malloc(sizeof(Data));
    newnode->data = data;
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
    switch (list->form->data->type)
    {
    case RECTANGLE:
        getRectangle(current->data);
        break;
    case SQUARE:
        getSquare(current->data);
        break;
    case LINE:

        break;
    case CIRCLE:
        getCircle(current->data);
        break;
    case ELLIPSE:
        getEllipse(current->data);
        break;
    case POLYGONE:
        ListNodePoly *currentPoly = current->data->shape->poly->list;
        while (currentPoly != NULL) {
            if (currentPoly->value == NULL) {
                fprintf(stderr, "Value is NULL\n");
            }else{
                getShape(currentPoly,current->data->type);
            }
        currentPoly = currentPoly->next;
        }
        break;
    case STRLINE:
        ListNodePoly *currentLineStr = current->data->shape->poly->list;
        while (currentLineStr != NULL) {
            if (currentLineStr->value == NULL) {
                fprintf(stderr, "Value is NULL\n");
            }else{
                getShape(currentLineStr,current->data->type);
            }
        currentPoly = currentPoly->next;
        }
        break;
    case PATH:

        break;
    case GROUP :
        break;
    default:
        break;
    }
    current = current->next;
    }
}
