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
#define BINARY_BUFFER_SIZE 33
#define HEXA_BUFFER_SIZE 9
// ANSI color code
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_TEXT "\033[0m"

int IsValid (const char* n);
void DecToBinaryTest ();
void DecToHexaTest ();
void UserInput ();

int IsValid (const char* n) {
   if (n == NULL || *n == '\0') return 0;
   char* endptr;
   long num = strtol (n, &endptr, 10);
   if (*endptr != '\0' || num < INT_MIN || num > INT_MAX) return 0;
   return 1;
}

void DecToBinaryTest () {
   const char* input[] = { "0", "5", "255", "-255", "2147483647", "-2147483647", "*", "abc56" };
   const char* expectedOutput[] = { "00000000", "00000101", "0000000011111111", "1111111100000001",
                                    "01111111111111111111111111111111", "10000000000000000000000000000001",
                                    INVALID_INPUT, INVALID_INPUT };
   int testCount = sizeof (input) / sizeof (input[0]);
   char actualBinary[BINARY_BUFFER_SIZE];
   printf ("---Decimal to Binary---\n\n");
   printf ("| %-12s | %-35s | %-40s | %-19s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("|--------------|-------------------------------------|------------------------------------------|---------------------|\n");
   for (int i = 0; i < testCount; i++) {
      int value = atoi (input[i]);
      char* actualBinaryOutput = IsValid (input[i]) ? DecToBinary (value, actualBinary) : INVALID_INPUT;
      const char* result = (strcmp (actualBinaryOutput, expectedOutput[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-12s | %-35s | %-40s | %-30s |\n", input[i], expectedOutput[i], actualBinaryOutput, result);
   }
   printf ("\n\n");
}

void DecToHexaTest () {
   const char* input2[] = { "0", "5", "255", "-255", "2147483647", "-2147483647", "*", "vini" };
   const char* expectedOutput[] = { "00", "05", "00FF", "FF01", "7FFFFFFF", "80000001", INVALID_INPUT, INVALID_INPUT };
   int testCount = sizeof (input2) / sizeof (input2[0]);
   char actualHexa[HEXA_BUFFER_SIZE];
   printf ("---Decimal to Hexadecimal---\n\n");
   printf ("| %-12s | %-20s | %-20s | %-20s |\n", "Input", "Expected Output", "Actual Output", "Test Case Result");
   printf ("|--------------|----------------------|----------------------|----------------------|\n");
   for (int i = 0; i < testCount; i++) {
      int value = atoi (input2[i]);
      char* actualHexaOutput = IsValid (input2[i]) ? DecToHexa (value, actualHexa) : INVALID_INPUT;
      const char* result = (strcmp (actualHexaOutput, expectedOutput[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT;
      printf ("| %-12s | %-20s | %-20s | %-31s |\n", input2[i], expectedOutput[i], actualHexaOutput, result);
   }
}

void UserInput () {
   char buffer[256]; // Buffer to hold user input
   int num, validInput = 0;
   while (!validInput) {
      printf ("\nEnter a decimal number: ");
      if (fgets (buffer, sizeof (buffer), stdin) != NULL) {
         size_t length = strlen (buffer);
         if (length > 0 && buffer[length - 1] == '\n') buffer[length - 1] = '\0';
         char* endptr;
         long long number = strtoll (buffer, &endptr, 10);
         if (*endptr == '\0' || *endptr == '\n') {
             // Check if the number is within 32-bit integer range
            if (number > INT_MAX || number < INT_MIN) printf (RED_TEXT "\nNumber out of 32-bit range.\n" RESET_TEXT);
            else {
               num = (int)number; // Cast to 32-bit integer
               char binary[BINARY_BUFFER_SIZE], hexa[HEXA_BUFFER_SIZE];
               printf ("\nBinary: %s\nHexadecimal: %s\nHexadecimal(Inbuilt): %X\n", DecToBinary (num, binary), DecToHexa (num, hexa), num);
               validInput = 1;
            }
         }
         else printf (RED_TEXT "\nInvalid input. Please enter a valid integer.\n" RESET_TEXT);
      }
   }
}

int main () {
   int choice;
   char buffer[256]; // Buffer to hold invalid input
   while (1) {
      printf ("\n1. Test Cases\n2. User Input\n3. Exit the program\nEnter your choice (1 or 2 or 3): ");
      if (fgets (buffer, sizeof (buffer), stdin) != NULL) {
         char* endptr;
         choice = strtol (buffer, &endptr, 10);
         if (*endptr == '\0' || *endptr == '\n') {
            switch (choice) {
               case 1:
                  DecToBinaryTest ();
                  DecToHexaTest ();
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