

#include "struct.h"
#include "../components/get.h"
#include <stdlib.h>


ListNodePath *movePath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.mv.x = getXCoord();
    newNodePath->path->order.mv.y = getYCoord();
    newNodePath->path->orderType = 'M';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *linePath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.lp.x = getXCoord();
    newNodePath->path->order.lp.y = getYCoord();
    newNodePath->path->orderType = 'L';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *horizontalPath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.h.x = getXCoord();
    newNodePath->path->orderType = 'H';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *verticalPath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.v.y = getYCoord();
    newNodePath->path->orderType = 'V';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *curvePath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.c.x1 = getXCoord();
    newNodePath->path->order.c.y1 = getYCoord();
    newNodePath->path->order.c.x2 = getXCoord();
    newNodePath->path->order.c.y2 = getYCoord();
    newNodePath->path->order.c.x3 = getXCoord();
    newNodePath->path->order.c.y3 = getYCoord();
    newNodePath->path->orderType = 'C';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *ShortCurvePath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.sc.x1 = getXCoord();
    newNodePath->path->order.sc.y1 = getYCoord();
    newNodePath->path->order.sc.x2 = getXCoord();
    newNodePath->path->order.sc.y2 = getYCoord();
    newNodePath->path->orderType = 'S';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *QuadraticCurvePath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.qc.x1 = getXCoord();
    newNodePath->path->order.qc.y1 = getYCoord();
    newNodePath->path->order.qc.x2 = getXCoord();
    newNodePath->path->order.qc.y2 = getYCoord();
    newNodePath->path->orderType = 'Q';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}

ListNodePath *ShortQuadraticPath(ListNodePath *path){
    ListNodePath *newNodePath = malloc(sizeof(ListNodePath));
    newNodePath->path = malloc(sizeof(Path));
    newNodePath->path->order.sq.x = getXCoord();
    newNodePath->path->order.sq.y = getYCoord();
    newNodePath->path->orderType = 'T';
    newNodePath->previous = path;
    path->next = newNodePath;
    return  path;
}
