#ifndef WINDOWS_USER
#define WINDOWS_USER

#include "../components/list.h"
/*
 Main Interface
*/
List *userInterface();
void createInterface(List *list);
int getAnswer();
void sleep_ms(int milliseconds);
void HeaderLine();


#endif
