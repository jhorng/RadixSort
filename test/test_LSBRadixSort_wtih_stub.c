#include "unity.h"
#include "LSBRadix.h"
#include "mock_LSBRadixSortStub.h"

void setUp(void){}

void tearDown(void){}

void test_array_with_seven_elements_of_a_digit_only_will_return_zero_for_the_significant_figure_of_the_next_recursive_call(void){
  int arr[] = {7, 5, 4, 8, 3, 1, 9};
  
  _lsbRadixSort_Expect((int *)arr, 7, 0, 2);
  
  lsbRadixSort((int *)arr, 7, 1, 1);
  
  // Arrangement of the LSB digit of radix sort.
  // Since all the element is a digit only,
  // 1 turn of sorting is needed to finsih sorting the array.
  TEST_ASSERT_EQUAL(arr[0], 1);
  TEST_ASSERT_EQUAL(arr[1], 3);
  TEST_ASSERT_EQUAL(arr[2], 4);
  TEST_ASSERT_EQUAL(arr[3], 5);
  TEST_ASSERT_EQUAL(arr[4], 7);
  TEST_ASSERT_EQUAL(arr[5], 8);
  TEST_ASSERT_EQUAL(arr[6], 9);
}

void test_array_with_seven_elements_of_3_digit_only_will_return_two_for_the_significant_figures_of_the_next_recursive_call(void){
  int arr[] = {711, 523, 454, 868, 399, 170, 912};
  
  _lsbRadixSort_Expect((int *)arr, 7, 2, 2);
  
  lsbRadixSort((int *)arr, 7, 3, 1);
  
  // Arrangement of the LSB digit of radix sort. (first turn)
  // This array will need three turns to finish sorting'em,
  // because every element has 3 significant figures.
  TEST_ASSERT_EQUAL(arr[0], 170);
  TEST_ASSERT_EQUAL(arr[1], 711);
  TEST_ASSERT_EQUAL(arr[2], 912);
  TEST_ASSERT_EQUAL(arr[3], 523);
  TEST_ASSERT_EQUAL(arr[4], 454);
  TEST_ASSERT_EQUAL(arr[5], 868);
  TEST_ASSERT_EQUAL(arr[6], 399);
}

void test_array_with_seven_elements_of_different_digit_only_will_return_the_largest_significant_figures_minus1_for_the_significant_figure_of_the_next_recursive_call(void){
  int arr[] = {7, 52, 441, 867, 3, 1010, 91128};
  
  _lsbRadixSort_Expect((int *)arr, 7, 4, 2);
  
  lsbRadixSort((int *)arr, 7, 5, 1);
  
  // Arrangement of the LSB digit of radix sort. (first turn)
  // Since every element has different significant figures,
  // the array will need five turns to finish sorting as 
  // the largest significant figures will 5 - 91128.
  TEST_ASSERT_EQUAL(arr[0], 1010);
  TEST_ASSERT_EQUAL(arr[1], 441);
  TEST_ASSERT_EQUAL(arr[2], 52);
  TEST_ASSERT_EQUAL(arr[3], 3);
  TEST_ASSERT_EQUAL(arr[4], 7);
  TEST_ASSERT_EQUAL(arr[5], 867);
  TEST_ASSERT_EQUAL(arr[6], 91128);
}

void test_array_with_seven_elements_of_same_digit_with_some_negative_values_will_fail_the_radix_sort(void){
  int arr[] = {-7, 52, 441, 86, -3, 20, 128};
  
  _lsbRadixSort_Expect((int *)arr, 7, 3, 1);
  
  lsbRadixSort((int *)arr, 7, 3, 1);
  
  TEST_FAIL_MESSAGE("Array has negative values and need to be eliminated!");
}