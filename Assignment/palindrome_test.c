// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Palindrome_test.c
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

int IsValidNum (const char* num);
void TestCases ();
void UserInput ();

/// <summary>To check if the input number is valid</summary>
int IsValidNum (const char* num) {
   if (*num == '\0' || num == NULL) return 0;
   if (*num == '-') num++;
   while (*num) {
      if (!isdigit ((unsigned char)*num)) return 0;
      num++;
   }
   return 1;
}

void TestCases () {
   char* inputs[] = { "vini", "I did,did I", "Ma*)d(*am", "@@@##!!!", "Mam!",
                      "Was it a car or a cat I saw?", "Don't nod", "Hello",
                      "4334", "2147447412", "34543", "-121", "*-23" ,"?@343", "6", " " },
      * expOutputs[] = { "Not a Palindrome", "Palindrome", "Palindrome", "Invalid Input",
                             "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome",
                             "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome",
                             "Invalid Input", "Invalid Input", "Palindrome", "Invalid Input" };
   int numOfTestCases = sizeof (inputs) / sizeof (inputs[0]);
   printf ("\n-------Testcases for String and Integer Input------\n\n"
           "| %-30s | %-30s | %-20s | %-20s | %-10s |\n"
           "|--------------------------------|--------------------------------|"
           "----------------------|----------------------|------------------|\n",
           "Input", "Reverse", "Expected Output", "Actual Output", "Test Case Result");
   for (int i = 0; i < numOfTestCases; i++) {
      char* input = inputs[i];
      char reversedInput[100] = { 0 };
      int len = strlen (input), reversed = 0, num = atoi (inputs[i]),
         actualOutput = IsValidNum (input) ? ReverseNumber (num, &reversed), num == reversed :
         PalindromeCheck (input);
      for (int j = 0; j < len; j++) reversedInput[j] = input[len - j - 1];
      reversedInput[len] = '\0';
      const char* isPal = actualOutput == -1 ? "Invalid Input"
         : actualOutput ? "Palindrome" : "Not a Palindrome",
         * res = !strcmp (isPal, expOutputs[i]) ?
         GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-30s | %-30s | %-20s | %-20s | %-27s |\n", input, reversedInput, expOutputs[i],
              isPal, res);
   }
   printf ("\n\n");
}

void UserInput () {
   char input[100];
   printf ("\nEnter a word or number: ");
   fgets (input, sizeof (input), stdin);
   input[strcspn (input, "\n")] = '\0';
   if (IsValidNum (input)) {
      char* endPtr;
      errno = 0;
      long num = strtol (input, &endPtr, 10);
      if (endPtr == input || *endPtr != '\0') printf ("Invalid Input\n");
      else if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
         printf (RED_TEXT "Overflow: The number is out of the valid range.\n" RESET_TEXT);
      else {
         if (num < 0) printf ("Not a Palindrome\n");
         else {
            int reversed = 0;
            ReverseNumber ((int)num, &reversed);
            printf ("Reversed Number: %d\n%s\n", reversed, reversed > INT_MAX ? "Overflow"
                    : num == reversed ? "Palindrome" : "Not a Palindrome");
         }
      }
   }
   else {
      int res = PalindromeCheck (input);
      printf (res == -1 ? "Invalid Input\n" : res ? "Palindrome\n" : "Not a Palindrome\n");
   }
}

int main () {
   int choice;
   char buffer[100];
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\n"
              "Enter your choice (1 or 2 or 3) : ");
      if (fgets (buffer, sizeof (buffer), stdin) == NULL) continue;
      char* endptr;
      choice = strtol (buffer, &endptr, 10);
      if (*endptr != '\0' && *endptr != '\n') {
         printf (RED_TEXT "Invalid choice. again choose 1, 2 or 3.\n" RESET_TEXT);
         continue;
      }
      switch (choice) {
         case 1:
            TestCases ();
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
   return 0;
}