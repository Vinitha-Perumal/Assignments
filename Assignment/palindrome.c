// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// palindrome.c
// Program for Number Conversion.
// ------------------------------------------------------------------------------------------------

#include "palindrome.h"
#include <ctype.h>

int PalindromeCheck (char str[]) {
   char temp[100] = { 0 };
   int len = 0;
   for (int i = 0; str[i] != '\0'; i++)
      if (isalpha (str[i])) temp[len++] = str[i];
   temp[len] = '\0';
   if (len == 0) return 0;
   int start = 0, end = len - 1;
   while (start < end)
      if (tolower (temp[start++]) != tolower (temp[end--])) return 0;
   return 1;
}

int ReverseNumber (int num, int* reversed) {
   *reversed = 0;
   if (num >= 0 && num <= 9) {
      *reversed = num;
      return 1;
   }
   int original = num;
   while (num != 0) {
      *reversed = *reversed * 10 + num % 10;
      num /= 10;
   }
   return original == *reversed ? 1 : 0;
}