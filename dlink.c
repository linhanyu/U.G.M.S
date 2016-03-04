// DoubleLinkedList -- dlink.c
// BigPa

#include "dlink.h"

node* createNode(void* content) {
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
        temp->content = content;
        return temp;
    }
}

void* createDLink(char* name) {
    Dlink* temp = NULL;
    temp = (Dlink*) malloc(sizeof(Dlink));
    if (!temp) {
        return NULL;
    }
    temp->list = createNode(NULL);
    temp->count = 0;
    temp->name = name;

    return temp;
}

int dLinkIsEmpty(Dlink* name) {
    return name->count == 0;
}

int dLinkSize(Dlink* pointer) {
    int count = pointer->count;
    return count;
}

static node* getNode(Dlink* name, int index) {
    if (index < 0 || index > name->count) {
//        printf("index is out of range\n");
        return NULL;
    }

    int count = name->count;

    // check one by one from closer side
    if (index <= count / 2) {
        int i = 0;
        node* temp = name->list; //->next;
        while (i++ < index) {
            temp = temp->next;
        }
        return temp;
    }
    else {
        // i is the steps to move
        int i = count - index + 1;
        node* temp = name->list; //->next;
        while (i-- != 0) {
            temp = temp->prev;
        }
        return temp;
    }
}

static node* getFirstNode(Dlink* name) {
    return getNode(name, 1);
}

static node* getLastNode(Dlink* name) {
    return getNode(name, name->count);
}

void* getContentOfNode(Dlink* name, int index) {
    node* temp = getNode(NULL, index);
    if (!temp) {
//        printf("Get Node content failed.\n");
        return NULL;
    }
    if (temp->content == NULL) {
//        printf("The Node has no content.\n");
    }
    return temp->content;
}


void* getContentOfFirstNode(Dlink* name) {
    return getContentOfNode(name, 1);
}


void* getContentOfLastNode(Dlink* name) {
    return getContentOfNode(name, name->count);
}

int insertNodeAtFirst(Dlink* name, void* content) {
    node* temp = createNode(content);
    if (!temp) {
        return -1;
    }

    int count = name->count;
    temp->prev = name->list->prev;
    temp->next = name->list->next;
    name->list->next->prev = temp;
    name->list->next = temp;
    ++count;
    name->count = count;

    return 0;
}

int insertNodeAtLast(Dlink* name, void* content) {
    node* temp = createNode(content);
    if (!temp) {
        return -1;
    }

    int count = name->count;
    temp->next = name->list;
    temp->prev = name->list->prev;
    name->list->prev->next = temp;
    name->list->prev = temp;
    ++count;
    name->count = count;

    return 0;
}

int deleteNode(Dlink* name, int index) {
    node* temp = getNode(name, index);
    if (!temp) {
//        printf("Get node failed, index is out of range.\n");
        return -1;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    --(name->count);

    return 0;
}

int deleteNodeAtFirst(Dlink* name) {
    return deleteNode(name, 1);
}

int deleteNodeAtLast(Dlink* name) {
    return deleteNode(NULL, name->count);
}

int destoryDLink(Dlink* name) {
    if (!name->list) {
//        printf("dLink does not exist.\n");
        return -1;
    }
    node* temp = name->list->next;
    // node being destoryed
    node* dest = NULL;

    while (temp != name->list) {
        dest = temp;
        temp = temp->next;
        free(dest);
    }

    free(name->list);
    name->list = NULL;
    name->count = 0;

    return 0;

}

int insertNode(Dlink* name, int index, void* content) {
    if (index == 0) {
//        printf("Inserted After Header");
        return insertNodeAtFirst(NULL, content);
    }
    else {
        node* temp = getNode(NULL, index);
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

        ++(name->count);

        return 0;
    }
}
