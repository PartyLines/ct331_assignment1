#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

void printStr(void* data) {
	printf("%s\n", (char*)data);
}

void printInt(void* data) {
	printf("%d\n", *(int*)data);
}

int main(int arg, char* argc[]) {
	//runTests();
	listElement* l = createEl("Uno", sizeof("Uno"), &printStr);
	listElement* n;
	n = insertAfter(l, "Dos", sizeof("Dos"), &printStr);
	insertAfter(n, "Tres", sizeof("Tres"), &printStr);
	printf("Expected length: 3. Actual Length: %d\n", length(l));
	printf("Current List state (Expecting uno dos tres): \n");
	traverse(l);
	printf("Pushing Zero to l...\n");
	push(&l, "Zero", sizeof("Zero"), &printStr);
	printf("New List state (Expecting zero uno dos tres): \n");
	traverse(l);
	listElement *popped = pop(&l);
	printf("Attempted to pop list. Popped value: ");
	traverse(popped);
	printf("New List state (Expecting uno dos tres): \n");
	traverse(l);
	printf("Enqueueing Zero to l...\n");
	enqueue(&l, "Zero", sizeof("Zero"), &printStr);
	printf("New List state (Expecting zero uno dos tres): \n");
	traverse(l);
	printf("Dequeueing from l. Expecting tres. Got: ");
	traverse(dequeue(l));
	printf("New List state (Expecting zero uno dos): \n");
	traverse(l);

	//Testing on more than one data type
	int x = 4, y = 8;	//Ints must be assigned in advance to get pointers to them
	listElement* i = createEl(&x, sizeof(int), &printInt);
	listElement* j;
	j = insertAfter(i, &y, sizeof(int), &printInt);
	insertAfter(j, "Fifteen", sizeof("Fifteen"), &printStr);
	printf("Traversing int List (Expecting 4 8 Fifteen): \n");
	traverse(i);

	return 0;
}

