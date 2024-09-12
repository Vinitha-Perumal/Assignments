// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// test.c
// Program to test the decimal conversion.
// ------------------------------------------------------------------------------------------------
#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> 
#include "conversion.h"

#define INVALID_INPUT "Invalid Input"
// ANSI color code for green and red text
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

int IsValid (const char* n) {
   if (n == NULL || *n == '\0') return 0;
   char* endptr;
   long num = strtol (n, &endptr, 10);
   if (*endptr != '\0' || num < INT_MIN || num > INT_MAX) return 0;
   return 1;
}

void PrintResult (const char* result) {
   int padding = 100 - (int)strlen (result) - 1;
   for (int i = 0; i < padding; i++) printf (" ");
   printf ("%s\n", result);
}

void DecToBinaryTest () {
   char* input[] = { "0", "5", "255", "-255", "2147483647", "-2147483647", "*", "abc56" };
   char* expected_output[] = { "00000000", "00000101", "0000000011111111", "1111111100000001",
                               "01111111111111111111111111111111", "10000000000000000000000000000001",
                               "Invalid Input", "Invalid Input" };
   int testCount = sizeof (input) / sizeof (input[0]);
   printf ("---Decimal to Binary---\n\n");
   printf ("| %-12s | %-35s | %-40s | %-19s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("|--------------|-------------------------------------|------------------------------------------|---------------------|\n");
   for (int i = 0; i < testCount; i++) {
      char* actualBinary = IsValid (input[i]) ? DecToBinary (atoi (input[i])) : INVALID_INPUT;
      const char* result = (strcmp (actualBinary, expected_output[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-12s | %-35s | %-40s | %-30s |\n", input[i], expected_output[i], actualBinary, result);
   }
   printf ("\n\n");
}

void DecToHexaTest () {
   char* input2[] = { "0", "5", "255", "-255", "2147483647", "-2147483647", "*", "vini" };
   char* expected_output[] = { "00", "05", "00FF", "FF01","7FFFFFFF", "80000001","Invalid Input", 
                               "Invalid Input" };
   int testCount = sizeof (input2) / sizeof (input2[0]);
   printf ("---Decimal to Hexadecimal---\n\n");
   printf ("| %-12s | %-20s | %-20s | %-20s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("|--------------|----------------------|----------------------|----------------------|\n");
   for (int i = 0; i < testCount; i++) {
      char* actualHexa = IsValid (input2[i]) ? DecToHexa (atoi (input2[i])) : INVALID_INPUT;
      const char* result = (strcmp (actualHexa, expected_output[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-12s | %-20s | %-20s | %-31s |\n", input2[i], expected_output[i], actualHexa, result);
   }
}

void UserInput () {
   long long number;
   char nextChar;
   while (1) {
      printf ("\nEnter a decimal number: ");
      if (scanf_s ("%lld%c", &number, &nextChar, 1) != 2 || nextChar != '\n') {
         printf (RED_TEXT "\nInvalid input. Please enter a valid integer.\n" RESET_TEXT);
         while (getchar () != '\n');
      }
      else {
       // Check if the number is within 32-bit integer range
         if (number > INT_MAX || number < INT_MIN) printf (RED_TEXT "\nNumber out of 32-bit range.\n" RESET_TEXT);
         else {
            int num = (int)number; // Cast to 32-bit integer
            printf ("\nBinary: %s\nHexadecimal: %s\nHexadecimal(Inbuilt): %X\n ", DecToBinary (num), DecToHexa (num), num);
         }
         break;
      }
   }
}

int main () {
   int choice;
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\nEnter your choice (1 or 2 or 3):");
      scanf_s ("%d", &choice);
      switch (choice) {
         case 1:
            DecToBinaryTest ();
            DecToHexaTest ();
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
