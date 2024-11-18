// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.c
// Program on A6B branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
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

// Function to get the next state and output based on the current state and input
State nextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
      case S0:
         if (input == 0) {
            *output = 0;
            return S1;  // Transition to S1 after '0'
         }
         else {
            *output = 0;
            return S5;  // Transition to S5 if input is '1'
         }
      case S1:
         if (input == 1) {
            *output = 0;
            return S2;  // Transition to S2 after '01'
         }
         else {
            *output = 0;
            return S1;  // Stay in S1 if input is '0'
         }
      case S2:
         if (input == 1) {
            *output = 0;
            return S3;    // Transitions to S3 after '011'
         }
         else {
            *output = 0;
            return S1;  // Return to S1 if input is '0'
         }
      case S3:
         if (input == 0) {
            *output = 1;  // output '1' upon seeing '0110'
            return S4;  // Transitions to S4 
         }
         else {
            *output = 0;
            return S5;    // Transitions to S5 if input is '1'
         }
      case S4:
         if (input == 1) {
            *output = 1;   // output '1' upon seeing '1101'
            return S2;     // Return to S2  
         }
         else {
            *output = 0;
            return S1;    // Return to S1 if input is '0'
         }
      case S5:
         if (input == 0) {
            *output = 0;
            return S6;   // Transition to S6 if input is '0'
         }
         else {
            *output = 0;
            return S5;   // Stay in S5 if input is '1'
         }
      case S6:
         if (input == 1) {
            *output = 1; // output '1' upon seeing '1101'
            return S7;   // move to S7
         }
         else {
            *output = 0;
            return S1;   // Transition to S1 if input is '0'
         }
      case S7:
         if (input == 0) {
            *output = 0; 
            return S1;   // Transition to S1 if input is '0'
         }
         else {
            *output = 0;
            return S3;   // Transition to S3 if input is '1'
         }
      default:
         return S0;  // Default return to initial state
   }
}

int processFSM (FILE* inputFile, FILE* outputFile) {
   State currentState = S0;  // Start in the initial state
   int input, output = 0;
   // Read input from the file and process it until the end of file (EOF)
   while ((input = getc (inputFile)) != EOF) {
      currentState = nextMealyState (currentState, input - '0', &output);  // Transition to the next state and calculate the output
      fprintf (outputFile, "%d", output);
   }
   return 0;
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
      currentState = nextMealyState (currentState, input, &output);
      fprintf (outputFile, "%d", output);
   }
   fclose (inputFile);
   fclose (outputFile);
   return 0;
}