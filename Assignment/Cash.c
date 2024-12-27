// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Cash.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Cash.h"

int Cash (int balance, int denominations[], int numOfDenominations, int coins[]) {
   if (balance < 0) return 0;
   for (int i = 0; i < numOfDenominations; i++) {
      coins[i] = balance / denominations[i];
      balance %= denominations[i];
   }
   return 1;
}