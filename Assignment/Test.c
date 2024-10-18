// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Test.c
// Program on A5 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Program.h"

// ANSI color code
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

int CompareArr (int arr1[], int arr2[], int size);
void TestCases ();
void UserInput ();

int CompareArr (int arr1[], int arr2[], int size) {
   for (int i = 0; i < size; i++) if (arr1[i] != arr2[i]) return 0;
   return 1;
}

void TestCases () {
   int input[][6] = { { 12, 2, 34, 6, 22, 13 }, { 2, 20, 23, 12, 54, 3 }, { 6, 5, 4, 3, 2, 1 },
                      { 3, 5, 6, 65, 78, 90 }, { 3, 3, 3, 3, 3, 3 }, { -2, -5, -15, 10, -3, -5 } },
      expOutput[][6] = { { 2, 6, 12, 13, 22, 34 }, { 2, 3, 12, 20, 23, 54 }, { 1, 2, 3, 4, 5, 6 },
                         { 3, 5, 6, 65, 78, 90 }, { 3, 3, 3, 3, 3, 3 },
                         { -15, -5, -5, -3, -2, 10 } };
   int numOfTestCases = (int)sizeof (input) / sizeof (input[0]),
      size = (int)sizeof (input[0]) / sizeof (input[0][0]);
   printf ("\n\t\t\t\tTestcases for Insertion Sort\n\n"
           "\tInput\t\t\t\tOutput\t\t\tTest Case Result\n"
           " |--------------------------|--------------------------|"
           "---------------------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      int actualOutput[6] = { 0 };
      for (int j = 0; j < size; j++) actualOutput[j] = input[i][j];
      InsertionSort (actualOutput, size);
      printf (" | ");
      for (int j = 0; j < size; j++) printf ("%-3d ", input[i][j]);
      printf (" | ");
      for (int j = 0; j < size; j++) printf ("%-3d ", expOutput[i][j]);
      printf (" | ");
      const char* result = CompareArr (actualOutput, expOutput[i], size) ?
         GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "fail" RESET_TEXT;
      int padding = (30 - strlen (result)) / 2; // Calculate left padding
      printf ("%*s%20s%*s   |\n", padding, "", result, padding, "");
   }
   printf ("\n\t\t\t\tTest Cases for Binary Search\n\n"
           "\tInput\t\t\t\tOutput\t\t  Key\t\tResult\n"
           " |--------------------------|--------------------------|------|-----------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      printf (" | ");
      for (int j = 0; j < size; j++) printf ("%-3d ", input[i][j]);
      printf (" | ");
      for (int j = 0; j < size; j++) printf ("%-3d ", expOutput[i][j]);
      int Keys[] = { 3, 25, -1, 65, 3, -10 };
      printf (" | %-3d ", Keys[i]);
      printf (" | ");
      int foundIndex = BinarySearch (expOutput[i], size, Keys[i]);
      const char* res = (foundIndex != -1) ? GREEN_TEXT "Found" RESET_TEXT
         : RED_TEXT "Not Found" RESET_TEXT;
      printf ("%26s |\n", res);
   }
}

void UserInput () {
   int arr[100] = { 0 }, n;
   char buffer[256], * endptr;
   while (1) {
      printf ("Enter number of elements: ");
      fgets (buffer, sizeof (buffer), stdin);
      n = strtol (buffer, &endptr, 10);
      // Check for valid input
      if (endptr != buffer && *endptr == '\n' && n > 0 && n <= 100) break; // Valid input, exit loop
   }
   for (int i = 0; i < n; i++) {
      printf ("Enter element %d: ", i + 1);
      fgets (buffer, sizeof (buffer), stdin);
      arr[i] = strtol (buffer, &endptr, 10);
      if (endptr == buffer || *endptr != '\n') i--;
   }
   printf ("Original array: ");
   for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
   printf ("\n");
   InsertionSort (arr, n);
   printf ("Sorted array: ");
   for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
   printf ("\n");
   int key;
   while (1) {
      printf ("Enter element to search: ");
      fgets (buffer, sizeof (buffer), stdin);
      key = strtol (buffer, &endptr, 10);
      if (endptr != buffer && *endptr == '\n') break; // Valid input, exit loop
   }
   int res = BinarySearch (arr, n, key);
   printf ((res != -1) ? "Element %d found at index %d\n" : "Element %d is not found\n", key, res);
}

int main () {
   char choice;  // Variable to hold a single character choice
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\n"
              "Enter your choice (1 or 2 or 3) : ");
      choice = _getch ();
      printf ("%c\n", choice);
      if (choice == '1' || choice == '2' || choice == '3') {
         switch (choice) {
            case '1':
               TestCases ();
               break;
            case '2':
               UserInput ();
               break;
            case '3':
               return 0;
         }
      }
      else printf (RED_TEXT "Invalid choice. Please choose 1, 2, or 3.\n" RESET_TEXT);
   }
   return 0;
}