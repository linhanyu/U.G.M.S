// DoubleLinkedList -- dlink.h
// BigPa

#include "dlink.c"

#ifndef UGMS_DLINK_H
#define UGMS_DLINK_H

#endif //UGMS_DLINK_H

extern node* createNode(void *pval);

extern int createDlink();

int dLinkIsEmpty();

int dLinkSize();

static node * getNode(int index);
