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

// ANSII color code for green and red text
#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31"
#define RESET_TEXT "\033[0m"

void PrintRightAligned (const char* result, int terminalWidth) {
   int padding = terminalWidth - (int)strlen (result) - 1;  
   for (int i = 0; i < padding; i++) {
      printf (" ");  
   }
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
      "0000000000000001" };
   int testCount = sizeof (input) / sizeof (input[0]);
   char actualBinary[35];
   int terminalWidth = 100; 
   printf ("---Decimal to Binary---\n\n");
   for (int i = 0; i < testCount; i++) {
      DecToBinary (input[i], actualBinary);  
      printf ("Input %12d => ", input[i]);  
      // Check result and print at the rightmost corner
      if (strcmp (actualBinary, expected_output[i]) == 0) PrintRightAligned (GREEN_TEXT "Pass" RESET_TEXT, terminalWidth);
      else PrintRightAligned (RED_TEXT "Fail" RESET_TEXT, terminalWidth);
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
   char actualhexa[35];
   int terminalWidth = 100;
   printf ("---Decimal to Hexa---\n\n");
   for (int i = 0; i < testCount; i++) {
      DecToHexa (input2[i], actualhexa);
      printf ("Input %12d => ", input2[i]);
      // Check result and print at the rightmost corner
      if (strcmp (actualhexa, expected_output[i]) == 0) PrintRightAligned (GREEN_TEXT "Pass" RESET_TEXT, terminalWidth);
      else PrintRightAligned (RED_TEXT "Fail" RESET_TEXT, terminalWidth);
   }
}

int main () {
   DecToBinaryTest ();
   DecToHexaTest ();
   return 0;
}