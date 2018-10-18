#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

node* insert(node* head, char* forename, char* surname) {
	node* newNode = (node*) malloc(sizeof(node));
	newNode->forename = (char*) malloc(100 * sizeof(char));
	newNode->surname = (char*) malloc(100 * sizeof(char));

	strncpy(newNode->forename, forename, 100);
	strncpy(newNode->surname, surname, 100);

	if (!head) 
		return newNode;
	
	if (strcmp(surname, head->surname) >= 0) {
		newNode->succ = head;
		return newNode;
	}

	node* index = head;
	while(index->succ && strcmp(surname, index->succ->surname) < 0) {
		index = index->succ;
	}

	newNode->succ = index->succ;
	index->succ = newNode;

	return head;
}

void freeList(node* head) {	
	node* currNode= head;

	while(currNode) {
		node* nextNode = currNode->succ;
		free(currNode->forename);
		free(currNode->surname);
		free(currNode);
		currNode = nextNode;
	}
}

void printList(node* head) {
	node* curNode = head;
	while (curNode) {
		printf("%s %s\n", curNode->forename, curNode->surname);
		curNode = curNode->succ;
	}
}