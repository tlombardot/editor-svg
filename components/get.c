

void getRectangle(Shape* rectangle){
    printf("/+--| Rectangle |--+/\n");
    printf("Position (x : %d, y : %d)\n",rectangle->rect.x,rectangle->rect.y);
    printf("Width : %d \n",rectangle->rect.width);
    printf("Height : %d \n",rectangle->rect.height);
}

void getSquare(Shape* square){
    printf("/+--| Square |--+/\n");
    printf("Position (x : %d, y : %d)\n",square->squ.x,square->squ.y);
    printf("Weight & Height : %d \n",square->squ.wh);
}

void getEllipse(Shape* ellipse){
    printf("/+--| Ellipse |--+/\n");
    printf("Position (x : %d, y : %d)\n",ellipse->elli.cx,ellipse->elli.cy);
    printf("Rayon : %d (x) & Rayon : %d (y)\n",ellipse->elli.rx, ellipse->elli.ry);
}

void getCircle(Shape* circle){
    printf("/+--| Circle |--+/\n");
    printf("Position (x : %d, y : %d)\n",circle->circle.cx,circle->circle.cy);
    printf("Rayon : %d \n",circle->circle.r);
}
