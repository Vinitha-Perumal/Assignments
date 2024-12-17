// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Cash.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Cash.h"

int Cash (int change, int denominations[], int numOfDenominations, int coins[]) {
   if (change < 0) return 0;
   for (int i = 0; i < numOfDenominations; i++) {
      coins[i] = change / denominations[i];
      change %= denominations[i];
   }
   return 1;
}