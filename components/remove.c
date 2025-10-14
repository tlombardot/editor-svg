
#include <stdio.h>
#include <stdlib.h>
#include "create.h"
#include "list.h"
#include "../config/struct.h"


List* removeShape(List *list, int id) {
    if (list == NULL || list->form == NULL) {
            printf("List is empty.\n");
            return list;
        }

    ListNode *current = list->form;
    if (id == 0) {
        switch (list->form->data->type) {
            case RECTANGLE:
                freeRectangle(current->data);
                break;
            case CIRCLE:
                freeCircle(current->data);
                break;
            case LINE:
                freeLine(current->data);
                break;
            case SQUARE:
                freeSquare(current->data);
                break;
            case ELLIPSE:
                freeEllipse(current->data);
                break;
            case POLYGONE:
                freeShapeless(current->data);
                break;
            case STRLINE:
                freeShapeless(current->data);
                break;
            case PATH:
                freePath(current->data);
                break;
            default:
                printf("Invalid shape type.\n");
                break;
        }
                list->form = current->next;
                list->lenght--;

                if (list->lenght == 0){
                    list = createList();
                }
                return list;
    }
    // 🔹 Sinon, parcours jusqu’à l’élément à supprimer
        for (int i = 0; i < id; i++) {
            current = current->next;
        }

        // 🔹 Libère la data selon le type
        switch (current->data->type) {
            case RECTANGLE:
                freeRectangle(current->data);
                break;
            case CIRCLE:
                freeCircle(current->data);
                break;
            case LINE:
                freeLine(current->data);
                break;
            case SQUARE:
                freeSquare(current->data);
                break;
            case ELLIPSE:
                freeEllipse(current->data);
                break;
            case POLYGONE:
                freeShapeless(current->data);
                break;
            case STRLINE:
                freeShapeless(current->data);
                break;
            case PATH:
                freePath(current->data);
                break;
            default:
                printf("Invalid shape type.\n");
                break;
        }

        // 🔹 Reconnecte les voisins
        if (current->previous)
            current->previous->next = current->next;

        if (current->next)
            current->next->previous = current->previous;

        free(current);
        list->lenght--;

        if (list->lenght == 0)
            list->form = NULL;

        printf("✅ Shape #%d removed successfully.\n", id);
        return list;
}
