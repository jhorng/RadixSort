#ifndef MSBRadix_H
#define MSBRadix_H

typedef struct buckets buckets;
struct buckets{
  int bin0;
  int bin1;
  int bin2;
  int bin3;
  int bin4;
  int bin5;
  int bin6;
  int bin7;
  int bin8;
  int bin9;
};

void printList(int *list, int length);
void radixSort();

#endif // MSBRadix_H
