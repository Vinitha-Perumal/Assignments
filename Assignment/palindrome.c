// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Palindrome.c
// ------------------------------------------------------------------------------------------------
#include "Palindrome.h"
#include <ctype.h>
#include <string.h>

int PalindromeCheck (const char str[]) {
   int start = 0, end = (int)strlen (str) - 1, validChar = 0;
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
   return !validChar ? -1 : validChar;
}

int ReverseNumber (int num, int* reversed) {
   if (num < 0) num = -num;
   *reversed = 0;
   int temp = num;
   while (temp != 0) {
      *reversed = *reversed * 10 + temp % 10;
      temp /= 10;
   }
   return 1;
}