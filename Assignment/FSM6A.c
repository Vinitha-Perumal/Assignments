// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.c
// Program on A6B branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS  1

// Define states of the Mealy machine
typedef enum {
   S0,
   S1,
   S2,
   S3,
   S4,
   S5,
   S6,
   S7
} State;

State NextMealyState (State currentState, int input, int* output);

// Function to get the next state and output based on the current state and input
State NextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
      case S0:
         *output = 0;
         return (input == 0) ? S1 : S5;  // Transition to S1 if input is '0', otherwise to S5
      case S1:
         *output = 0;
         return (input == 1) ? S2 : S1;  // Transition to S2 if input is '1', otherwise stay in S1
      case S2:
         *output = 0;
         return (input == 1) ? S3 : S1;  // Transition to S3 if input is '1', otherwise go back to S1
      case S3:
         *output = (input == 0) ? 1 : 0; // Output 1 if input is '0', otherwise output 0
         return (input == 0) ? S4 : S5;  // Transition to S4 if input is '0', otherwise to S5
      case S4:
         *output = (input == 1) ? 1 : 0; // Output 1 if input is '1', otherwise output 0
         return (input == 1) ? S2 : S1;  // Transition to S2 if input is '1', otherwise go back to S1
      case S5:
         *output = 0;
         return (input == 0) ? S6 : S5;  // Transition to S6 if input is '0', otherwise stay in S5
      case S6:
         *output = (input == 1) ? 1 : 0; // Output 1 if input is '1', otherwise output 0
         return (input == 1) ? S7 : S1;  // Transition to S7 if input is '1', otherwise go back to S1
      case S7:
         *output = 0;
         return (input == 0) ? S1 : S3;  // Transition to S1 if input is '0', otherwise to S3
      default:
         return S0;  // Default return to initial state
   }
}

int main (int argc, char** argv) {
   if (argc != 3) {
      printf ("Usage: %s <input file> <output file>\n", argv[0]);
      return 1;
   }
   FILE* inputFile = fopen (argv[1], "r"),
      * outputFile = fopen (argv[2], "w");
   if (inputFile == NULL || outputFile == NULL) {
      printf ("Error opening file.\n");
      return 1;
   }
   State currentState = S0;
   int input, output = 0;
   while (fscanf (inputFile, "%1d", &input) == 1) {
      currentState = NextMealyState (currentState, input, &output);
      fprintf (outputFile, "%d", output);
   }
   fclose (inputFile);
   fclose (outputFile);
   return 0;
}