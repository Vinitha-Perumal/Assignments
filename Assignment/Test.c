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
#include <malloc.h>
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
void PrintTable (int* arr, int arrSize, int columns);

void PrintTable (int* arr, int arrSize, int columns) {
   printf (" | ");
   for (int j = 0; j < arrSize; j++) printf ("%3d ", arr[j]);
   for (int j = columns - arrSize; j > 0; j--) printf ("%-3s ", "");
}

int CompareArr (int arr1[], int arr2[], int size) {
   for (int i = 0; i < size; i++) if (arr1[i] != arr2[i]) return 0;
   return 1;
}

void TestCases () {
   int* input[] = { (int[]) { 12, 2, 34, 22, 13 }, (int[]) { 6, 23, 20, 12 },
                    (int[]) { 6, 5, 4, 3, 2, 1 }, (int[]) { 3, 5, 65 },
                    (int[]) { 3, 3, 3, 3, 3, 3 }, (int[]) { -2, -5, -10, 10, -3, -5 } },
     * expOutput[] = { (int[]) { 2, 12, 13, 22, 34 }, (int[]) { 6, 12, 20, 23 },
                       (int[]) { 1, 2, 3, 4, 5, 6 }, (int[]) { 3, 5, 65 },
                       (int[]) { 3, 3, 3, 3, 3, 3 }, (int[]) { -10, -5, -5, -3, -2, 10 } };
   int numOfTestCases = (int)sizeof (input) / sizeof (input[0]), size[] = { 5, 4, 6, 3, 6, 6 };
   printf ("\n\t\t\t\tTestcases for Insertion Sort\n\n"
           "\tInput\t\t\t\tOutput\t\t\tTest Case Result\n |--------------------------|"
           "--------------------------|--------------------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      int* actualOutput = malloc (size[i] * sizeof (int));
      if (actualOutput == NULL) {
         fprintf (stderr, "memory allcoation failed");
         return;
      }
      for (int j = 0; j < size[i]; j++) actualOutput[j] = input[i][j];
      InsertionSort (actualOutput, size[i]);
      PrintTable (input[i], size[i], 6);
      PrintTable (expOutput[i], size[i], 6);
      const char* result = CompareArr (actualOutput, expOutput[i], size[i]) ?
         GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "fail" RESET_TEXT;
      int padding = (30 - strlen (result)) / 2; // Calculate left padding
      printf (" |%*s%20s%*s   |\n", padding, "", result, padding, "");
      free (actualOutput);
   }
   printf ("\n\t\t\t\tTest Cases for Binary Search\n\n"
           "\tInput\t\t\t\tOutput\t\t  Key\t\tResult\n |--------------------------|"
           "--------------------------|------|------------------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      int* actualOutput = malloc (size[i] * sizeof (int));
      PrintTable (input[i], size[i], 6);
      PrintTable (expOutput[i], size[i], 6);
      int Keys[] = { 3, 25, -1, 65, 3, -10 },
         foundIndex = BinarySearch (expOutput[i], size[i], Keys[i]);
      printf (" | %-3d  | ", Keys[i]);
      printf (foundIndex != -1 ? GREEN_TEXT "Element %3d found at %d" RESET_TEXT
              : RED_TEXT "Element %3d Not Found " RESET_TEXT, Keys[i], foundIndex);
      printf (" |\n");
      free (actualOutput);
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
      if (endptr != buffer && *endptr == '\n' && n > 0 && n <= 100) break; // Valid input,exit loop
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
   while (1) {
      char searchChoice;
      printf ("Do you want Search (y|n)? : ");
      searchChoice = _getch ();
      printf ("%c\n", searchChoice);
      if (searchChoice == 'y' || searchChoice == 'Y') {
         printf ("Enter element to search: ");
         fgets (buffer, sizeof (buffer), stdin);
         int key = strtol (buffer, &endptr, 10), res = BinarySearch (arr, n, key);
         if (endptr != buffer && *endptr == '\n') {
            printf ((res != -1) ? "Element %d found at index %d\n"
                    : "Element %d is not found\n", key, res);
            break;
         }
         else printf (RED_TEXT "Invalid Input,enter valid number\n" RESET_TEXT);
      }
      else if (searchChoice == 'n' || searchChoice == 'N') break;
      else printf (RED_TEXT "Invalid choice, please enter valid choice \n" RESET_TEXT);
   }
}

int main () {
   TestCases ();
   char choice;  // Variable to hold a single character choice
   while (1) {
      printf ("\n1. User Input\n2. Exit the program\n"
              "Enter your choice (1 or 2 ) : ");
      choice = _getch ();
      printf ("%c\n", choice);
      system ("cls");
      if (choice == '1' || choice == '2') {
         switch (choice) {
            case '1':
               UserInput ();
               break;
            case '2':
               return 0;
         }
      }
      else printf (RED_TEXT "Invalid choice. Please choose 1, 2\n" RESET_TEXT);
   }
   return 0;
}