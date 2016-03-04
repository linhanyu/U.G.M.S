// BigPa

#ifndef UGMS_FILE_H
#define UGMS_FILE_H

#endif //UGMS_FILE_H

#include <stdio.h>
#include "dlink.h"
#include "structs.h"

int savePlayer(void* linkedList);

int saveItem(void* linkedList);

int loadPlayer(void* linkedList);

int loadItem(void* linkedList);
