// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Conversion.c
// Program for Number Conversion.
// ------------------------------------------------------------------------------------------------

#pragma warning(disable:4996)
#include <stdio.h>
void DecToBinary (int n);
void DecToHexa (int n);

// Function to convert the decimal number to binary
void DecToBinary (int n) {
   int binary[32];
   int i = 0;
   int flag = 0; // Flag is to check if the number is negative
   if (n == 0)    printf ("binary is 0");
   if (n < 0) {
      n = -n;
      flag = 1;
   }
   while (n > 0) {
      binary[i] = n % 2;
      n = n / 2;
      i++;
   }
   // If the number was negative,apply two's complement
   if (flag) {
      for (int j = 0; j < i; j++)   binary[j] = 1 - binary[j]; // Invert the bits for 2's complement
      int carry = 1;
      for (int j = 0; j < i; j++) {
         binary[j] = binary[j] + carry;
         if (binary[j] == 2) {
            binary[j] = 0;
            carry = 1;
         }
         else {
            carry = 0;
            break;
         }
      }
      // If there is still a carry left, extend the binary array
      if (carry == 1) {
         binary[i] = 1;
         i++;
      }
   }
   for (int k = i - 1; k >= 0; k--)    printf ("%d", binary[k]);   
}

// Function to convert the decimal number to Hexadecimal
void DecToHexa (int n) {
   char hexa[32];
   int i = 0;
   if (n == 0)  printf ("Hexadecimal is 0");
   unsigned int num = (unsigned int)n;   // Handle negative numbers by using unsigned int
   while (num > 0) {
      int rem = num % 16;
      if (rem < 10)  hexa[i] = rem + '0';
      else  hexa[i] = rem - 10 + 'A';
      num = num / 16;
      i++;
   }
   for (int k = i - 1; k >= 0; k--)    printf ("%c", hexa[k]);
}

int main () {
   int number;
   printf ("Enter decimal Number: ");
   scanf ("%d", &number);
   printf ("Binary: ");
   DecToBinary (number);
   printf ("\nHexadecimal: ");
   DecToHexa (number);
   printf ("\n");
   return 0;
}