#include "unity.h"
#include "LSBRadix.h"
#include "mock_LSBRadixSortStub.h"

void setUp(void){}

void tearDown(void){}

void test_dummy_function(void){
  int arr[] = {7, 5, 4, 8, 3, 1, 9};
  
  _lsbRadixSort_Expect((int *)arr, 7, 0, 2);
  
  lsbRadixSort((int *)arr, 7, 1, 1);
}