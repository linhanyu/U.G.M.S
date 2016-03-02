// DoubleLinkedList -- dlink.c
// BigPa

#include <stdio.h>
#include <stdlib.h>
//#ifdef __APPLE__
//#else
//#endif
#include "dlink.h"

// declare node with two pointers
typedef struct tagOfNode {
    struct tagOfNode *prev;
    struct tagOfNode *next;
    void *p;
} node;

static node *head = NULL;

// number of nodes
static int count = 0;

static node* createNode(void *pval) {
    // create temp node
    node *tnode = NULL;
    tnode = (node *)malloc(sizeof(node));
    if (!tnode) {
        printf("Node creation error\n");
        return NULL;
    }
    // point to itself
    tnode -> prev = tnode -> next = tnode;
    tnode -> p = pval;
    return tnode;
}

int createDLink() {
    head = createNode(NULL);
    if (!head) {
        return -1;
    }
    count = 0;
    return 0;
}

int dLinkIsEmpty() {
    return count == 0;
}


int dLinkSize() {
    return count;
}


static node* getNode(int index) {
    if (index < 0 || index >= count) {
        printf("index is out of range\n");
        return NULL;
    }

    // check one by one from closer side
    if (index < count / 2) {
        int i = 0;
        node *tnode = head -> next;
        while (i++ < index) {
            tnode = tnode -> next;
        }
        return tnode;
    }
    else {
        int i = 0;
        int rIndex = count - index;
        node *tnode = head -> next;
        while (++i < rIndex) {
            tnode = tnode->next;
        }
        return tnode;
    }
}

static node* getFirstNode() {
    return getNode(0);
}

static node* getLastNode() {
    return getNode(count - 1);
}

void* getNodeContent(int index) {
    node *tnode = getNode(index);
    if (!tnode) {
        printf("Get Node content failed\n");
        return NULL;
    }
    return tnode -> p;
}

void* getContentOfFirstNode() {
    return getNodeContent(0);
}

void* getContentOfLastNode() {
    return getNodeContent(count - 1);
}

int insertNodeAtFirst(void* pval) {
    node *nnode = createNode(pval);
    if (!nnode) {
        return -1;
    }
    
    nnode -> prev = head;
    nnode -> next = head -> next;
    head -> next -> prev = nnode;
    head -> next = nnode;
    count++;
    
    return 0;
}

int insertNodeAtLast(void* pval) {
    node *nnode = createNode(pval);
    if (!nnode) {
        return -1;
    }
    
    nnode -> next = head;
    nnode -> prev = head -> prev;
    head -> prev -> next = nnode;
    head -> prev = nnode;
    ++count;
    
    return 0;
}

int insertNode(int index, void* pval) {
    if (index == 0) {
        return insertNodeAtFirst(pval);
    }
    else {
        node *tnode = getNode(index);
        if (!tnode) {
            return -1;
        }
        node *nnode = createNode(pval);
        if (!nnode) {
            return -1;
        }
        
        nnode -> prev = tnode -> prev;
        nnode -> next = tnode;
        tnode -> prev -> next = nnode;
        tnode -> prev = nnode;
        
        ++count;
        
        return 0;
    }
}

