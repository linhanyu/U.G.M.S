#include <string.h>
#include "test.h"
#include "dlink.h"
#include "structs.h"

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

void fileTest() {
    Item arr[] = {
            {"跳高",      0, "03260800", "03260900", "操场",  6,  "男"},
            {"男子1000米", 1, "03271400", "03271600", "田径场", 16, "男"},
            {"女子800米",  2, "03280900", "03281000", "田径场", 16, "女"},
    };

    Item temp;
    temp = arr[2];
    FILE *fp;
    Item *p = &temp;
    char *path = getenv("HOME");
    const char *path2 = "/ClionProjects/UGMS/Items.ugms";
    path = strcat(path, path2);
    printf("%s", path);
    fp = fopen(path, "w");
    if (fp == NULL) {
        printf("file creation failed\n");
    }
    fwrite(p, sizeof(Item), 1, fp);
    fclose(fp);
    fp = fopen(path, "r");
    fread(p, sizeof(Item), 1, fp);
    output(temp);
    fclose(fp);
}

int output(Item temp) {
    printf("\n%s \n%d \n%s \n%s \n%s \n%d \n%s\n", temp.iName, temp.id,
           temp.sTime,
           temp.eTime, temp.place, temp.number, temp.gender);
    return 0;
}
