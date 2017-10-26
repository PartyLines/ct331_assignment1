#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
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

void push(listElement** list, char* data, size_t size) {
	listElement* head = createEl(data, size);
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
void enqueue(listElement** list, char* data, size_t size) {
	listElement* head = createEl(data, size);
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
		//See below for an implementation that can reduce a list to 0, using side effects on a double pointer.
	}
	while (!!last->next) {
		secondLast = last;
		last = last->next;
	}
	secondLast->next = NULL;
	return last;
}

/*listElement* dequeue(listElement** list) {
	if (!list) return NULL;
	listElement* secondLast = *list;
	listElement* last = (*list)->next;
	if (!last) {
		*list = NULL;
		return secondLast;
	}
	while (!!last->next) {
		secondLast = last;
		last = last->next;
	}
	secondLast->next = NULL;
	return last;
}*/