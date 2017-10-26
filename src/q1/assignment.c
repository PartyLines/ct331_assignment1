#include <stdio.h>

int main(int arg, char* argc[]){
	printf("Int size: %d, \nInt ptr size: %d, \nLong size: %d, \nDouble ptr size: %d, \nPointer to Char ptr size: %d",
	  sizeof(int),
	  sizeof(int*),
	  sizeof(long),
	  sizeof(double *),
	  sizeof(char **));
  return 0;
}
