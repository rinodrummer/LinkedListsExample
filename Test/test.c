#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursiveLists.h"

#define DEBUG 0

void clearScreen();

int main(void) {
    struct ListNode *test = createNode(createStudent(0));

    printf("%s\n", (test->stud)->nome);

    printStudentFromNode(test);

    clearScreen();

    return 0;
}

void clearScreen() {
    printf("\nPremere un tasto per continuare...\n");
    getchar();
    system("clear");

    return;
}
