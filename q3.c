/*
Program: q3.c
Author: Justin Bornais
Date: December 12, 2020
*/

#include <stdio.h>

void append(char str[]);
void replace(char str[], int start, int end);

int main(void) {
  char source[60];
  char keyword[15];

  printf("\n");
  puts("Please enter a string:");
  scanf("%60s", source);

  puts("Please enter your search word:");
  scanf("%15s", keyword);

  puts("******");

  int len1, len2;
  for(len1 = 0;source[len1] != '\0';len1++); // Get length of source string.
  for(len2 = 0;keyword[len2] != '\0';len2++); // Get length of keyword.

  int count = 0;
  int start = 0;
  int end = 0;

  for(int i = 0;i < len1;i++) {

    if(source[i] == keyword[count]) {
      if(count == 0) {
        // Reset start and end variables.
        start = i;
        end = i;
      }
      else {
        end++; // Increment end.
      }
      count++; // Increment count so the program can interpret the next characters in the keyword.
    }
    else {
      if(count == len2) {
        break; // The keyword was found so exit the loop.
      }
      // This code will only be reached if the keyword has not been found yet.
      count = 0;
      start = 0;
      end = 0;
    }
  }

  if(count == len2) {
    printf("The keyword, %s, has been found in the given string. :)\n", keyword);
    puts("******");
    printf("The new string is:\t");
    replace(source, start, end);
  }
  else {
    printf("The keyword, %s, was not found in the given string. :(\n", keyword);
    puts("******");
    printf("The new string is:\t");
    append(source);
  }

  return 0;
}

void replace(char str[], int start, int end) {
  int length = 0, length2, tempIndex = 1;

  for(length = 0;str[length] != '\0';length++); // Get length of the string.

  length2 = length + 6 - (end - start);

  char newString[length2];
  char name[] = "Justin";

  // Add normal string up to start.
  for(int i = 0;i < start;i++) {
    newString[i] = str[i];
  }

  // Add Justin.
  for(int i = start;i < start + 6;i++) {
    newString[i] = name[i - start];
  }

  // Go from start to the end of the string.
  for(int i = start + 6;i < length2;i++) {
    newString[i] = str[end + tempIndex];
    tempIndex++;
  }

  // Print the string.
  for(int i = 0;i < length2;i++) {
    printf("%c", newString[i]);
  }

  printf("\n");
}

void append(char str[]) {
  int length = 0, length2;
  for(length = 0;str[length] != '\0';length++);

  length2 = length + 6;

  char newString[length2]; // My first name Justin has 6 characters.
  char name[] = "Justin";

  // Add the first string.
  for(int i = 0;i < length;i++) {
    newString[i] = str[i];
  }

  // Add Justin.
  for(int i = length;i < length2;i++) {
    newString[i] = name[i - length];
  }

  // Print the string.
  for(int i = 0;i < length2;i++) {
    printf("%c", newString[i]);
  }

  printf("\n");
}