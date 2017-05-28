#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Number {
    int n;
    struct Number *next;
};

struct Number *createNode(int n);
struct Number *unshift(struct Number *head, struct Number *node);
struct Number *push(struct Number *head, struct Number *node);

struct Number *iterativeOrderByMinK(struct Number *head, int k);
struct Number *recursiveOrderByMinK(struct Number *head, int k);

void printList(struct Number *head);

int main(void) {
    struct Number *numberList = (struct Number *) malloc(sizeof(struct Number));
    int i;

    for (i = 0; i < 10; i++) {
        numberList = unshift(numberList, createNode(i));
    }
    printList(numberList);

    numberList = iterativeOrderByMinK(numberList, 5);

    //printList(numberList);

    return 0;
}

struct Number *createNode(int n) {
	struct Number *node = (struct Number *) malloc(sizeof(struct Number));

	node->n = n;
	node->next = NULL;

	return node;
}

struct Number *unshift(struct Number *head, struct Number *node) {
    node->next = head;

    return node;
}

struct Number *iterativeOrderByMinK(struct Number *head, int k) {
    struct Number *curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->n < k) {
            head = unshift(head, curr);
        }

        curr = curr->next;
    }

    return head;
}

struct Number *recursiveOrderByMinK(struct Number *head, int k) {
    if (head != NULL) {
        if (head->n < k) {
            head = unshift(head, head);
        }
        else {
            head->next = recursiveOrderByMinK(head->next, k);
        }
    }

    return head;
}

void printList(struct Number *head) {
    if (head != NULL) {
        printf("%d\n", head->n);

        printList(head->next);
    }
    else {
        printf(" > La lista non contiene altri elementi.\n");
    }

    return;
}
