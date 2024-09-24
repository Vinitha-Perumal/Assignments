// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Palindrome.c
// Program for Number Conversion.
// ------------------------------------------------------------------------------------------------
#include "Palindrome.h"
#include <ctype.h>
#include <string.h>

int PalindromeCheck (char str[]) {
   int start = 0;
   int end = (int)strlen (str) - 1;
   int validChar = 0;
   while (start < end) {  // Ignore non-alphabet characters and convert to lowercase for comparison
      if (!isalpha (str[start])) {
         start++;
         continue;
      }
      if (!isalpha (str[end])) {
         end--;
         continue;
      }
      validChar = 1;
      if (tolower (str[start++]) != tolower (str[end--])) return 0;
   }
   if (!validChar) return 0;
   return 1;
}

int ReverseNumber (int num, int* reversed) {
   *reversed = 0;
   if (num < 0 || (num <= 9 && (*reversed = num))) return num >= 0;
   int original = num;
   while (num != 0) {
      *reversed = *reversed * 10 + num % 10;
      num /= 10;
   }
   return original == *reversed ? 1 : 0;
}