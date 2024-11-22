// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.h
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#ifndef PROGRAM_H
#define PROGRAM_H

typedef struct ComplexNumber {
   float real;
   float img;
}ComplexNumber;

ComplexNumber Op_Add (ComplexNumber num1, ComplexNumber num2);
ComplexNumber Op_Sub (ComplexNumber num1, ComplexNumber num2);
ComplexNumber Op_mul (ComplexNumber num1, ComplexNumber num2);
#endif