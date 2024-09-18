// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// palindrome_test.c
// Program to test the decimal conversion.
// ------------------------------------------------------------------------------------------------

#pragma warning (disable:4996)
#include "palindrome.h"
#include <stdio.h>
#include <string.h> 
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

#define INVALID_INPUT "Invalid Input"
// ANSI color code
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

void PalindromeTest ();
void ReverseNumPalindromeTest ();
void UserInput ();
int IsValid (const char* str);

int IsValid (const char* str) {
   if (*str == '\0' || str == NULL) return 0;
   if (*str == '-') str++;
   while (*str) {
      if (!isdigit ((unsigned char)*str)) return 0;
      str++;
   }
   return 1;
}

void PalindromeTest () {
   char* input1[] = { "vini", "I did,did I", "Ma*)d(*am", "Was it a car or a cat I saw?", "Hello", "Don't nod" };
   char* expected_output[] = { "Not a Palindrome", "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome", "Palindrome" };
   int testCount = sizeof (input1) / sizeof (input1[0]);
   printf ("------Palindrome Check------\n");
   printf ("| %-30s | %-20s | %-20s | %-10s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("|--------------------------------|----------------------|----------------------|------------------|\n");
   for (int i = 0; i < testCount; i++) {
      int actualOutput = PalindromeCheck (input1[i]);
      const char* actualRes = actualOutput ? "Palindrome" : "Not a Palindrome";
      const char* res = (strcmp (actualRes, expected_output[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-30s | %-20s | %-20s | %-27s |\n", input1[i], expected_output[i], actualRes, res);
   }
   printf ("\n\n");
}

void ReverseNumPalindromeTest () {
   char* input2[] = { "123", "4334", "654", "34543", "-121","*-23" ,"?@343", "6", " " };
   char* expected_output2[] = { "Not a Palindrome", "Palindrome", "Not a Palindrome", "Palindrome", "Palindrome","Invalid Input","Invalid Input", "Palindrome", "Invalid Input" };
   int testCount = sizeof (input2) / sizeof (input2[0]);
   printf ("------ReverseNumber Palindrome Check------\n");
   printf ("| %-30s | %-20s | %-20s | %-10s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("|--------------------------------|----------------------|----------------------|------------------|\n");
   for (int i = 0; i < testCount; i++) {
      if (!IsValid (input2[i])) {
         printf ("| %-30s | %-20s | %-20s | %-27s |\n", input2[i], expected_output2[i], "Invalid Input", GREEN_TEXT "Pass" RESET_TEXT);
         continue;
      }
      int num = atoi (input2[i]), reversed = 0, actualOutput = ReverseNumber (num, &reversed);
      const char* actualRes = actualOutput ? "Palindrome" : "Not a Palindrome";
      const char* res = (strcmp (actualRes, expected_output2[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-30s | %-20s | %-20s | %-27s |\n", input2[i], expected_output2[i], actualRes, res);
   }
   printf ("\n\n");
}

void UserInput () {
   char input[100], numStr[100];
   printf ("\nEnter a word or phrase: ");
   if (fgets (input, sizeof (input), stdin)) {
      input[strcspn (input, "\n")] = '\0'; // Remove newline character if present
      printf (PalindromeCheck (input) ? "Palindrome\n" : "Not a Palindrome\n");
   }
   printf ("\nEnter a number: ");
   if (fgets (numStr, sizeof (numStr), stdin)) {
      numStr[strcspn (numStr, "\n")] = '\0';
      char* endPtr;
      errno = 0;  // Clear errno before conversion
      long num = strtol (numStr, &endPtr, 10);
      if (endPtr == numStr || *endPtr != '\0') printf ("Invalid input!\n");
      else if (errno == ERANGE || num > INT_MAX || num < INT_MIN) printf (RED_TEXT "Overflow: The number is out of the valid range.\n" RESET_TEXT);
      else {
         int reversed = 0, isPalindrome = ReverseNumber ((int)num, &reversed);
         if (reversed > INT_MAX || reversed < 0) printf ("Overflow\n");
         else {
            printf ("Reversed Number: %d\n", reversed);
            printf (isPalindrome ? "Palindrome\n" : "Not a Palindrome\n");
         }
      }
   }
}

int main () {
   int choice;
   char buffer[100];
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\nEnter your choice (1 or 2 or 3): ");
      if (fgets (buffer, sizeof (buffer), stdin) != NULL) {
         char* endptr;
         choice = strtol (buffer, &endptr, 10);
         if (*endptr == '\0' || *endptr == '\n') {
            switch (choice) {
               case 1:
                  PalindromeTest ();
                  ReverseNumPalindromeTest ();
                  break;
               case 2:
                  UserInput ();
                  break;
               case 3:
                  printf ("Exiting the program\n");
                  return 0;
               default:
                  printf (RED_TEXT "Invalid choice. again choose 1, 2 or 3.\n" RESET_TEXT);
                  break;
            }
         }
         else printf (RED_TEXT "Invalid choice. again choose 1, 2 or 3.\n" RESET_TEXT);
      }
   }
   return 0;
}