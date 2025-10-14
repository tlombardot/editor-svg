#include "get.h"
#include "list.h"
#include <stdbool.h>
#include <stdio.h>

void editX(Data * data){
    printf("Enter the new X coordinate: \n");
    switch (data->type) {
        case RECTANGLE:
            data->shape.rect.x = getInt();
            break;
        case CIRCLE:
            data->shape.circle.cx = getInt();
            break;
        case ELLIPSE:
            data->shape.elli.cx = getInt();
            break;
        case LINE:
            data->shape.line.x1 = getInt();
            break;
        case SQUARE:
            data->shape.squ.x = getInt();
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editY(Data * data){
    printf("Enter the new Y coordinate: \n");
    switch (data->type) {
        case RECTANGLE:
            data->shape.rect.y = getInt();
            break;
        case SQUARE:
            data->shape.squ.y = getInt();
            break;
        case CIRCLE:
            data->shape.circle.cy = getInt();
            break;
        case ELLIPSE:
            data->shape.elli.cy = getInt();
            break;
        case LINE:
            data->shape.line.y1 = getInt();
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editAngle(Data *data){
    printf("Enter the new angle: \n");
    switch (data->type) {
        case RECTANGLE:
            data->shape.rect.style.angle = getInt();
            break;
        case SQUARE:
            data->shape.squ.style.angle = getInt();
            break;
        case CIRCLE:
            data->shape.circle.style.angle = getInt();
            break;
        case ELLIPSE:
            data->shape.elli.style.angle = getInt();
            break;
        case LINE:
            data->shape.line.style.angle = getInt();
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editFill(Data *data){
    printf("Enter the new fill color: \n");
    switch (data->type) {
        case RECTANGLE:
            data->shape.rect.style.RF = getInt();
            data->shape.rect.style.GF = getInt();
            data->shape.rect.style.BF = getInt();
            break;
        case SQUARE:
            data->shape.squ.style.RF = getInt();
            data->shape.squ.style.GF = getInt();
            data->shape.squ.style.BF = getInt();
            break;
        case CIRCLE:
            data->shape.circle.style.RF = getInt();
            data->shape.circle.style.GF = getInt();
            data->shape.circle.style.BF = getInt();
            break;
        case ELLIPSE:
            data->shape.elli.style.RF = getInt();
            data->shape.elli.style.GF = getInt();
            data->shape.elli.style.BF = getInt();
            break;
        case LINE:
            data->shape.line.style.RF = getInt();
            data->shape.line.style.GF = getInt();
            data->shape.line.style.BF = getInt();
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editStroke(Data *data){
    printf("Enter the new stroke color: \n");
    switch (data->type) {
        case RECTANGLE:
            data->shape.rect.style.RS = getInt();
            data->shape.rect.style.GS = getInt();
            data->shape.rect.style.BS = getInt();
            break;
        case SQUARE:
            data->shape.squ.style.RS = getInt();
            data->shape.squ.style.GS = getInt();
            data->shape.squ.style.BS = getInt();
            break;
        case CIRCLE:
            data->shape.circle.style.RS = getInt();
            data->shape.circle.style.GS = getInt();
            data->shape.circle.style.BS = getInt();
            break;
        case ELLIPSE:
            data->shape.elli.style.RS = getInt();
            data->shape.elli.style.GS = getInt();
            data->shape.elli.style.BS = getInt();
            break;
        case LINE:
            data->shape.line.style.RS = getInt();
            data->shape.line.style.GS = getInt();
            data->shape.line.style.BS = getInt();
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editTranslate(Data *data){
    switch(data->type){
        case CIRCLE:
            printf("Enter the new x coordinate: ");
            data->shape.circle.style.translate.x = getInt();
            printf("Enter the new y coordinate: ");
            data->shape.circle.style.translate.y = getInt();
            break;
        case ELLIPSE:
            printf("Enter the new x coordinate: ");
            data->shape.elli.style.translate.x = getInt();
            printf("Enter the new y coordinate: ");
            data->shape.elli.style.translate.y = getInt();
            break;
        case LINE:
            printf("Enter the new x coordinate: ");
            data->shape.line.style.translate.x = getInt();
            printf("Enter the new y coordinate: ");
            data->shape.line.style.translate.y = getInt();
            break;
        case RECTANGLE:
            printf("Enter the new x coordinate: ");
            data->shape.rect.style.translate.x = getInt();
            printf("Enter the new y coordinate: ");
            data->shape.rect.style.translate.y = getInt();
            break;
        case SQUARE:
            printf("Enter the new x coordinate: ");
            data->shape.squ.style.translate.x = getInt();
            printf("Enter the new y coordinate: ");
            data->shape.squ.style.translate.y = getInt();
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editShape(List *ListShape, int index){
    // Edit the shape properties
    int answer = 0;
    ListNode *current = ListShape->form;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    while(true){
        printf("What do you want to edit\n 1 - X\n 2 - Y\n 3 - Fill\n 4 - Stroke\n 5 - Translate\n 6 - Angle\n 7 - Return to main menu\n ");
        answer = getInt();
        switch (answer) {
            case 1:
                editX(current->data);
                break;
            case 2:
                editY(current->data);
                break;
            case 3:
                editFill(current->data);
                break;
            case 4:
                editStroke(current->data);
                break;
            case 5:
                editTranslate(current->data);
                break;
            case 6:
                editAngle(current->data);
                break;
            case 7:
                printf("Returning to main menu...\n");
                return;
            default:
                printf("Invalid option");
                break;
        }
    }
};
