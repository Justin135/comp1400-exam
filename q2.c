/*
Program: q2.c
Author: Justin Bornais
Date: December 12, 2020
*/

#include <stdio.h>

float diff(int num);

int main(void) {
  int num;
  printf("Please enter an integer number:\t");
  scanf("%d", &num);

  if(num > 9) {
    printf("The output is:\t%.2f", diff(num));
  }
  else {
    puts("The number is too small.");
  }
  return 0;
}

float diff(int num) {
  int digit;
  int numDigits = 0;
  int product = 1;
  float sum = 0;
  float average;
  
  while(num > 0) {
    digit = num % 10;
    sum += digit;
    product *= digit;
    numDigits++;
    num /= 10;
  }

  average = sum / numDigits;

  return product - average;
}