#include "unity.h"
#include "LSBRadix.h"
#include "LSBRadixSortStub.h"

void setUp(void){}

void tearDown(void){}

void test_array_with_seven_numbers_return_the_largest_number(void){
	int arr1[] = {45, 11, 56, 780, 3, 900, 2674};
  int arrLength, largestNumber;
  
  arrLength = (int)(sizeof(arr1) / sizeof(arr1[0]));
  largestNumber = findLargestNumber((int *)arr1, arrLength);
  
  TEST_ASSERT_EQUAL(2674, largestNumber);
}

void test_number_with_3_significant_figures_return_three(void){
  int significantFigures;
  
  significantFigures = findSignificantFigures(450);
  TEST_ASSERT_EQUAL(3, significantFigures);
}

void test_number_with_one_significant_figures_return_one(void){
  int significantFigures;
  
  significantFigures = findSignificantFigures(5);
  TEST_ASSERT_EQUAL(1, significantFigures);
}

void test_array_of_random_numbers_get_sorted_by_LSBRadixSort(void){
  int arr1[] = {45, 11, 56, 780, 3, 900, 2674};
  int arrLength, largestNumber, significantFigures, counter=1;
  
  arrLength = (int)(sizeof(arr1) / sizeof(arr1[0]));
  largestNumber = findLargestNumber((int *)arr1, arrLength);
  significantFigures = findSignificantFigures(largestNumber);
  
  printf("Before: ");
  printList((int *)arr1, arrLength);
  lsbRadixSort((int *)arr1, arrLength, significantFigures, counter);
  printf("\nAfter: ");
  printList((int *)arr1, arrLength);
  
  TEST_ASSERT_EQUAL(3, arr1[0]);
  TEST_ASSERT_EQUAL(11, arr1[1]);
  TEST_ASSERT_EQUAL(45, arr1[2]);
  TEST_ASSERT_EQUAL(56, arr1[3]);
  TEST_ASSERT_EQUAL(780, arr1[4]);
  TEST_ASSERT_EQUAL(900, arr1[5]);
  TEST_ASSERT_EQUAL(2674, arr1[6]);
}

void test_array_of_random_numbers_with_equivalent_significant_figures_get_sorted_by_LSBRadixSort(void){
  int arr1[] = {445, 211, 156, 780, 378, 900, 674};
  int arrLength, largestNumber, significantFigures, counter=1;
  
  arrLength = (int)(sizeof(arr1) / sizeof(arr1[0]));
  largestNumber = findLargestNumber((int *)arr1, arrLength);
  significantFigures = findSignificantFigures(largestNumber);
  
  printf("Before: ");
  printList((int *)arr1, arrLength);
  lsbRadixSort((int *)arr1, arrLength, significantFigures, counter);
  printf("\nAfter: ");
  printList((int *)arr1, arrLength);
  
  TEST_ASSERT_EQUAL(156, arr1[0]);
  TEST_ASSERT_EQUAL(211, arr1[1]);
  TEST_ASSERT_EQUAL(378, arr1[2]);
  TEST_ASSERT_EQUAL(445, arr1[3]);
  TEST_ASSERT_EQUAL(674, arr1[4]);
  TEST_ASSERT_EQUAL(780, arr1[5]);
  TEST_ASSERT_EQUAL(900, arr1[6]);
}