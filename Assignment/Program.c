// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include "Program.h"

ComplexNumber Op_Add (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp;
   temp.real = num1.real + num2.real;
   temp.img = num1.img + num2.img;
   return temp;
}

ComplexNumber Op_Sub (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp;
   temp.real = num1.real - num2.real;
   temp.img = num1.img - num2.img;
   return temp;
}

ComplexNumber Op_mul (ComplexNumber num1, ComplexNumber num2) {
   ComplexNumber temp;
   temp.real = (num1.real * num2.real) - (num1.img * num2.img);
   temp.img = (num1.real * num2.img) + (num1.img * num1.real);
   return temp;
}