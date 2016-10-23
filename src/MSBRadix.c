#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "MSBRadix.h"

/******************************************************
 *  Introduction:
 *
 *    This is the most significant radix sort. It uses 
 *  the significant figures of the largest numbers to 
 *  to even out the significant figures of other numbers
 *  in an list/array of numbers.
 *
 *   Besides that, the numbers in the list/array will be 
 *  grouped as according of the buckets - bucket0 to 
 *  bucket9.
 *
 *    Once the numbers are grouped, the numbers in the 
 *  buckets will be sorted again if the order isn't 
 *  correct. Then, the numbers will be arranged back 
 *  into the list/array. 
 *
 *    The process will keep on going until the numbers in 
 *  the list/array are sorted to the ascending order.
 */

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

/*******************************************
 *
 *  This is to obtain the largest number in 
 *  the array.
 *
 ******************************************/
int getLargestNumber(int *list, int arrayLength){
  int i, largestNum=INT_MIN;
  for(i=0; i<arrayLength; i++){
    if(list[i]>largestNum){
      largestNum=list[i];
    }
  }
  return largestNum;
}

/********************************************
 *
 *  This is to get the significant figures of
 *  the largest number.
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

/*********************************************
 *
 *  This function is to sort the list/array
 *  as according to Radix sort algorithms.
 *
 ********************************************/
void radixSort(int *list, int arrayLength, int sigFig){
  int i, j, k, l, m=0;
  int bucketList[10] = {0};
  int buckets[10][arrayLength];
  int temp;

  for(i=0; i<arrayLength; i++){
    temp = list[i]/pow(10, sigFig);
    for(j=0; j<arrayLength; j++){
      if(temp == j){
        buckets[j][bucketList[j]] = list[i];
        bucketList[j]++;
      }
    }
  }

  for(k=0; k<10; k++){
    for(l=0; l<bucketList[k]; l++){
      list[m] = buckets[k][l];
      m++;
    }
  }

  sigFig--;
  if(sigFig>=0){
    radixSort(&list[0], arrayLength, sigFig);
  }
}