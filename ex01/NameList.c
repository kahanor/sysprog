#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Wrong number of arguments supplied.");
		return -1;
	}

	char forename[100], surname[100];
	node* head = NULL;

	char* file_name = argv[1];

	FILE* list_file;

	list_file = fopen(file_name, "r");
	while (fscanf(list_file, "%s %s", forename, surname) != EOF) {
		head = insert(head, forename, surname);
	}
	fclose(list_file);

	printList(head);

	freeList(head);

	return 0;
}