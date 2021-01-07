/*
Program: q5.c
Author: Justin Bornais
Date: December 12, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInt();
void sort(int arr[], int size);


int main(void) {
  char choice;
  int n;
  srand(time(0));
  int large = 1000;
  int small = 1;

  puts("******");
  while(choice != 'n' && choice != 'N') {
    puts("Please enter a valid integer number (n):\t");
    n = getInt();

    if(n > 1000) {
      n = 1000; // Set n to 1000.
    }

    int arr[n];

    for(int i = 0;i < n;i++) {
      arr[i] = (rand() % (large + 1 - small) + small);

      // Verifies that there are no duplicates.
      for(int j = i - 1;j >= 0;j--) {
        if (arr[i] == arr[j]) {
          i--; // Decrement i to try another random number.
          break;
        }
      }
    }

    sort(arr, n);

    printf("%s", "The output is:\t");
    for(int i = 0;i < n;i++) {
      if(i == n - 1) {
        printf("%d\n", arr[i]);
        break;
      }
      printf("%d, ", arr[i]);
    }
    // printUnique(arr, n);
    puts("******");
    printf("%s", "Would you like to continue? Type n for no:\t");
    choice = getchar();
  }

  puts("Thanks!:)");
  puts("******");
  return 0;
}

void sort(int arr[], int size) {
  int temp;

  for(int i = 0;i < size - 1;i++) {

    for(int j = 0;j < size - i - 1;j++) {

      if(arr[j] < arr[j + 1]) {

        // Swap values.
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int getInt() {
  char input[100];
  int num;
  
  
  while(1) {
    if(scanf("%d%*c", &num)) {
      if(num < 1) {
        puts("The input value is incorrect, please try again…");
        puts("******");
        continue;
      }
      break;
    }
    // This runs if the user didn't even enter a number at all.
    else {
      scanf("%s", input);
      puts("Invalid input. Please try again:");
      puts("******");
    }
  }

  return num;
}