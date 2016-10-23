#include "unity.h"
#include "MSBRadix.h"

void setUp(void){}

void tearDown(void){}

void test_array_of_ascending_numbers_return_the_largest_number(void){
  int array[] = {1,2,3,4,5,6,7,8,9};
  int largestNum;
  int arrayLength = (int)(sizeof(array) / sizeof(array[0]));
  
  largestNum = getLargestNumber((int *)array, arrayLength);
  TEST_ASSERT_EQUAL(largestNum, 9);
}

void test_array_of_random_numbers_return_the_largest_numbers(void){
  int array[] = {15, 987, 1263, 9, 50, 777};
  int largestNum;
  int arrayLength = (int)(sizeof(array) / sizeof(array[0]));
  
  largestNum = getLargestNumber((int *)array, arrayLength);
  TEST_ASSERT_EQUAL(largestNum, 1263);
}

void test_number_with_three_digits_return_significant_figures_two(void){
  int number = 197;
  int figures = significantFigures(number);
  
  TEST_ASSERT_EQUAL(figures, 2);
}

void test_number_with_five_digits_return_significant_figures_four(void){
  int number = 19847;
  int figures = significantFigures(number);
  
  TEST_ASSERT_EQUAL(figures, 4);
}

void test_array_of_random_order_numbers_sorted_return_ascending_order(void){
  int array[] = {26, 654, 12, 8, 70, 111, 46, 5, 3408};
  int arrayLength = (int)(sizeof(array) / sizeof(array[0]));
  int figures = significantFigures(getLargestNumber((int *)array, arrayLength));
  
  printf("Before: ");
  printList((int *)array, arrayLength);
  radixSort((int *)array, arrayLength, figures);
  printf("\nAfter: ");
  printList((int *)array, arrayLength);
  TEST_ASSERT_EQUAL(5, array[0]);
  TEST_ASSERT_EQUAL(8, array[1]);
  TEST_ASSERT_EQUAL(12, array[2]);
  TEST_ASSERT_EQUAL(26, array[3]);
  TEST_ASSERT_EQUAL(46, array[4]);
  TEST_ASSERT_EQUAL(70, array[5]);
  TEST_ASSERT_EQUAL(111, array[6]);
  TEST_ASSERT_EQUAL(654, array[7]);
  TEST_ASSERT_EQUAL(3408, array[8]);
}

