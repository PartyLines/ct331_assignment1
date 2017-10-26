#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct {
	void* data;
	size_t size;
	void (*printFunc)(void* data);
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void(*printNode)(void* data)) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	memcpy(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	e->printFunc = printNode;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		current->printFunc(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void(*printNode)(void* data)) {
	listElement* newEl = createEl(data, size, printNode);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

int length(listElement* list) {
	if (!list) return 0;
	listElement* next = list;
	int i = 0;
	do {
		next = next->next;
		i++;
	} while (next != NULL);
	return i;
}

void push(listElement** list, void* data, size_t size, void(*printNode)(void* data)) {
	listElement* head = createEl(data, size, printNode);
	head->next = *list;
	*list = head;
	//Looks like memcpy was not needed after all
}
listElement* pop(listElement** list) {
	listElement* temp = *list;
	*list = temp->next;
	temp->next = NULL;
	return temp;
}
void enqueue(listElement** list, void* data, size_t size, void(*printNode)(void* data)) {
	listElement* head = createEl(data, size, printNode);
	head->next = *list;
	*list = head;
	//Enqueue is the same as push when used on the same data structure.
}
listElement* dequeue(listElement* list) {
	if (!list) return NULL;
	listElement* secondLast = list;
	listElement* last = list->next;
	if (!last) {
		return secondLast;
	}
	while (!!last->next) {
		secondLast = last;
		last = last->next;
	}
	secondLast->next = NULL;
	return last;
}

