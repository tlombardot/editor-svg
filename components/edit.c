#include "get.h"
#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils/windows_user.h"
#include "../config/color.h"

void editX(Data * data){
    switch (data->type) {
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.rect.x = getInt(0,600);
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.circle.cx = getInt(0,600);
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.elli.cx = getInt(0,600);
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.line.x1 = getInt(0,600);
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.squ.x = getInt(0,600);
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editY(Data * data){
    switch (data->type) {
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.rect.y = getInt(0,300);
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.squ.y = getInt(0,300);
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.circle.cy = getInt(0,300);
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.elli.cy = getInt(0,300);
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.line.y1 = getInt(0,300);
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editAngle(Data *data){
    switch (data->type) {
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.rect.style.angle = getInt(0,360);
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.squ.style.angle = getInt(0,360);
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.circle.style.angle = getInt(0,360);
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.elli.style.angle = getInt(0,360);
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.line.style.angle = getInt(0,360);
            break;
        case POLYGONE:
            data->shape.poly->style.angle = getInt(0,360);
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editFill(Data *data){
    switch (data->type) {
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.rect.style.RF = getInt(0,255);
            data->shape.rect.style.GF = getInt(0,255);
            data->shape.rect.style.BF = getInt(0,255);
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.squ.style.RF = getInt(0,255);
            data->shape.squ.style.GF = getInt(0,255);
            data->shape.squ.style.BF = getInt(0,255);
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.circle.style.RF = getInt(0,255);
            data->shape.circle.style.GF = getInt(0,255);
            data->shape.circle.style.BF = getInt(0,255);
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.elli.style.RF = getInt(0,255);
            data->shape.elli.style.GF = getInt(0,255);
            data->shape.elli.style.BF = getInt(0,255);
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.line.style.RF = getInt(0,255);
            data->shape.line.style.GF = getInt(0,255);
            data->shape.line.style.BF = getInt(0,255);
            break;
        case POLYGONE:
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.poly->style.RF = getInt(0,255);
            data->shape.poly->style.GF = getInt(0,255);
            data->shape.poly->style.BF = getInt(0,255);
            break;
        case STRLINE:
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.poly->style.RF = getInt(0,255);
            data->shape.poly->style.GF = getInt(0,255);
            data->shape.poly->style.BF = getInt(0,255);
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editStroke(Data *data){
    switch (data->type) {
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.rect.style.RS = getInt(0,255);
            data->shape.rect.style.GS = getInt(0,255);
            data->shape.rect.style.BS = getInt(0,255);
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.squ.style.RS = getInt(0,255);
            data->shape.squ.style.GS = getInt(0,255);
            data->shape.squ.style.BS = getInt(0,255);
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.circle.style.RS = getInt(0,255);
            data->shape.circle.style.GS = getInt(0,255);
            data->shape.circle.style.BS = getInt(0,255);
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.elli.style.RS = getInt(0,255);
            data->shape.elli.style.GS = getInt(0,255);
            data->shape.elli.style.BS = getInt(0,255);
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.line.style.RS = getInt(0,255);
            data->shape.line.style.GS = getInt(0,255);
            data->shape.line.style.BS = getInt(0,255);
            break;
        case POLYGONE:
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.poly->style.RS = getInt(0,255);
            data->shape.poly->style.GS = getInt(0,255);
            data->shape.poly->style.BS = getInt(0,255);
            break;
        default:
            printf("Invalid type");
            break;
    }
}

void editTranslate(Data *data){
    switch(data->type){
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.circle.style.translate.x = getInt(0,200);
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.circle.style.translate.y = getInt(0,100);
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.elli.style.translate.x = getInt(0,200);
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.elli.style.translate.y = getInt(0,100);
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.line.style.translate.x = getInt(0,200);
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.line.style.translate.y = getInt(0,100);
            break;
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.rect.style.translate.x = getInt(0,200);
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.rect.style.translate.y = getInt(0,100);
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.squ.style.translate.x = getInt(0,200);
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.squ.style.translate.y = getInt(0,100);
            break;
        case POLYGONE:
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.poly->style.translate.x = getInt(0,200);
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.poly->style.translate.y = getInt(0,100);
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
        system("clear");
        printf("\n");
        printf(YELLOW"             █▀▀ █▀▄ █ ▀█▀\n");
        printf("             ██▄ █▄▀ █ ░█░\n");
        printf("\n");
        HeaderLine();
        printf("\n");
        printf( YELLOW"(1).....................Edit X coordinate\n"RESET);
        printf( YELLOW"(2).....................Edit Y coordinate\n"RESET);
        printf( YELLOW"(3).....................Change fill color\n"RESET);
        printf( YELLOW"(4)...................Adjust stroke style\n"RESET);
        printf( YELLOW"(5)....................Modify translation\n"RESET);
        printf( YELLOW"(6)....................Set rotation angle\n"RESET);
        printf( MAGENTA"(0).....................Back to main menu\n\n"RESET);
        HeaderLine();
        printf(YELLOW "\nINPUT> " RESET);
        answer = getInt(0, 6);
        system("clear");
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
            case 0:
                printf("Returning to main menu...\n");
                return;
            default:
                printf("Invalid option");
                break;
        }
    }
};
