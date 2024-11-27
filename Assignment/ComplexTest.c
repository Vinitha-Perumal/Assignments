// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// ComplexTest.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Complex.h"
#include <stdio.h>
#include <math.h>

void DisplayRes (ComplexNumber num);
void TestCases ();

void DisplayRes (ComplexNumber num) {
   num.img < 0 ? printf ("%.2f - %.2fi\n", num.real, -num.img)
      : printf ("%.2f + %.2fi\n", num.real, num.img);
}

void TestCases () {
   ComplexNumber num1[] = { {3, 2}, {5, 7}, {1, -1} }, num2[] = { {1, -4}, {3, -8}, {-2, 3} },
      expectedAddOut[] = { {4, -2}, {8, -1}, {-1, 2} },
      expectedSubOut[] = { {2, 6}, {2, 15}, {3, -4} },
      expectedMulOut[] = { {11, -10}, {71, -19}, {1, 5} },
      expectedConjOut[] = { {3, -2}, {5, -7}, {1, 1} };
   double expectedModOut[] = { 3.60555, 8.60233, 1.41421 };
   int numOfTestCases = sizeof (num1) / sizeof (num1[0]);
   for (int i = 0; i < numOfTestCases; i++) {
      printf ("Testcase %d:\n\n", i + 1);
       // Addition TestCase
      ComplexNumber addRes = Op_Add (num1[i], num2[i]);
      if (addRes.real == expectedAddOut[i].real && addRes.img == expectedAddOut[i].img)
         printf ("Addition: Pass\n");
      else printf ("Addition: Fail\n");

      // Subtraction TestCase
      ComplexNumber subRes = Op_Sub (num1[i], num2[i]);
      if (subRes.real == expectedSubOut[i].real && subRes.img == expectedSubOut[i].img)
         printf ("Subtraction: Pass\n");
      else printf ("Subtraction: Fail\n");

      // Multiplication TestCase
      ComplexNumber mulRes = Op_Mul (num1[i], num2[i]);
      if (mulRes.real == expectedMulOut[i].real && mulRes.img == expectedMulOut[i].img)
         printf ("Multiplication: Pass\n");
      else printf ("Multiplication: Fail\n");

      // Conjugate TestCase
      ComplexNumber conjRes = Op_Conj (num1[i]);
      if (conjRes.real == expectedConjOut[i].real && conjRes.img == expectedConjOut[i].img)
         printf ("Conjugate: Pass\n");
      else printf ("Conjugate: Fail\n");

      // Modulus TestCase
      double modRes = Op_Mod (num1[i]);
      if (fabs (modRes - expectedModOut[i]) < 0.00001) printf ("Modulus: Pass\n");
      else printf ("Modulus: Fail\n");
      printf ("\n\n");
   }
}

int main () {
   TestCases ();
   printf ("\n\n");
   ComplexNumber num1 = { 0,0 }, num2 = { 0,0 };
   printf ("Enter real part 1: ");
   scanf_s ("%f", &num1.real);
   printf ("Enter img part 1: ");
   scanf_s ("%f", &num1.img);
   printf ("Enter real part 2: ");
   scanf_s ("%f", &num2.real);
   printf ("Enter img part 2: ");
   scanf_s ("%f", &num2.img);
   printf ("\nAddition: ");
   DisplayRes (Op_Add (num1, num2));
   printf ("Subtraction: ");
   DisplayRes (Op_Sub (num1, num2));
   printf ("Multiplication: ");
   DisplayRes (Op_Mul (num1, num2));
   printf ("Conjugate: ");
   DisplayRes (Op_Conj (num1));
   printf ("Modulus: %.2lf\n", Op_Mod (num1));
   return 0;
}