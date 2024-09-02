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
int mBitLength;
/// <summary>Decimal number to binary Conversion</summary>
void DecToBinary (int n) {
   int binary[32], i = 0, isNegative = 0; // Flag is to check if the number is negative
   if (n == 0) {
      printf ("0");
      return;
   }
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

/// <summary>Decimal number to Hexadecimal Conversion</summary>
void DecToHexa (int n) {
   char hexa[32];
   int i = 0;
   if (n == 0) {
      printf ("0");
      return;
   }
   unsigned int num = (unsigned int)n;   // Handle negative numbers by using unsigned int
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
   printf ("Binary: ");
   DecToBinary (number);
   printf ("\nHexadecimal: ");
   DecToHexa (number);
   printf ("\n");
   return 0;
}