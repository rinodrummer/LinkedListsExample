#ifndef REC_LISTS_H
#define REC_LISTS_H

struct ListNode {
	struct Studente *stud;
	struct ListNode *next;
};

// Function prototypes:
struct ListNode *createNode(struct Studente *stud); // Creates a node for the linked list;
struct ListNode *deleteNode(struct ListNode *node); // Deletes all the dynamic memory allocated in the node;

struct ListNode *addNodeInPos(struct ListNode *head, struct ListNode *node, unsigned int pos);
struct ListNode *addNodeBefore(struct ListNode *head, struct ListNode *beforeIt, struct ListNode *node);
struct ListNode *addNodeAfter(struct ListNode *head, struct ListNode *afterIt, struct ListNode *node);
struct ListNode *addNodeByMat(struct ListNode *orderedHead, struct ListNode *node, unsigned int isAsc); // Adds the node in order by Studente.mat (ASC || DESC);

struct ListNode *unshift(struct ListNode *head, struct ListNode *node); // Adds the node at the start of the linked list;
struct ListNode *push(struct ListNode *head, struct ListNode *node); // Adds the node at the end of the linked list;

struct ListNode *shift(struct ListNode *head); // Removes the current head of the list, shifting it to the next;
struct ListNode *pop(struct ListNode *head); // Removes the current tail of the list, shifting it to the previous;

struct ListNode *getNodeByPos(struct ListNode *head, unsigned int pos);
struct ListNode *getNodeByStud(struct ListNode *head, struct Studente *stud, struct ListNode **node);
struct ListNode *getNodeByMat(struct ListNode *head, unsigned int mat, struct ListNode **node);

struct ListNode *swapNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode);
struct ListNode *replaceNode(struct ListNode *head, struct ListNode *oldNode, struct ListNode *newNode);

struct ListNode *removeNode(struct ListNode *head, struct ListNode *node); // Definitively removes the node from the list;
/*struct ListNode *removeNodeByPos(struct ListNode *head, unsigned int pos); // TODO
struct ListNode *removeNodeByStud(struct ListNode *head, struct Studente *stud); // TODO
struct ListNode *removeNodeByMat(struct ListNode *head, unsigned int mat); // TODO*/

struct ListNode *deleteList(struct ListNode *head); // Removes all the linked list;

int getLenght(struct ListNode *head); // Returns the lenght of the list;

#endif
