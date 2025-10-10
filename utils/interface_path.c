
#include "../config/struct.h"
#include <inttypes.h>
#include <stdio.h>
#include "../components/get.h"
#include "../config/path.h"

int getAnswerPath(){
    printf("What do you wan to do ?\n 1 - Move(M)\n Answer : ");
    int answer = getInt();
    return answer;
}

Data *interfacePath(Data *path){
    int answer = 1;
    ListNodePath *current = path->shape.path->list;
    while (answer != 0) {
        printf("--- Menu Path ---\n 1 - Move\n 2 - Line\n 3 - Horizontal\n 4 - Vertical\n 5 - Curve\n 9 - Close the path\n\n Answer : ");
        answer = getInt();
        if (answer == 9){
            break;
        }
        switch (answer) {
            case 1:
                current = movePath(current);
                path->shape.path->lenght ++;
                current = current->next;
                break;
            case 2:
                current = linePath(current);
                path->shape.path->lenght ++;
                current = current->next;
                break;
            case 3:
                current = horizontalPath(current);
                path->shape.path->lenght ++;
                current = current->next;
                break;
            case 4:
                current = verticalPath(current);
                path->shape.path->lenght ++;
                current = current->next;
                break;
            case 5:
                current = curvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 6:
                current = ShortCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 7:
                current = QuadraticCurvePath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            case 8:
                current = ShortQuadraticPath(current);
                path->shape.path->lenght++;
                current = current->next;
                break;
            default:
                break;
        }
    }
    return path;
}
