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
   int input[][6] = { { 12, 2, 34, 6, 22, 13 }, { 2, 20, 23, 12, 54, 3 } };
   int expOutput[][6] = { { 2, 6, 12, 13, 22, 34 }, { 2, 3, 12, 20, 23, 54 } };
   int numOfTestCases = sizeof (input) / sizeof (input[0]);
   int size = sizeof (input[0]) / sizeof (input[0][0]);
   printf ("\n-------Testcases for Insertion Sort------\n\n"
           "\tInput\t\t\t\tOutput\t\t\tTest Case Result\n"
           " |--------------------------|--------------------------|"
           "------------------------------|\n");
   for (int i = 0; i < numOfTestCases; i++) {
      int actualOutput[6] = { 0 };
      for (int j = 0; j < size; j++) actualOutput[j] = input[i][j];
      InsertionSort (actualOutput, size);
      printf (" | ");
      for (int j = 0; j < size; j++) printf ("%-3d ", input[i][j]);
      printf (" | ");
      for (int j = 0; j < size; j++) printf ("%-3d ", expOutput[i][j]);
      printf (" | ");
      printf ("%-40s|", CompareArr (actualOutput, expOutput[i], size) ?
              GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "fail" RESET_TEXT);
      printf ("\n");
   }
}

void UserInput () {
   int arr[100] = { 0 }, n;
   char buffer[256], * endptr;
   printf ("Enter number of elements: "); //Get No. of elements 
   fgets (buffer, sizeof (buffer), stdin);
   n = strtol (buffer, &endptr, 10);
   printf ("Enter %d elements: ", n);
   for (int i = 0; i < n; i++) {
      fgets (buffer, sizeof (buffer), stdin);
      arr[i] = strtol (buffer, &endptr, 10);
   }
   printf ("Original array: ");
   for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
   printf ("\n");
   InsertionSort (arr, n);
   printf ("Sorted array: ");
   for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
   printf ("\n");
   int key;
   printf ("Enter element to search: ");
   fgets (buffer, sizeof (buffer), stdin);
   key = strtol (buffer, &endptr, 10);
   int res = BinarySearch (arr, n, key);
   printf ((res != -1) ? "Element %d found at index %d\n" : "Element %d is not found\n", key, res);
}

int main () {
   int choice;
   char buffer[256]; // Buffer to hold invalid input
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\n"
              "Enter your choice (1 or 2 or 3) : ");
      if (fgets (buffer, sizeof (buffer), stdin) != NULL) {
         char* endptr;
         choice = strtol (buffer, &endptr, 10);
         if (*endptr == '\0' || *endptr == '\n') {
            switch (choice) {
               case 1:
                  TestCases ();
                  break;
               case 2:
                  UserInput ();
                  break;
               case 3:
                  printf ("Exit the program\n");
                  return 0;
               default:
                  printf (RED_TEXT "Invalid choice. Please choose 1, 2, or 3.\n" RESET_TEXT);
                  break;
            }
         }
         else printf (RED_TEXT "Invalid choice. Please enter a valid integer.\n" RESET_TEXT);
      }
   }
   return 0;
}