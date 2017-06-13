#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursiveLists.h"

#include "studentNode.h"

#ifndef DEBUG
#define DEBUG 0
#endif

// Student related functions (4):
struct Studente *createStudent(unsigned int print) {
    static unsigned int ID = 1;

	struct Studente *stud = (struct Studente *) malloc(sizeof(struct Studente));

	if (DEBUG) {
		stud->mat = ID++;
		strcpy(stud->nome, "Giuseppe");
		strcpy(stud->cognome, "Di Genova");

        if (print) printStudent(stud);
	}
	else {
		printf("\nInserimento di un nuovo studente:\n");
		printf("\tMatricola: ");
		scanf("%d", &stud->mat);
		printf("\tNome: ");
		scanf("%s", stud->nome);
		printf("\tCognome: ");
		scanf("%s", stud->cognome);
		printf("\n\n");
	}

	return stud;
}

void printStudent(struct Studente *stud) {
    if (stud != NULL) {
        printf("\nDettagli studente:\n");
		printf("\tMatricola: %d;\n", stud->mat);
		printf("\tNome: %s;\n", stud->nome);
		printf("\tCognome: %s;\n", stud->cognome);
    }

    return;
}

void printStudentFromNode(struct ListNode *node) {
    struct Studente *stud;

    if (node != NULL && node->stud != NULL) {
        stud = node->stud;

        printf("\nDettagli studente:\n");
		printf("\tMatricola: %d;\n", stud->mat);
		printf("\tNome: %s;\n", stud->nome);
		printf("\tCognome: %s;\n", stud->cognome);
    }
    else {
        printf("\n> Nessuno studente presente in questo nodo.\n");
    }

    return;
}

void printStudentsList(struct ListNode *head) {
    if (head != NULL) {
        struct Studente *stud = head->stud;

        if (stud != NULL) {
            printf("\nDettagli studente:\n");
    		printf("\tMatricola: %d;\n", stud->mat);
    		printf("\tNome: %s;\n", stud->nome);
    		printf("\tCognome: %s;\n", stud->cognome);
        }

        printStudentsList(head->next);
    }
    else {
        printf("\n> La lista non contiene altri elementi.\n");
    }

    return;
}
