#include "test.h"
#include "dlink.h"

void dLinkTest() {

    typedef struct tagOfObject {
        int id;
        char name[20];
    } object;

    object arr[] = {
            {10, "Patrick"},
            {20, "Thomas"},
            {30, "Dora"},
            {40, "Cindy"},
    };

//    for(int i = 0; i < 4; ++i) {
//        printf("%d\n", &arr[i]);
//    }

    createDLink();

    insertNodeAtLast(&arr[0]);
    insertNodeAtLast(&arr[1]);
    insertNodeAtLast(&arr[2]);
    insertNode(2, &arr[3]);
    insertNodeAtFirst(&arr[3]);
    deleteNode(2);


    printf("\n%d, %d\n", dLinkIsEmpty(), dLinkSize());

    object* p;
    int size = dLinkSize();
    for (int i = 1; i <= size; ++i) {
        p = (object*) getContentOfNode(i);
        printf("get %d, %s\n", p->id, p->name);
    }

    destoryDLink();

    printf("\n%s Finished!\n", __func__);

}