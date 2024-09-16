// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Conversion.c
// Program for Number Conversion.
// ------------------------------------------------------------------------------------------------

#include "conversion.h"

char* DecToBinary (int n, char* binaryStr) {
   int bitLength = (n >= -128 && n <= 127) ? 8 : (n >= -32768 && n <= 32767) ? 16 : 32;
   if (n < 0) n = ~(-n) + 1; // Compute two's complement
   unsigned int mask = 1 << (bitLength - 1); // Create a mask to extract each bit
   int i = 0;
   for (i = 0; i < bitLength; i++) {
      binaryStr[i] = (n & mask) ? '1' : '0';
      mask >>= 1;
   }
   binaryStr[bitLength] = '\0';
   return binaryStr;
}

char* DecToHexa (int n, char* hexaStr) {
   int bitLength = (n >= -128 && n <= 127) ? 8 : (n >= -32768 && n <= 32767) ? 16 : 32;
   int hexDigits = (bitLength / 4);
   unsigned int num = (unsigned int)n;
   int i = 0, hexDigitVal;
   for (i = hexDigits - 1; i >= 0; i--) {
      hexDigitVal = (num >> (i * 4)) & 0xF;
      hexaStr[hexDigits - 1 - i] = hexDigitVal + (hexDigitVal < 10 ? '0' : (-10 + 'A'));
   }
   hexaStr[hexDigits] = '\0';
   return hexaStr;
}