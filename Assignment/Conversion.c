// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Conversion.c
// Program for Number Conversion.
// ------------------------------------------------------------------------------------------------

#pragma warning(disable:4996)
#include "conversion.h"

int mBitLength;

void DecToBinary (int n, char* binaryStr) {
   int binary[32], i = 0, k, isNegative = 0; // Flag is to check if the number is negative
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
      mBitLength = (i <= 7) ? 8 : 16;
      for (int j = i; j < mBitLength; j++) binary[j] = 0;
      for (int j = 0; j < mBitLength; j++) binary[j] = 1 - binary[j]; // Invert the bits for 2's complement
      int carry = 1;
      for (int j = 0; j < mBitLength; j++) {
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
   }
   for (k = 0; k < mBitLength; k++) binaryStr[k] = binary[mBitLength - 1 - k] + '0';
   binaryStr[k] = '\0';
}

void DecToBinaryShiftOperator (int n, char* binaryString) {
   int numBits = sizeof (int) * 8;
   int isNegative = (n < 0); // Check if the number is negative
   mBitLength = (n >= -128 && n <= 127) ? 8 : 16;
   if (isNegative) n = ~(-n) + 1; // Compute two's complement
   unsigned int mask = 1 << (mBitLength - 1); // Create a mask to extract each bit
   int i;
   for (i = 0; i < mBitLength; i++) {
      binaryString[i] = (n & mask) ? '1' : '0';
      mask >>= 1;
   }
   binaryString[i] = '\0';
}

void DecToHexa (int n, char* hexaStr) {
   char hexa[32];
   int i = 0, k, isNegative = 0;  // Flag to check if the number is negative
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
   int requiredDigits = 2;
   while (i < requiredDigits) hexa[i++] = '0';
   for (k = 0; k < i; k++) hexaStr[k] = hexa[i - 1 - k];
   hexaStr[k] = '\0';
}