#ifndef WINDOWS_USER
#define WINDOWS_USER

#include "../components/list.h"

List *userInterface();
void createInterface(List *list);
int getAnswer();
void sleep_ms(int milliseconds);
void slowPrint(const char *text, int delay_ms);
void HeaderLine();
#endif
