// DoubleLinkedList -- dlink.h
// BigPa

#ifndef UGMS_DLINK_H
#define UGMS_DLINK_H

#endif //UGMS_DLINK_H

#include <stdio.h>
#include <stdlib.h>

extern int createDLink();

extern int destoryDLink();

extern int dLinkIsEmpty();

extern int dLinkSize();

extern void* getContentOfNode(int index);

void * getContentOfFirstNode();

void * getContentOfLastNode();

int insertNode(int index, void* pval);

int insertNodeAtFirst(void* pval);

int insertNodeAtLast(void* pval);

int deleteNodeAtFirst();

int deleteNodeAtLast();

