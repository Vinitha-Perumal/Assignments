// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Test.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>

int main () {
   int n, n2;
   char rupees[10];
   printf ("Enter the total amount : ");
   scanf_s ("%d", &n);
   printf ("\nenter the amount of cash paid: ");
   scanf_s ("%d", &n2);
   printf ("enter the number of coins you have: ");
   for (int i = 0; i < 10; i++) {
      fgets (rupees, sizeof (rupees), stdin);
   }
   int res = n - n2;
   for (int i = 0; i < 10; i++) {
      if (res == rupees[i]) printf ("to give %d coin to customer\n", rupees[i]);
      else break;
   }
   return 0;
}