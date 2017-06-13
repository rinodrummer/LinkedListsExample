#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursiveLists.h"

#ifndef DEBUG
#define DEBUG 0
#endif

// Functions implementations:
//	Base node interaction functions (2):
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

// 	Adding node functions (3 dynamic position, 2 static position):
struct ListNode *addNodeInPos(struct ListNode *head, struct ListNode *node, unsigned int pos) {
    if (pos == 0) {
        if (head == NULL) {
            head = node;
        }
        else {
            head = swapNode(head, head, node);
        }
    }
    else {
        head->next = addNodeInPos(head->next, node, pos - 1);
    }

    return head;
}

struct ListNode *addNodeBefore(struct ListNode *head, struct ListNode *beforeIt, struct ListNode *node) {
	if (head != NULL) {
		if (head->next == beforeIt) {
			head = swapNode(head, head, node);
		}
		else {
			head->next = addNodeBefore(head, beforeIt, node);
		}
	}
	else {
		head = node;
	}

    return head;
}

struct ListNode *addNodeAfter(struct ListNode *head, struct ListNode *afterIt, struct ListNode *node) {
	if (head != NULL) {
		if (head == afterIt) {
			node->next = head->next;
			head->next = node;
		}
		else {
			head->next = addNodeAfter(head->next, afterIt, node);
		}
	}

    return head;
}

struct ListNode *addNodeByMat(struct ListNode *head, struct ListNode *node, unsigned int mat) {
	struct Studente *stud;

	if (head != NULL && head->stud != NULL) {
		stud = head->stud;

		if (stud->mat == mat) {
			head = addNodeAfter(head, head, node);
		}
		else {
			head->next = addNodeByMat(head->next, node, mat);
		}
	}
	else {
		head = node;
	}

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

// 	Removing node functions (2):
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

// 	Retrivering node functions (3):
struct ListNode *getNodeByPos(struct ListNode *head, unsigned int pos) {
    //printf("%d >\n", pos);

    if (head != NULL) {
        //printStudentFromNode(head);
        //clearScreen();

        if (pos > 0) {
            head = getNodeByPos(head->next, pos - 1);
        }
    }

    return head;
}

struct ListNode *getNodeByStud(struct ListNode *head, struct Studente *stud, struct ListNode **node) {
    if (head != NULL) {
        if (head->stud == stud) {
            *node = head;
        }
        else {
            head->next = getNodeByStud(head->next, stud, node);
        }
    }

    return head;
}

struct ListNode *getNodeByMat(struct ListNode *head, unsigned int mat, struct ListNode **node) {
	if (head != NULL) {
		if (head->stud->mat == mat) {
			*node = head;
		}
		else {
			head->next = getNodeByMat(head->next, mat, node);
		}
	}

    return head;
}

// 	Moving node functions (2):
struct ListNode *swapNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode) {
    if (head != NULL && oldNode != NULL) {
        if (head != oldNode) {
            head->next = swapNode(head->next, oldNode, newNode);
        }
        else {
            newNode->next = oldNode;
            head = newNode;
        }
    }
    else {
        head = newNode;
    }

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

// 	Removing node functions (4):
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

struct ListNode *removeNodeByPos(struct ListNode *head, unsigned int pos) {
	if (head != NULL) {
		if (pos == 0) {
			head = removeNode(head, head);
		}
		else {
			head->next = removeNodeByPos(head->next, --pos);
		}
	}

	return head;
}

struct ListNode *removeNodeByStud(struct ListNode *head, struct Studente *stud) {
	return head;
}

struct ListNode *removeNodeByMat(struct ListNode *head, unsigned int mat) {
	return head;
}

// Linked list related functions (2):
struct ListNode *deleteList(struct ListNode *head) {
    if (head != NULL) {
        head->next = deleteList(head->next);
    }

    return NULL;
}

int getLenght(struct ListNode *head) {
    int l = 0;

    if (head != NULL) {
        l = 1 + getLenght(head->next);
    }

    return l;
}

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
