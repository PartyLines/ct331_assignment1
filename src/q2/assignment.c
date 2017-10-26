#include <stdio.h>
#include "linkedList.h"
#include "tests.h"

int main(int arg, char* argc[]){
  runTests();
  listElement* l = createEl("Uno", 16);
  listElement* n;
  n = insertAfter(l, "Dos", 16);
  insertAfter(n, "Tres", 16);
  printf("Expected length: 3. Actual Length: %d\n", length(l));
  printf("Current List state (Expecting uno dos tres): \n");
  traverse(l);
  printf("Pushing Zero to l...\n");
  push(&l, "Zero", 16);
  printf("New List state (Expecting zero uno dos tres): \n");
  traverse(l);
  listElement *popped = pop(&l);
  printf("Attempted to pop list. Popped value: ");
  traverse(popped);
  printf("New List state (Expecting uno dos tres): \n");
  traverse(l);
  printf("Enqueueing Zero to l...\n");
  enqueue(&l, "Zero", 16);
  printf("New List state (Expecting zero uno dos tres): \n");
  traverse(l);
  printf("Dequeueing from l. Expecting tres. Got: ");
  traverse(dequeue(l));
  printf("New List state (Expecting zero uno dos): \n");
  traverse(l);


  return 0;
}
