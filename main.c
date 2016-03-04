// UGMS

//#include <stdio.h>
#include <string.h>
//#include "dlink.h"
#include "test.h"

int main(int argc, char** argv) {
    if (strcmp(argv[1], "-t") == 0) {
//        fileTest();
        dLinkTest();
    }
    return 0;
}
