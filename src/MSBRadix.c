#include <stdlib.h>
#include <stdio.h>
#include "MSBRadix.h"

/***************************************
 *
 *  The purpose of this function is to 
 *  print out the numbers/items in the
 *  list/array when called.
 *
 **************************************/
void printList(int *list, int arrayLength){
  int i;
  printf("(");
  for(i=0; i<arrayLength; i++){
    printf("%d, ", *list++);
  }
  printf("\b\b)");
}

/*********************************************
 *
 *  This function is to sort the list/array
 *  as according to Radix sort algorithms.
 *
 ********************************************/
void radixSort(){
  int list[] = {4, 256, 101, 20, 78, 379, 400, 7, 546};
  int arrayLength  = (int)(sizeof(list) / sizeof(list[0]));
  
  printList(&list[0], arrayLength);
}