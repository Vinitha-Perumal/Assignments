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
#include <stdbool.h>
#include "Program.h"

// ANSI color code
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int CompareArr (int arr1[], int arr2[], int size);
void TestCases ();
int GetInputElement (int index);
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
   int row0Input[] = { 12, 2, 34, 22, 13 }, row1Input[] = { 6, 23, 20, 12 },
      row2Input[] = { 6, 5, 4, 3, 2, 1 }, row3Input[] = { 3, 5, 65 },
      row4Input[] = { 3, 7, -20, 56, 20, 2 }, row5Input[] = { -2, -5, -10, 10, -3, -5 },
      row0Expected[] = { 2, 12, 13, 22, 34 }, row1Expected[] = { 6, 12, 20, 23 },
      row2Expected[] = { 1, 2, 3, 4, 5, 6 }, row3Expected[] = { 3, 5, 65 },
      row4Expected[] = { -20, 2, 3, 7, 20, 56 }, row5Expected[] = { -10, -5, -5, -3, -2, 10 },
      * input[] = { row0Input, row1Input, row2Input, row3Input, row4Input, row5Input },
      * expOutput[] = { row0Expected, row1Expected, row2Expected, row3Expected, row4Expected,
      row5Expected }, numOfTestCases = (int)sizeof (input) / sizeof (input[0]),
      sizes[] = { ARR_SIZE (row0Input), ARR_SIZE (row1Input), ARR_SIZE (row2Input),
                  ARR_SIZE (row3Input), ARR_SIZE (row4Input), ARR_SIZE (row5Input) };
   printf ("\n\t\t\t\tTestcases for Insertion Sort\n\n"
           "\tInput\t\t\t\tOutput\t\t\tTest Case Result\n |--------------------------|"
           "--------------------------|--------------------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      int size = sizes[i], * actualOutput = malloc (size * sizeof (int));
      if (actualOutput == NULL) {
         fprintf (stderr, "memory allocation failed");
         return;
      }
      for (int j = 0; j < size; j++) actualOutput[j] = input[i][j];
      InsertionSort (actualOutput, size);
      PrintTable (input[i], size, 6);
      PrintTable (expOutput[i], size, 6);
      const char* result = CompareArr (actualOutput, expOutput[i], size) ?
         GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "fail" RESET_TEXT;
      int padding = (30 - strlen (result)) / 2; // Calculate left padding
      printf (" |%*s%20s%*s   |\n", padding, "", result, padding, "");
      free (actualOutput);
   }
   printf ("\n\t\t\t\tTest Cases for Binary Search\n\n"
           "\tInput\t\t\t\tOutput\t\t  Key\t\tIndex\t\tTest Case Result\n |--------------------------|"
           "--------------------------|------|-----------------------|------------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      int size = sizes[i], * actualOutput = malloc (size * sizeof (int)), expectedIndex = -1,
         keys[] = { 3, 25, -1, 65, 2, -10 }, foundIndex = BinarySearch (expOutput[i], size, keys[i]);
      PrintTable (input[i], size, 6);
      PrintTable (expOutput[i], size, 6);
      for (int j = 0; j < size; j++) {
         if (expOutput[i][j] == keys[i]) {
            expectedIndex = j;
            break;
         }
      }
      printf (" | %-3d  |", keys[i]);
      if (foundIndex != -1) {
         printf (GREEN_TEXT "Element %3d found at %d " RESET_TEXT, keys[i], foundIndex);
         printf ("|");
         printf ((foundIndex == expectedIndex) ? GREEN_TEXT "    pass"  RESET_TEXT :
                 RED_TEXT "    fail" RESET_TEXT);
      }
      else {
         printf (RED_TEXT "Element %3d Not Found " RESET_TEXT, keys[i]);
         printf (" |");
         printf ((expectedIndex == -1) ? GREEN_TEXT "    pass" RESET_TEXT :
                 RED_TEXT "    fail" RESET_TEXT);
      }
      printf ("          |\n");
      free (actualOutput);
   }
}

int GetInputElement (int index) {
   char buffer[256], * endptr;
   while (true) {
      printf ("Enter element %d: ", index + 1);
      fgets (buffer, sizeof (buffer), stdin);
      int element = strtol (buffer, &endptr, 10);
      if (endptr != buffer && *endptr == '\n') return element;
      else printf ("Invalid input, please enter a valid integer.\n");
   }
}

void UserInput () {
   int arr[100] = { 0 }, n;
   char buffer[256], * endptr;
   while (true) {
      printf ("Enter number of elements: ");
      fgets (buffer, sizeof (buffer), stdin);
      n = strtol (buffer, &endptr, 10);
      if (endptr != buffer && *endptr == '\n' && n > 0 && n <= 100) break;
   }
   for (int i = 0; i < n; i++) arr[i] = GetInputElement (i);
   printf ("Original array: ");
   for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
   printf ("\n");
   InsertionSort (arr, n);
   printf ("Sorted array: ");
   for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
   printf ("\n");
   while (true) {
      char searchChoice;
      printf ("Do you want Search (y|n)? : ");
      searchChoice = _getch ();
      printf ("%c\n", searchChoice);
      if (searchChoice == 'y' || searchChoice == 'Y') {
         printf ("Enter element to search: ");
         fgets (buffer, sizeof (buffer), stdin);
         int key = strtol (buffer, &endptr, 10), res = BinarySearch (arr, n, key);
         if (endptr != buffer && *endptr == '\n') {
            printf (res != -1 ? "Element %d found at index %d\n"
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
   char choice;
   while (true) {
      printf ("\n1. User Input\n2. Exit the program\n"
              "Enter your choice (1 or 2 ) : ");
      choice = _getch ();
      printf ("%c\n", choice);
      system ("cls");
      switch (choice) {
         case '1':
            UserInput ();
            break;
         case '2':
            return 0;
         default:
            printf (RED_TEXT "Invalid choice. Please choose 1, 2\n" RESET_TEXT);
            break;
      }
   }
   return 0;
}