#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "LSBRadix.h"

/**********************************
 *
 *  This function is to print out
 *  any 1D-array that is passed to
 *  this function as an argument.
 *
 **********************************/
void printList(int *list, int arrayLength){
  int i;
  printf("(");
  for(i=0; i<arrayLength; i++){
    printf("%d, ", *list++);
  }
  printf("\b\b)");
}

/**************************************** 
 *
 *  This function is to find the largest 
 *  number in a 1D-array.
 *
 *  Example: {1, 2, 3, 4, 5}
 *  Return : 5
 ****************************************/
int findLargestNumber(int *array, int arrayLength){
  int i, largestNumber;
  
  largestNumber = INT_MIN;
  for(i=0; i<arrayLength; i++){
    if(*array>largestNumber){
      largestNumber = *array;
    }
    array++;
  }
  
  return largestNumber;
}

/*************************************
 *
 *  To find the significant digits of 
 *  a number.
 *
 *  Example : 15648
 *  Return  : 5
 *************************************/
int findSignificantFigures(int number){
  int significantFigures=0;
  
  while(number != 0){
    number = number / 10;
    significantFigures++;
  }
  
  return significantFigures;
}

/****************************************************
 *
 *  To sort a 1D-array into an ascending order.
 *  The sort will sort from least significant to most 
 *  significant.
 *  However, this sort can only sorts unsigned integer.
 *  Any negative number in the 1D-array will crash the
 *  whole function.
 *
 *  Example : {7, 5, 4, 8, 3, 1, 9}
 *  Return  : {1, 3, 4, 5, 7, 8, 9}
 *
 ****************************************************/
void lsbRadixSort(int *array, int arrayLength, int significantFigures, int counter) // counter is always passed as one for looping purpose as well as identifying the digit of each numbers.
{
  int i, j, numberHolder;
  int digit=0, k=0;
  int bucket[10][10];
  int bucketElement[10] = {0}; // To record the total numbers inside each buckets in array form.
  
  // Every numbers will be split to determine the digit numbers.
  // The digit will be used to determine the particular bucket to store 
  // the particular number.
  for(i=0; i<arrayLength; i++){
    numberHolder = array[i];
    for(j=counter; j!=0; j--){
      digit = numberHolder % 10;
      numberHolder = numberHolder / 10;
    }
    bucket[digit][bucketElement[digit]] = array[i];
    bucketElement[digit]++;
  }
  
  // This loop is to return the stored numbers from bucket0-9 back to the 1D-array.
  for(i=0; i<10; i++){
    for(j=0; j<bucketElement[i]; j++){
      array[k] = bucket[i][j];
      k++;
    }
  }
  
  significantFigures--;
  counter++;
  if(significantFigures>=0){
    _lsbRadixSort(&array[0], arrayLength, significantFigures, counter);
  }   
}




