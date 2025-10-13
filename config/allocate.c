
#include "struct.h"
#include <stdbool.h>
#include <stdlib.h>


Data *allocateMemory(){
    Data *new_shape = malloc(sizeof(Data));
    return new_shape;
}

Data *allocateMemoryPoly(){
    Data *new_shape = malloc(sizeof(Data));
    new_shape->shape.poly = malloc(sizeof(ListPoly));
    new_shape->shape.poly->list = malloc(sizeof(ListNodePoly));
    return new_shape;
}

Data *allocateMemoryPath(){
    Data *new_shape = malloc(sizeof(Data));
    new_shape->shape.path = malloc(sizeof(ListPath));
    new_shape->shape.path->list = malloc(sizeof(ListNodePath));
    new_shape->shape.path->list->path = malloc(sizeof(Path));
    return new_shape;
}

Data *allocateMemoryGroup(){
    Data *new_group = malloc(sizeof(Data));
    new_group->shape.group = malloc(sizeof(Group));
    return new_group;
}
