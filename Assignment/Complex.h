// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Complex.h
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------------------
#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct ComplexNumber {
   float Real, Img;
}ComplexNumber;

/// <summary>To Add two complex numbers.</summary>
ComplexNumber Op_Add (ComplexNumber num1, ComplexNumber num2);

/// <summary>Returns the difference of 2 complex numbers.</summary>
ComplexNumber Op_Sub (ComplexNumber num1, ComplexNumber num2);

/// <summary>To Multiply two complex numbers</summary>
ComplexNumber Op_Mul (ComplexNumber num1, ComplexNumber num2);

/// <summary>To calculate the Conjugate of a complex number.</summary>
ComplexNumber Op_Conj (ComplexNumber num);

/// <summary>To calculate the Modulus of a complex number.</summary>
double Op_Mod (ComplexNumber num);

#endif