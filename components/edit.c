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
            data->shape.rect.x = getInt();
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.circle.cx = getInt();
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.elli.cx = getInt();
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.line.x1 = getInt();
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"\nEnter the new X coordinate: \n");
            data->shape.squ.x = getInt();
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
            data->shape.rect.y = getInt();
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.squ.y = getInt();
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.circle.cy = getInt();
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.elli.cy = getInt();
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"\nEnter the new Y coordinate: \n");
            data->shape.line.y1 = getInt();
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
            data->shape.rect.style.angle = getInt();
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.squ.style.angle = getInt();
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.circle.style.angle = getInt();
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.elli.style.angle = getInt();
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"\nEnter the new angle: \n");
            data->shape.line.style.angle = getInt();
            break;
        case POLYGONE:
            data->shape.poly->style.angle = getInt();
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
            data->shape.rect.style.RF = getInt();
            data->shape.rect.style.GF = getInt();
            data->shape.rect.style.BF = getInt();
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.squ.style.RF = getInt();
            data->shape.squ.style.GF = getInt();
            data->shape.squ.style.BF = getInt();
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.circle.style.RF = getInt();
            data->shape.circle.style.GF = getInt();
            data->shape.circle.style.BF = getInt();
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.elli.style.RF = getInt();
            data->shape.elli.style.GF = getInt();
            data->shape.elli.style.BF = getInt();
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.line.style.RF = getInt();
            data->shape.line.style.GF = getInt();
            data->shape.line.style.BF = getInt();
            break;
        case POLYGONE:
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.poly->style.RF = getInt();
            data->shape.poly->style.GF = getInt();
            data->shape.poly->style.BF = getInt();
            break;
        case STRLINE:
            printf(BOLD CYAN"Enter the new fill color: \n");
            data->shape.poly->style.RF = getInt();
            data->shape.poly->style.GF = getInt();
            data->shape.poly->style.BF = getInt();
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
            data->shape.rect.style.RS = getInt();
            data->shape.rect.style.GS = getInt();
            data->shape.rect.style.BS = getInt();
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.squ.style.RS = getInt();
            data->shape.squ.style.GS = getInt();
            data->shape.squ.style.BS = getInt();
            break;
        case CIRCLE:
            getCircle(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.circle.style.RS = getInt();
            data->shape.circle.style.GS = getInt();
            data->shape.circle.style.BS = getInt();
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.elli.style.RS = getInt();
            data->shape.elli.style.GS = getInt();
            data->shape.elli.style.BS = getInt();
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.line.style.RS = getInt();
            data->shape.line.style.GS = getInt();
            data->shape.line.style.BS = getInt();
            break;
        case POLYGONE:
            printf(BOLD CYAN"Enter the new stroke color: \n");
            data->shape.poly->style.RS = getInt();
            data->shape.poly->style.GS = getInt();
            data->shape.poly->style.BS = getInt();
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
            data->shape.circle.style.translate.x = getInt();
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.circle.style.translate.y = getInt();
            break;
        case ELLIPSE:
            getEllipse(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.elli.style.translate.x = getInt();
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.elli.style.translate.y = getInt();
            break;
        case LINE:
            getLine(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.line.style.translate.x = getInt();
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.line.style.translate.y = getInt();
            break;
        case RECTANGLE:
            getRectangle(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.rect.style.translate.x = getInt();
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.rect.style.translate.y = getInt();
            break;
        case SQUARE:
            getSquare(data, 0);
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.squ.style.translate.x = getInt();
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.squ.style.translate.y = getInt();
            break;
        case POLYGONE:
            printf(BOLD CYAN"Enter the new x coordinate: ");
            data->shape.poly->style.translate.x = getInt();
            printf(BOLD CYAN"Enter the new y coordinate: ");
            data->shape.poly->style.translate.y = getInt();
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
        HeaderLine();
        printf("\n");
        slowPrint( BOLD CYAN"       ██████ EDIT INTERFACE ██████      \n", 3);
        printf("\n");
        slowPrint(BOLD YELLOW"[1]" MAGENTA" Edit X coordinate\n"RESET, 3);
        slowPrint(BOLD YELLOW"[2]" MAGENTA" Edit Y coordinate\n"RESET, 3);
        slowPrint(BOLD YELLOW"[3]" MAGENTA" Change fill color\n"RESET, 3);
        slowPrint(BOLD YELLOW"[4]" MAGENTA" Adjust stroke style\n"RESET, 3);
        slowPrint(BOLD YELLOW"[5]" MAGENTA" Modify translation\n"RESET, 3);
        slowPrint(BOLD YELLOW"[6]" MAGENTA" Set rotation angle\n"RESET, 3);
        slowPrint(BOLD YELLOW"[0]" MAGENTA" Back to main menu\n"RESET, 3);
        HeaderLine();
        printf(BOLD CYAN "INPUT> " RESET);
        answer = getInt();
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
