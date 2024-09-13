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

#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

void PalindromeTest () {
   char* input1[] = { "vini", "I did,did I", "Ma*)d(*am", "Was it a car or a cat I saw?", "Hello", "Don't nod" };
   char* expected_output[] = { "Not a Palindrome", "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome", "Palindrome" };
   int testCount = sizeof (input1) / sizeof (input1[0]);
   printf ("------Palindrome Check------\n");
   printf ("| %-30s | %-20s | %-20s | %-10s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("---------------------------------|----------------------|----------------------|------------------\n");
   for (int i = 0; i < testCount; i++) {
      int actualOutput = PalindromeCheck (input1[i]);
      const char* actualRes = actualOutput ? "Palindrome" : "Not a Palindrome";
      const char* res = (strcmp (actualRes, expected_output[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-30s | %-20s | %-20s | %-27s |\n", input1[i], expected_output[i], actualRes, res);
   }
   printf ("\n\n");
}

void ReverseNumPalindromeTest () {
   int input2[] = { 123, 4334, 987876, 654, 34534, 34543 };
   char* expected_output2[] = { "Not a Palindrome", "Palindrome", "Not a Palindrome", "Not a Palindrome", "Not a Palindrome", "Palindrome" };
   int testCount = sizeof (input2) / sizeof (input2[0]);
   printf ("------ReverseNumber Palindrome Check------\n");
   printf ("| %-30s | %-20s | %-20s | %-10s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("---------------------------------|----------------------|----------------------|------------------|\n");
   for (int i = 0; i < testCount; i++) {
      int reversed;
      int actualOutput = reverseNumber (input2[i], &reversed);
      const char* actualRes = actualOutput ? "Palindrome" : "Not a Palindrome";
      const char* res = (strcmp (actualRes, expected_output2[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-30d | %-20s | %-20s | %-27s |\n", input2[i], expected_output2[i], actualRes, res);
   }
   printf ("\n\n");
}

void UserInput () {
   char input[100];
   int num;
   printf ("\nEnter a word or phrase: ");
   if (fgets (input, sizeof (input), stdin)) {
      input[strcspn (input, "\n")] = '\0';    // Remove newline character if present
      if (PalindromeCheck (input)) printf ("Palindrome\n");
      else printf ("Not a Palindrome\n");
   }
   printf ("\nEnter a number: ");
   scanf_s ("%d", &num);
   int reversed = { 0 };
   int isPalindrome = reverseNumber (num, &reversed);
   printf ("Reversed Number: %d\n", reversed);
   if (isPalindrome) printf ("Palindrome\n");
   else printf ("Not a palindrome\n");
}

int main () {
   int choice;
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\nEnter your choice (1 or 2 or 3):");
      scanf_s ("%d", &choice);
      int c;
      while ((c = getchar ()) != '\n' && c != EOF);
      switch (choice) {
         case 1:
            PalindromeTest ();
            ReverseNumPalindromeTest ();
            break;
         case 2:
            UserInput ();
            break;
         case 3:
            printf ("Exit the program \n");
            return 0;
         default:
            printf ("Invalid choice. again choose 1 or 2 or 3.\n");
            break;
      }
   }
   return 0;
}