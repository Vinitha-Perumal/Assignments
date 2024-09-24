// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Palindrome_test.c
// Program to test the decimal conversion.
// ------------------------------------------------------------------------------------------------
#pragma warning (disable:4996)
#include "Palindrome.h"
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

int IsValid (const char* str);
void PrintRes (const char* input, const char* expectedOutput, int actualOutput);
void PalindromeTest ();
void ReverseNumPalindromeTest ();
void UserInput ();

int IsValid (const char* str) {
   if (*str == '\0' || str == NULL) return 0;
   if (*str == '-') str++;
   while (*str) {
      if (!isdigit ((unsigned char)*str)) return 0;
      str++;
   }
   return 1;
}

void PrintRes (const char* input, const char* expectedOutput, int actualOutput) {
   const char* actualRes = actualOutput ? "Palindrome" : "Not a Palindrome";
   const char* res = (strcmp (actualRes, expectedOutput) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
   printf ("| %-30s | %-20s | %-20s | %-27s |\n", input, expectedOutput, actualRes, res);
}

void PalindromeTest () {
   char* input1[] = { "vini", "I did,did I", "Ma*)d(*am", "Was it a car or a cat I saw?", "Hello", "Don't nod" };
   char* expectedOutput1[] = { "Not a Palindrome", "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome", "Palindrome" };
   int testCount = sizeof (input1) / sizeof (input1[0]);
   printf ("------Palindrome Check------\n"
           "| %-30s | %-20s | %-20s | %-10s |\n"
           "|--------------------------------|----------------------|----------------------|------------------|\n",
           "Input", "Expected Output", "Actual Output", "Test Case Result");
   int i = 0, actualOutput;
   for (i = 0; i < testCount; i++) {
      actualOutput = PalindromeCheck (input1[i]);
      PrintRes (input1[i], expectedOutput1[i], actualOutput);
   }
   printf ("\n\n");
}

void ReverseNumPalindromeTest () {
   char* input2[] = { "123", "4334", "654", "34543", "-121","*-23" ,"?@343", "6", " " };
   char* expectedOutput2[] = { "Not a Palindrome", "Palindrome", "Not a Palindrome", "Palindrome", "Not a Palindrome","Invalid Input","Invalid Input", "Palindrome", "Invalid Input" };
   int testCount = sizeof (input2) / sizeof (input2[0]);
   printf ("------ReverseNumber Palindrome Check------\n"
           "| %-30s | %-20s | %-20s | %-10s |\n"
           "|--------------------------------|----------------------|----------------------|------------------|\n",
           "Input", "Expected Output", "Actual Output", "Test Case Result");
   int i = 0, num, reversed = 0, actualOutput;
   for (i = 0; i < testCount; i++) {
      if (!IsValid (input2[i])) {
         const char* actualRes = "Invalid Input";
         const char* res = (strcmp (actualRes, expectedOutput2[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
         printf ("| %-30s | %-20s | %-20s | %-27s |\n", input2[i], expectedOutput2[i], actualRes, res);
         continue;
      }
      num = atoi (input2[i]), actualOutput = ReverseNumber (num, &reversed);
      PrintRes (input2[i], expectedOutput2[i], actualOutput);
   }
   printf ("\n\n");
}

void UserInput () {
   char input[100], numStr[100];
   printf ("\nEnter a word or phrase: ");
   if (fgets (input, sizeof (input), stdin)) {
      input[strcspn (input, "\n")] = '\0'; // Remove newline character if present
      input[0] == '\0' ? printf ("Empty String\n") : printf (PalindromeCheck (input) ? "Palindrome\n" : "Not a Palindrome\n");
   }
   printf ("\nEnter a number: ");
   if (fgets (numStr, sizeof (numStr), stdin)) {
      numStr[strcspn (numStr, "\n")] = '\0';
      char* endPtr;
      errno = 0;  // Clear errno before conversion
      long num = strtol (numStr, &endPtr, 10);
      int reversed = 0, isPalindrome;
      if (endPtr == numStr || *endPtr != '\0') printf ("Invalid input!\n");
      else if (errno == ERANGE || num > INT_MAX || num < INT_MIN) printf (RED_TEXT "Overflow: The number is out of the valid range.\n" RESET_TEXT);
      else {
         isPalindrome = ReverseNumber ((int)num, &reversed);
         printf (num < 0 ? "Not a Palindrome\n" : (reversed > INT_MAX || reversed < 0) ? "Overflow\n" : "Reversed Number : %d\n%s\n", reversed, isPalindrome ? "Palindrome\n" : "Not a Palindrome\n");
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