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

void TestCases ();

void TestCases () {
   ComplexNumber num1[] = { {3, 2}, {5, 7}, {1, -1} }, num2[] = { {1, -4}, {3, -8}, {-2, 3} };
   int numOfTestCases = sizeof (num1) / sizeof (num1[0]);
   for (int i = 0; i < numOfTestCases; i++) {
      printf ("\nTestcase %d:\n\n", i + 1);
      // Addition TestCase
      ComplexNumber expectedAddOut = { num1[i].Real + num2[i].Real,num1[i].Img + num2[i].Img },
         addRes = Op_Add (num1[i], num2[i]);
      printf ("Addition: %s\n", IsEqual (addRes, expectedAddOut) ? "Pass" : "Fail");

      // Subtraction TestCase
      ComplexNumber expectedSubOut = { num1[i].Real - num2[i].Real, num1[i].Img - num2[i].Img },
         subRes = Op_Sub (num1[i], num2[i]);
      printf ("Subtraction: %s\n", IsEqual (subRes, expectedSubOut) ? "Pass" : "Fail");

      // Multiplication TestCase
      ComplexNumber expectedMulOut = { (num1[i].Real * num2[i].Real) - (num1[i].Img * num2[i].Img),
                                       (num1[i].Real * num2[i].Img) + (num1[i].Img * num2[i].Real) },
         mulRes = Op_Mul (num1[i], num2[i]);
      printf ("Multiplication: %s\n", IsEqual (mulRes, expectedMulOut) ? "Pass" : "Fail");

      // Conjugate TestCase
      ComplexNumber expectedConjOut = { num1[i].Real, -num1[i].Img }, conjRes = Op_Conj (num1[i]);
      printf ("Conjugate: %s\n", IsEqual (conjRes, expectedConjOut) ? "Pass" : "Fail");

      // Modulus TestCase
      double expectedModOut = sqrt (num1[i].Real * num1[i].Real + num1[i].Img * num1[i].Img),
         modRes = Op_Mod (num1[i]);
      printf ("Modulus: %s\n", modRes == expectedModOut ? "Pass" : "Fail");
   }
}

int main () {
   TestCases ();
   return 0;
}