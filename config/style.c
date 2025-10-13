
#include "../config/struct.h"
#include "../components/get.h"
#include <stdio.h>

Style createFillStyle(Style *style){
    printf("Enter RED Color (RGB Fill)\n");
    style->RF = getInt();
    printf("Enter Green Color (RGB Fill)\n");
    style->GF = getInt();
    printf("Enter Blue Color (RGB Fill)\n");
    style->BF = getInt();
    return *style;
}

Style createAngleStyle(Style *style){
    printf("Enter Angle of the Shape");
    style->angle = getInt();
    return *style;
}

Style createStrokeStyle(Style *style){
    printf("Enter RED Color (RGB Stroke)\n");
    style->RS = getInt();
    printf("Enter Green Color (RGB Stroke)\n");
    style->GS = getInt();
    printf("Enter Blue Color (RGB Stroke)\n");
    style->BS = getInt();
    return *style;
}
