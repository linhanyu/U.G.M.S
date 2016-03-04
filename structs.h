// Use these structs

#ifndef UGMS_STRUCTS_H
#define UGMS_STRUCTS_H

#endif //UGMS_STRUCTS_H

typedef struct tagOfItem {
    char iName[20];
    int id;
    int sTime[8];
    int eTime[8];
    char place[10];
    int number;
    char gender;
} Item;

typedef struct tagOfPlayer {
    char name[20];
    int id[11];
    char college[10];
    char major[15];
    int grade;
    char gender;
    char iName[20];
    int ranks[5];
    int result[7][5];
} Player;

