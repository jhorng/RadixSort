#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
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

/********************************************
 *
 *  This is to get the significant figures of
 *  the number.
 *
 *******************************************/
int significantFigures(int num){
  int sigFig=0;
  while (num>=10){
    num = num/10;
    sigFig++;
  }
  return sigFig;
}

/*******************************************
 *
 *  This is to obtain the largest number in 
 *  the array.
 *
 ******************************************/
int getLargestNumber(int *list, int arrayLength){
  int i, largestNum=INT_MIN;
  for(i=0; i<arrayLength; i++){
    if(list[i]>=largestNum){
      largestNum=list[i];
    }
  }
  return largestNum;
}

/*********************************************
 *
 *  This function is to sort the list/array
 *  as according to Radix sort algorithms.
 *
 ********************************************/
void radixSort(int *list, int arrayLength, int sigFig){
  // int list[] = {4, 256, 101, 20, 78, 379, 400, 7, 546};
  // int arrayLength  = (int)(sizeof(list) / sizeof(list[0]));
  
  // printList(&list[0], arrayLength);
  int i, j;
  int buckets[10][arrayLength];
  int newList[arrayLength];
  int tempList[arrayLength];
  
  for(i=0; i<arrayLength; i++){
    newList[i] = list[i]/pow(10, sigFig);
  }
  
  
  
}