// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Cash.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Cash.h"

int Cash (int cashPaid, int actualAmount, int coins[4]) {
   int change = cashPaid - actualAmount, denominations[] = { 10,5,2,1 };
   if (change < 0) return 0;
   for (int i = 0; i < 4; i++) {
      coins[i] = change / denominations[i];
      change %= denominations[i];
   }
   return 1;
}