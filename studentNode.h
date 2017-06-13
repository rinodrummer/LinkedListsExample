#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

struct Studente {
	unsigned int mat;
	char nome[32];
	char cognome[32];
};

struct Studente *createStudent(unsigned int print); // Creates a student;

void printStudent(struct Studente *stud);
void printStudentFromNode(struct ListNode *node);
void printStudentsList(struct ListNode *head); // Prints the students of the linked list;

#endif
