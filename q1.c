/*
Program: q1.c
Author: Justin Bornais
Date: December 12, 2020
*/

#include <stdio.h>

int main(void) {
  int nums[10];
  int product = 1;

  puts("My name is: Justin Bornais");
  puts("************");

  printf("Please enter 10 integer numbers separated by comma, press \"Enter\" after that:\t");

  for(int i = 0;i < 10;i++) {
    scanf("%d%*c", &nums[i]); // This input ignores the comma afterwards by ignoring the following character after the number.
  }

  for(int i = 0;i < 10;i++) {
    if(i % 2 == 1 && nums[i] % 2 == 0 && nums[i] != 0) {
      product *= nums[i];
    }
  }

  puts("********");
  printf("The output is:\t%d\n", product);
  puts("********");

  return 0;
}