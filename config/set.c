
#include "struct.h"
#include <stdbool.h>
#include <stdlib.h>


Data *setMalloc(){
    Data *new_shape = malloc(sizeof(Data));
    new_shape->shape = malloc(sizeof(Shape));
    return new_shape;
}
