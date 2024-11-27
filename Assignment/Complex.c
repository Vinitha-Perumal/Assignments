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
   ComplexNumber temp = { num1.real + num2.real, num1.img + num2.img };
   return temp;
}

ComplexNumber Op_Sub (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp = { num1.real - num2.real, num1.img - num2.img };
   return temp;
}

ComplexNumber Op_Mul (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp = { (num1.real * num2.real) - (num1.img * num2.img),
      (num1.real * num2.img) + (num1.img * num2.real) };
   return temp;
}

ComplexNumber Op_Conj (ComplexNumber num) {
   ComplexNumber temp = { num.real, -num.img };
   return temp;
}

double Op_Mod (ComplexNumber num) {
   return sqrt (num.real * num.real + num.img * num.img);
}