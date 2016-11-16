#ifndef LSBRadixSortStub_H
#define LSBRadixSortStub_H

#ifdef TEST
#include "LSBRadix.h"
#else
#define _lsbRadixSort lsbRadixSort
#endif

void _lsbRadixSort(int *array, int arrayLength, int significantFigures, int counter);

#endif // LSBRadixSortStub_H
