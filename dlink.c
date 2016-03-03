// DoubleLinkedList -- dlink.c
// BigPa

#include "dlink.h"

// declare node with two pointers
typedef struct tagOfNode {
    struct tagOfNode* prev;
    struct tagOfNode* next;
    void* content;
} node;

// head node
static node* head = NULL;

// number of nodes
static int count = 0;

static node* createNode(void* pval) {
    // create temp node
    node* temp = NULL;
    temp = (node*) malloc(sizeof(node));
    if (!temp) {
//        printf("Node creation error\n");
        return NULL;
    }
    else {
        // point to itself
        temp->prev = temp->next = temp;
        temp->content = pval;
        return temp;
    }
}

int createDLink() {
    head = createNode(NULL);
    if (!head) {
        return -1;
    }
    else {
        count = 0;
        head->content = head;
    }
    return 0;
}

int dLinkIsEmpty() {
    return count == 0;
}

int dLinkSize() {
    return count;
}

static node* getNode(int index) {
    if (index < 0 || index > count) {
//        printf("index is out of range\n");
        return NULL;
    }

    // check one by one from closer side
    if (index <= count / 2) {
        int i = 0;
        node* temp = head; //->next;
        while (i++ < index) {
            temp = temp->next;
        }
        return temp;
    }
    else {
        // i is the steps to move
        int i = count - index + 1;
        node* temp = head; //->next;
        while (i-- != 0) {
            temp = temp->prev;
        }
        return temp;
    }
}

static node* getFirstNode() {
    return getNode(1);
}

static node* getLastNode() {
    return getNode(count);
}

void* getContentOfNode(int index) {
    node* temp = getNode(index);
    if (!temp) {
//        printf("Get Node content failed.\n");
        return NULL;
    }
    if (temp->content == NULL) {
//        printf("The Node has no content.\n");
    }
    return temp->content;
}


void* getContentOfFirstNode() {
    return getContentOfNode(1);
}


void* getContentOfLastNode() {
    return getContentOfNode(count);
}

int insertNodeAtFirst(void* content) {
    node* temp = createNode(content);
    if (!temp) {
        return -1;
    }

    temp->prev = head;
    temp->next = head->next;
    head->next->prev = temp;
    head->next = temp;
    ++count;

    return 0;
}

int insertNodeAtLast(void* content) {
    node* temp = createNode(content);
    if (!temp) {
        return -1;
    }

    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    ++count;

    return 0;
}

int deleteNode(int index) {
    node* temp = getNode(index);
    if (!temp) {
//        printf("Get node failed, index is out of range.\n");
        return -1;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    --count;

    return 0;
}

int deleteNodeAtFirst() {
    return deleteNode(1);
}

int deleteNodeAtLast() {
    return deleteNode(count);
}

int destoryDLink() {
    if (!head) {
//        printf("dLink does not exist.\n");
        return -1;
    }
    node* temp = head->next;
    // node being destoryed
    node* dest = NULL;

    while (temp != head) {
        dest = temp;
        temp = temp->next;
        free(dest);
    }

    free(head);
    head = NULL;
    count = 0;

    return 0;

}

int insertNode(int index, void* content) {
    if (index == 0) {
//        printf("Inserted After Header");
        return insertNodeAtFirst(content);
    }
    else {
        node* temp = getNode(index);
        if (!temp) {
//            printf("get node failed.\n");
            return -1;
        }
        node* nnode = createNode(content);
        if (!nnode) {
            return -1;
        }

        nnode->prev = temp->prev;
        nnode->next = temp;
        temp->prev->next = nnode;
        temp->prev = nnode;

        ++count;

        return 0;
    }
}

