// DoubleLinkedList -- dlink.h
// BigPa

#ifndef UGMS_DLINK_H
#define UGMS_DLINK_H

#endif //UGMS_DLINK_H

#include <stdlib.h>

// DO NOT TOUCH THIS
typedef struct tagOfNode {
    struct tagOfNode* prev;
    struct tagOfNode* next;
    void* content;
} node;

typedef struct tagOfDLink {
    char* name;
    int count;
    node* list;
} Dlink;

// create DoubleLinkedList with a name
void* createDLink(char* name);

// destory DoubleLinkedList
int destoryDLink(Dlink* name);

// return 1 if DoubleLinkedList is empty INCLUDING header node
extern int dLinkIsEmpty(Dlink* name);

extern int dLinkSize(Dlink* pointer);

extern void* getContentOfNode(Dlink* name, int index);

void* getContentOfFirstNode(Dlink* name);

void* getContentOfLastNode(Dlink* name);

int insertNode(Dlink* name, int index, void* content);

int insertNodeAtFirst(Dlink* name, void* content);

int insertNodeAtLast(Dlink* name, void* content);

int deleteNode(Dlink* name, int index);

int deleteNodeAtFirst(Dlink* name);

int deleteNodeAtLast(Dlink* name);
