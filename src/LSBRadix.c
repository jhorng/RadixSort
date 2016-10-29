#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "LSBRadix.h"

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

int findSignificantFigures(int number){
  int significantFigures=0;
  
  while(number>=10){
    number = number/10;
    significantFigures++;
  }
  
  return significantFigures;
}