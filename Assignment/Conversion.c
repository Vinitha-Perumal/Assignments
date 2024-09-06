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

char* DecToBinary (int n) {
   int binary[32] = { 0 }, i = 0, isNegative = 0; // Flag is to check if the number is negative
   char binaryStr[33];
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
      mBitLength = (i <= 7) ? 8 : (i <= 8) ? 16 : 32;
      for (int j = 0; j < mBitLength; j++) binary[j] = 1 - binary[j]; // Invert the bits for 2's complement
      int carry = 1;
      for (int j = 0; j < mBitLength; j++) {
         binary[j] += carry;
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
   int k;
   for (k = 0; k < mBitLength; k++) binaryStr[k] = binary[mBitLength - 1 - k] + '0';
   binaryStr[k] = '\0';
   return binaryStr;
}

char* DecToBinaryShiftOperator (int n) {
   char binaryString[33] = {'0'};
   int numBits = sizeof (int) * 8,isNegative = (n < 0); 
   mBitLength = (n >= -128 && n <= 127) ? 8 : 16;
   if (isNegative) n = ~(-n) + 1; // Compute two's complement
   unsigned int mask = 1 << (mBitLength - 1); // Create a mask to extract each bit
   int i;
   for (i = 0; i < mBitLength; i++) {
      binaryString[i] = (n & mask) ? '1' : '0';
      mask >>= 1;
   }
   binaryString[i] = '\0';
   return binaryString;
}

char* DecToHexa (int n) {
   char hexaStr[32] = { 0 };
   int i = 0;
   unsigned int num = (unsigned int)n;
   while (num > 0) {
      int rem = num % 16;
      hexaStr[i++] = (rem < 10) ? rem + '0' : rem - 10 + 'A';
      num /= 16;
   }
   int requiredDigits = 2;
   while (i < requiredDigits) hexaStr[i++] = '0';
   int j;
   for (j = 0; j < i / 2; j++) {
      char temp = hexaStr[j];
      hexaStr[j] = hexaStr[i - 1 - j];
      hexaStr[i - 1 - j] = temp;
   }
   hexaStr[i] = '\0';
   return hexaStr;
}