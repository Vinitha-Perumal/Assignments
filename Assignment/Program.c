// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.c
// Program on B2 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h> 

#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

bool CompareArr (int arr1[], int arr2[], int size);
void Fibonacci (int n, int fib[]);
void TestCases ();
void UserInput ();

bool CompareArr (int arr1[], int arr2[], int size) {
   for (int i = 0; i < size; i++) if (arr1[i] != arr2[i]) return false;
   return true;
}

void Fibonacci (int n, int fib[]) {
   if (n <= 0) return;
   fib[0] = 0, fib[1] = 1;
   for (int i = 2; i < n; i++) fib[i] = fib[i - 1] + fib[i - 2];
}

void TestCases () {
   int input[] = { 5, 2, 3, 6, 1 }, expOutput[][6] = { { 0, 1, 1, 2, 3 }, { 0, 1 }, { 0, 1, 1 }, { 0, 1, 1, 2, 3, 5 }, { 0 } },
      numOfTestCases = sizeof (input) / sizeof (input[0]);
   for (int i = 0; i < numOfTestCases; i++) {
      int actualOutput[10] = { 0 };
      Fibonacci (input[i], actualOutput);
      if (!CompareArr (actualOutput, expOutput[i], input[i])) {
         printf (RED_TEXT "TestCase %d Failed \n" RESET_TEXT "Expected: ", i + 1);
         for (int k = 0; k < input[i]; k++) printf ("%d ", expOutput[i][k]);
         printf ("\nActual Output: ");
         for (int k = 0; k < input[i]; k++) printf ("%d ", actualOutput[k]);
         printf ("\n");
         return;
      }
   }
   printf (GREEN_TEXT "All TestCases Passed\n" RESET_TEXT);
}

void UserInput () {
   char input[100];
   printf ("Enter the number: ");
   fgets (input, sizeof (input), stdin);
   input[strcspn (input, "\n")] = '\0';
   int n = atoi (input), fib[100];
   if (n <= 0) {
      printf (RED_TEXT "Invalid Input. please enter a Positive number.\n" RESET_TEXT);
      return;
   }
   if (n > 100) {
      printf (RED_TEXT "Input exceeds maximum allowed size of 100.\n" RESET_TEXT);
      return;
   }
   Fibonacci (n, fib);
   for (int i = 0; i < n; i++) printf ("%d ", fib[i]);
   printf ("\n");
}

int main () {
   char choice;
   while (true) {
      printf ("\n1.Test Cases\n2.User Input\n3.Exit the Program\nEnter Your choice: ");
      choice = _getch ();
      printf ("%c\n", choice);
      system ("cls");
      switch (choice) {
         case '1':
            TestCases ();
            break;
         case '2':
            UserInput ();
            break;
         case '3':
            return 0;
         default:
            printf (RED_TEXT "Invalid choice. please choose 1 or 2\n" RESET_TEXT);
            break;
      }
   }
   return 0;
}