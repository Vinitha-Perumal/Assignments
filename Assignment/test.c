// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// test.c
// Program to test the decimal conversion.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "conversion.h"

// ANSI color code for green and red text
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31"
#define RESET_TEXT "\033[0m"

void PrintResult (const char* result, int terminalWidth) {
   int padding = terminalWidth - (int)strlen (result) - 1;
   for (int i = 0; i < padding; i++) printf (" ");
   printf ("%s\n", result);
}

void DecToBinaryTest () {
   int input[] = { 0,5,255,-255,2147483647,-2147483647 };
   char* expected_output[] = {
      "00000000",
      "00000101",
      "11111111",
      "1111111100000001",
      "1111111111111111111111111111111",
      "10000000000000000000000000000001" };
   int testCount = sizeof (input) / sizeof (input[0]);
   int terminalWidth = 100;
   printf ("---Decimal to Binary---\n\n");
   for (int i = 0; i < testCount; i++) {
      char* actualBinary = DecToBinary (input[i]);
      printf ("Input %12d => ", input[i]);
      PrintResult ((strcmp (actualBinary, expected_output[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT, terminalWidth);
   }
   printf ("\n\n");
}

void DecToHexaTest () {
   int input2[] = { 0,5,255,-255,2147483647,-2147483647 };
   char* expected_output[] = {
      "00",
      "05",
      "FF",
      "FFFFFF01",
      "7FFFFFFF",
      "80000001" };
   int testCount = sizeof (input2) / sizeof (input2[0]);
   int terminalWidth = 100;
   printf ("---Decimal to Hexa---\n\n");
   for (int i = 0; i < testCount; i++) {
      char* actualhexa = DecToHexa (input2[i]);
      printf ("Input %12d => ", input2[i]);
      PrintResult ((strcmp (actualhexa, expected_output[i]) == 0) ? GREEN_TEXT "Pass" RESET_TEXT : RED_TEXT "Fail" RESET_TEXT, terminalWidth);
   }
}

void UserInput () {
   int number;
   printf ("Enter a decimal number: ");
   scanf_s ("%d", &number);
   printf ("\nBinary: %s\n", DecToBinary (number));
   printf ("Hexadecimal: %s\n", DecToHexa (number));
}

int main () {
   int choice;
   printf ("1. Test Cases\n");
   printf ("2. User Input\n");
   printf ("Enter your choice (1 or 2): ");
   scanf_s ("%d", &choice);
   switch (choice) {
      case 1:
         DecToBinaryTest ();
         DecToHexaTest ();
         break;
      case 2:
         UserInput ();
         break;
      default:
         printf ("Invalid choice. again choose 1 or 2.\n");
         break;
   }
   return 0;
}