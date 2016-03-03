// DoubleLinkedList -- dlink.h
// BigPa

#ifndef UGMS_DLINK_H
#define UGMS_DLINK_H

#endif //UGMS_DLINK_H

#include <stdio.h>
#include <stdlib.h>

// create DoubleLinkedList
extern int createDLink();

// destory DoubleLinkedList
extern int destoryDLink();

// return 1 if DoubleLinkedList is empty INCLUDING header node
extern int dLinkIsEmpty();

extern int dLinkSize();

extern void* getContentOfNode(int index);

void* getContentOfFirstNode();

void* getContentOfLastNode();

int insertNode(int index, void* content);

int insertNodeAtFirst(void* content);

int insertNodeAtLast(void* content);

int deleteNode(int index);

int deleteNodeAtFirst();

int deleteNodeAtLast();

