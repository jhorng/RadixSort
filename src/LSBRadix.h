#ifndef LSBRadix_H
#define LSBRadix_H

void printList(int *list, int arrayLength);
int findLargestNumber(int *array, int arrayLength);
int findSignificantFigures(int largestNumber);
int lsbRadixSort(int *array, int arrayLength, int significantFigures, int counter);

#endif // LSBRadix_H
