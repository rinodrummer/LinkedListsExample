#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

struct Studente {
	int mat;
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
struct ListNode *addNodeByMat(struct ListNode *orderedHead, struct ListNode *node, unsigned int isAsc); // TODO - Adds the node in order by Studente.mat (ASC || DESC);

struct ListNode *unshift(struct ListNode *head, struct ListNode *node); // Adds the node at the start of the linked list;
struct ListNode *push(struct ListNode *head, struct ListNode *node); // Adds the node at the end of the linked list;

struct ListNode *shift(struct ListNode *head); // Removes the current head of the list, shifting it to the next;
struct ListNode *pop(struct ListNode *head); // Removes the current tail of the list, shifting it to the previous;

struct ListNode *getNodeByPos(struct ListNode *head, int pos); // TODO
struct ListNode *getNodeByStud(struct ListNode *head, struct Studente *stud); // TODO
struct ListNode *getNodeByMat(struct ListNode *head, unsigned int mat); // TODO

struct ListNode *swapNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode); // TODO
struct ListNode *replaceNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode); // TODO

struct ListNode *removeNode(struct ListNode *head, struct ListNode *node); // Definitively removes the node from the list;
struct ListNode *removeNodeByPos(struct ListNode *head, int pos); // TODO
struct ListNode *removeNodeByStud(struct ListNode *head, struct Studente *stud); // TODO
struct ListNode *removeNodeByMat(struct ListNode *head, unsigned int mat); // TODO

struct ListNode *deleteList(struct ListNode *head); // Removes all the linked list;

int getLenght(struct ListNode *head); // Returns the lenght of the list;

struct Studente *createStudent(unsigned int print); // Creates a student;
void printStudent(struct Studente *stud);
void printStudentFromNode(struct ListNode *node);
void printStudentsList(struct ListNode *head); // Prints the students of the linked list;

void clearScreen();

int main(void) {
	struct ListNode *studList;

	studList = createNode(createStudent(0));
	studList = unshift(studList, createNode(createStudent(0)));

	/*printStudentsList(studList);

	studList = shift(studList);

	printStudentsList(studList);*/

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

/* TODO:
 * addNodeByPos
 * addNodeBefore
 * addNodeAfter
 * addNodeByMat
*/

struct ListNode *unshift(struct ListNode *head, struct ListNode *node) {
	node->next = head;

	return node;
}

struct ListNode *push(struct ListNode *head, struct ListNode *node) {
	// Must return head, 'cause the linked list could be empty!
	if (head == NULL) {
		head = node;
	}
	else  {
		struct ListNode *tail = head;

		while (tail->next != NULL) {
			tail = tail->next;
		}

		tail->next = node;
	}

	return head;
}

struct ListNode *shift(struct ListNode *head) {
	head = deleteNode(head);

	return head;
}

struct ListNode *pop(struct ListNode *head) {
	struct ListNode *prev = NULL;
	struct ListNode *tail = head;

	if  (tail != NULL) {
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
	}

	prev->next = deleteNode(tail);

	return head;
}

/* TODO:
 * getNodeByPos
 * getNodeByStud
 * getNodeByMat
 *
 * swapNode
 * replaceNode
 *
 * removeNode
 * removeNodeByPos
 * removeNodeByStud
 * removeNodeByMat
 */

struct ListNode *deleteList(struct ListNode *head) {
	while (head != NULL) {
		head = deleteNode(head);
	}

	return head;
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
    struct Studente *stud = node->stud;

    if (stud != NULL) {
        printf("\nDettagli studente:\n");
		printf("\tMatricola: %d;\n", stud->mat);
		printf("\tNome: %s;\n", stud->nome);
		printf("\tCognome: %s;\n", stud->cognome);
    }

    return;
}

void printStudentsList(struct ListNode *head) {
	struct Studente *stud;

	while (head != NULL) {
		stud = head->stud;

		printf("\n\nDettagli studente:\n");
		printf("\tMatricola: %d;\n", stud->mat);
		printf("\tNome: %s;\n", stud->nome);
		printf("\tCognome: %s;\n", stud->cognome);

		head = head->next;
	}

	return;
}
