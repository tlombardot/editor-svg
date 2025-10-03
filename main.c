#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "config/struct.c"
#include "components/create.c"
#include "components/get.c"



int main(void){
    Shape *rectangle;
    rectangle = createRectangle();
    getRectangle(rectangle);
    freeRectangle(rectangle);
    return EXIT_SUCCESS;
    
}


