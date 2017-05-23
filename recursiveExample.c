// Iterative Linked List Example: https://pastebin.com/dNn6fr4J
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define DEBUG 1

struct Studente {
	unsigned int mat;
	char nome[32];
	char cognome[32];
};

struct ListNode {
	struct Studente *stud;
	struct ListNode *next;
};

struct ListNode *createNode(struct Studente *stud); // Creates a node for the linked list;
struct ListNode *deleteNode(struct ListNode *node); // Deletes all the dynamic memory allocated in the node;

struct ListNode *addNodeInPos(struct ListNode *head, struct ListNode *node, int pos); // TODO
struct ListNode *addNodeBefore(struct ListNode *head, struct ListNode *beforeIt, struct ListNode *node); // TODO
struct ListNode *addNodeAfter(struct ListNode *head, struct ListNode *afterIt, struct ListNode *node); // TODO
struct ListNode *addNodeBetween(struct ListNode *head, struct ListNode *aIt, struct ListNode *bIt, struct ListNode *node); // TODO

struct ListNode *unshift(struct ListNode *head, struct ListNode *node); // Adds the node at the start of the linked list;
struct ListNode *push(struct ListNode *head, struct ListNode *node); // Adds the node at the end of the linked list;

struct ListNode *shift(struct ListNode *head); // Removes the current head of the list, shifting it to the next;
struct ListNode *pop(struct ListNode *head); // Removes the current tail of the list, shifting it to the previous;

struct ListNode *getNodeByPos(struct ListNode *head, int pos); // TODO
struct ListNode *getNodeByStud(struct ListNode *head, struct Studente *stud); // TODO

struct ListNode *replaceNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode);

struct ListNode *removeNode(struct ListNode *head, struct ListNode *node); // Definitively removes the node from the list;
struct ListNode *removeNodeByPos(struct ListNode *head, int pos); // TODO
struct ListNode *removeNodeByStud(struct ListNode *head, struct Studente *stud); // TODO

struct ListNode *deleteList(struct ListNode *head); // Removes all the linked list;

int getLenght(struct ListNode *head); // Returns the lenght of the list;

struct Studente *createStudent(unsigned int print); // Creates a student;
void printStudent(struct Studente *stud);
void printStudentFromNode(struct ListNode *node);
void printStudentsList(struct ListNode *head); // Prints the students of the linked list;

void clearScreen();

int main(void) {
	struct ListNode *studList;
    //struct ListNode *node = NULL;

	studList = createNode(createStudent(0));
    studList = push(studList, createNode(createStudent(0)));

    printf("Prima lista:\n");
    printStudentsList(studList);
    //printf("\nN° studenti presenti: %d;\n", getLenght(studList));

    //printf("\n===============================================\n");

    /*node = push(node, createNode(createStudent(0)));

    printf("\nSeconda lista:\n");
    printStudentsList(node);
    printf("\nN° studenti presenti: %d;\n", getLenght(node));*/

    clearScreen();

    studList = replaceNode(studList, studList->next, createNode(createStudent(0)));

    printf("Prima lista:\n");
    //printStudentsList(studList);
    printf("\nN° studenti presenti: %d;\n", getLenght(studList));

    /*studList = deleteList(studList);
    printStudentsList(studList);*/

    /*printf("\nEliminazione in corso...\n");
    studList = removeNode(studList, studList->next);

    clearScreen();

	if (studList == NULL) {
        printf("\nNessuno studente presente.\n");
    }
    else {
        printStudentsList(studList);
    }*/

	return 0;
}

struct ListNode *createNode(struct Studente *stud) {
	struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));

	node->stud = stud;
	node->next = NULL;

	return node;
}

struct ListNode *deleteNode(struct ListNode *node) {
    struct ListNode *next = node->next;

	free(node->stud);
    free(node);

	return next;
}

struct ListNode *addNodeInPos(struct ListNode *head, struct ListNode *node, int pos) {
    return head;
}

struct ListNode *addNodeBefore(struct ListNode *head, struct ListNode *beforeIt, struct ListNode *node) {
    return head;
}

struct ListNode *addNodeAfter(struct ListNode *head, struct ListNode *afterIt, struct ListNode *node) {
    return head;
}

struct ListNode *addNodeBetween(struct ListNode *head, struct ListNode *aIt, struct ListNode *bIt, struct ListNode *node) {
    return head;
}

struct ListNode *unshift(struct ListNode *head, struct ListNode *node) {
    node->next = head;

    return node;
}

struct ListNode *push(struct ListNode *head, struct ListNode *node) {
    if (head == NULL) {
        head = node;
    }
    else {
        head->next = push(head->next, node);
    }

    return head;
}

struct ListNode *shift(struct ListNode *head) {
    return deleteNode(head);
}

struct ListNode *pop(struct ListNode *head) {
    if (head->next != NULL) {
        head->next = pop(head->next);
    }
    else {
        head = deleteNode(head);
    }

    return head;
}

struct ListNode *getNodeByPos(struct ListNode *head, int pos) {
    printf("%d >\n", pos);
    if (head != NULL) {
        printStudentFromNode(head);

        clearScreen();

        if (pos > 0) {
            head = getNodeByPos(head->next, --pos);
        }
    }

    return head;
}

struct ListNode *getNodeByStud(struct ListNode *head, struct Studente *stud) {
    return head;
}

struct ListNode *replaceNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode) {
    if (head != NULL) {
        if (head != oldNode) {
            head->next = replaceNode(head->next, oldNode, newNode);
        }
        else {
            newNode->next = oldNode->next;
            head = newNode;

            oldNode = deleteNode(oldNode);
        }
    }
    else {
        head = newNode;
    }

    return head;
}

struct ListNode *removeNode(struct ListNode *head, struct ListNode *node) {
    if (head != NULL && node != NULL) {
        if (head == node) {
            head = head->next;

            deleteNode(node);
        }
        else {
            head->next = removeNode(head->next, node);
        }
    }

    return head;
}

struct ListNode *deleteList(struct ListNode *head) {
    if (head != NULL) {
        head->next = deleteList(head->next);
    }

    return NULL;
}

int getLenght(struct ListNode *head) {
    int l = 0;

    if (head != NULL) {
        printStudentFromNode(head);

        l = 1 + getLenght(head->next);
    }

    return l;
}

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

void clearScreen() {
    printf("\nPremere un tasto per continuare...");
    getchar();
    system("clear");

    return;
}
