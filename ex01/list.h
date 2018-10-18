#pragma once

typedef struct node {
	struct node* succ;
	char* forename;
	char* surname;
} node;

node* insert(node* head, char* forename, char* surname);

void freeList(node* head);

void printList(node* head);