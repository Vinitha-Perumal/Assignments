// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// palindrome.c
// Program for Number Conversion.
// ------------------------------------------------------------------------------------------------

#include "palindrome.h"
#include <ctype.h>
#include <string.h>

int PalindromeCheck (char str[]) {
   int start = 0;
   int end = (int)strlen (str) - 1;
   while (start < end) {  // Ignore non-alphabet characters and convert to lowercase for comparison
      if (!isalpha (str[start])) {
         start++;
         continue;
      }
      if (!isalpha (str[end])) {
         end--;
         continue;
      }
      if (tolower (str[start++]) != tolower (str[end--])) return 0;
   }
   return 1;
}

int reverseNumber (int num) {
   int reversed = 0;
   while (num > 0) {
      reversed = reversed * 10 + num % 10;
      num /= 10;
   }
   return reversed;
}