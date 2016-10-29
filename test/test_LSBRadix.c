#include "unity.h"
#include "LSBRadix.h"

void setUp(void){}

void tearDown(void){}

void test_array_with_seven_numbers_return_the_largest_number(void){
	int arr1[] = {45, 11, 56, 780, 3, 900, 2674};
  int arrLength, largestNumber;
  
  arrLength = (int)(sizeof(arr1) / sizeof(arr1[0]));
  largestNumber = findLargestNumber((int *)arr1, arrLength);
  
  TEST_ASSERT_EQUAL(2674, largestNumber);
}

void test_number_with_3_significant_figures_return_two(void){
  int significantFigures;
  
  significantFigures = findSignificantFigures(450);
  TEST_ASSERT_EQUAL(2, significantFigures);
}

void test_number_with_one_significant_figures_return_zero(void){
  int significantFigures;
  
  significantFigures = findSignificantFigures(5);
  TEST_ASSERT_EQUAL(0, significantFigures);
}