// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Test.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include "Program.h"
#include <stdio.h>

void DisplayRes (ComplexNumber num) {
   printf ("%.2f + %.2fi\n", num.real, num.img);
}

int main () {
   ComplexNumber num1, num2, res1, res2, res3;
   printf ("enter real part 1 and img part 1:");
   scanf_s ("%f ", &num1.real);
   scanf_s ("%f", &num1.img);
   printf ("\nenter real part 2: ");
   scanf_s ("%f", &num2.real);
   printf ("\nenter img part 2:");
   scanf_s ("%f", &num2.img);
   res1 = Op_Add (num1, num2);
   DisplayRes (res1);
   res2 = Op_Sub (num1, num2);
   DisplayRes (res2);
   res3 = Op_mul (num1, num2);
   DisplayRes (res3);
   return 0;
}