// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Complex.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Complex.h"
#include <math.h>

ComplexNumber Op_Add (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp = { num1.Real + num2.Real, num1.Img + num2.Img };
   return temp;
}

ComplexNumber Op_Sub (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp = { num1.Real - num2.Real, num1.Img - num2.Img };
   return temp;
}

ComplexNumber Op_Mul (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp = { (num1.Real * num2.Real) - (num1.Img * num2.Img),
      (num1.Real * num2.Img) + (num1.Img * num2.Real) };
   return temp;
}

ComplexNumber Op_Conj (ComplexNumber num) {
   ComplexNumber temp = { num.Real, -num.Img };
   return temp;
}

double Op_Mod (ComplexNumber num) {
   return sqrt (num.Real * num.Real + num.Img * num.Img);
}