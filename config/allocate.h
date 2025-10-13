#ifndef SET_H
#define  SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"

Data *allocateMemory();
Data *allocateMemoryPoly();
Data *allocateMemoryPath();
Data *allocateMemoryGroup();

#endif
