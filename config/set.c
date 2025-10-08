
#include "struct.h"
#include <stdbool.h>
#include <stdlib.h>


Data *setMalloc(){
    Data *new_shape = malloc(sizeof(Data));
    new_shape->shape = malloc(sizeof(Shape));
    return new_shape;
}

Data *setMallocPoly(){
    Data *new_shape = malloc(sizeof(Data));
    new_shape->shape = malloc(sizeof(Shape));
    new_shape->shape->poly = malloc(sizeof(ListPoly));
    new_shape->shape->poly->list->next = NULL;
    new_shape->shape->poly->list->previous = NULL;
    new_shape->shape->poly->lenght = 0;
    return new_shape;
}

Data *setMallocPath(){
    Data *new_shape = malloc(sizeof(Data));
    new_shape->shape = malloc(sizeof(Shape));
    new_shape->shape->path = malloc(sizeof(ListPath));
    new_shape->shape->path->list->next = NULL;
    new_shape->shape->path->list->previous = NULL;
    new_shape->shape->path->lenght = 0;
    return new_shape;
}
