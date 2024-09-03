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
void DecimalToBinary (int n);
void DecToHexa (int n);
int mBitLength;

/// <summary>Decimal number to binary Conversion</summary>
void DecToBinary (int n) {
   int binary[32], i = 0, isNegative = 0; // Flag is to check if the number is negative
   if (n < 0) {
      n = -n;
      isNegative = 1;
   }
   while (n > 0) {
      binary[i++] = n % 2;
      n /= 2;
   }
   // If the number was negative,apply two's complement
   if (isNegative) {
      if (i <= 7) mBitLength = 8;
      else mBitLength = 16;
      for (int j = i; j < mBitLength; j++) binary[j] = 0;
      i = mBitLength;
      for (int j = 0; j < i; j++) binary[j] = 1 - binary[j]; // Invert the bits for 2's complement
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
   }
   else {
      mBitLength = (i <= 8) ? 8 : i;
      for (int j = i; j < mBitLength; j++) binary[j] = 0;
      i = mBitLength;
   }
   for (int k = i - 1; k >= 0; k--) printf ("%d", binary[k]);
}

/// <summary>Decimal number to Binary Conversion using Shift Operator</summary>
void DecimalToBinary (int n) {
   int numBits = sizeof (int) * 8; 
   int isNegative = (n < 0); // Check if the number is negative
   if (n >= -128 && n <= 127) mBitLength = 8;
   else mBitLength = 16;
   if (isNegative) n = ~(-n) + 1; // Compute two's complement
   unsigned int mask = 1 << (mBitLength - 1); // Create a mask to extract each bit
   for (int i = 0; i < mBitLength; i++) {
      printf ("%d", (n & mask) ? 1 : 0);
      mask >>= 1;
   }
   printf ("\n");
}

/// <summary>Decimal number to Hexadecimal Conversion</summary>
void DecToHexa (int n) {
   char hexa[32];
   int i = 0, isNegative = 0;  // Flag to check if the number is negative
   unsigned int num;
   if (n < 0) {
      num = (unsigned int)n;  // Handle negative numbers by using unsigned int
      isNegative = 1;
   }
   else num = (unsigned int)n;
   while (num > 0) {
      int rem = num % 16;
      hexa[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
      num /= 16;
   }
   int requiredDigits = (mBitLength + 3) / 4;
   while (i < requiredDigits) hexa[i++] = '0';
   for (int k = i - 1; k >= 0; k--) printf ("%c", hexa[k]);
}

int main () {
   int number;
   printf ("Enter decimal Number: ");
   scanf_s ("%d", &number);
   printf ("\nBinary: ");
   DecToBinary (number);
   printf ("\nBinary value using shift operator: ");
   DecimalToBinary (number);  
   printf ("\nHexadecimal: ");
   DecToHexa (number);
   
   // printing hexadecimal number using format specifier %X 
   printf ("\nHexadecimal value using format specfier: ");
   printf ("%X",number);
   printf ("\n");
   return 0;
}