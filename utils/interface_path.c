
#include "../config/struct.h"
#include <inttypes.h>
#include <stdio.h>
#include "../components/get.h"

int getAnswerPath(){
    printf("What do you wan to do ?\n 1 - Move(M)\n Answer : ");
    int answer = getInt();
    return answer;
}

Data *interfacePath(Data *path){
    int answer = 1;
    while (answer != 0) {
        printf("--- Menu Path ---");
        answer = getInt();
        switch (answer) {
            case 1:

                break;
            default:
                break;
        }
    }
    return path;
}
