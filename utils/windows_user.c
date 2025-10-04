int getAnswer(){
    int answer;
    while ((answer <= 0) || (answer > 6))
    {
        printf("What do you want to do ?\n 1 - Create a SVG\n 2 - Edit a SVG\n 3 - Remove a SVG\n 4 - Export SVG\n 5 - Import SVG\n 6 - Quit\nAnswer : ");
        scanf("%d",&answer);
        if ((answer <= 0) || (answer > 6)){
            printf("Error!\n");
        }
    }
    return answer;
}

void userInterface(){
    int answer = getAnswer();
    while (answer != 6){
    printf("Welcome !\n");
    switch (answer)
    {
    case 1:
        printf("What do you want to create ?\n 1 - Rectangle\n 2 - Square\n 3 - Line\n 4 - Circle\n 5 - Ellipse\nAnswer : ");
        scanf("%d", &answer);
        switch (answer)
        {
        case 1:
            Shape* rectangle = createRectangle();
            getRectangle(rectangle);
            break;
        case 2:
            Shape* square = createSquare();
            getSquare(square);
            break;
        
        default:
            break;
        }
    break;
    
    default:
        break;
    }
    answer = getAnswer();
}
return;
    
}