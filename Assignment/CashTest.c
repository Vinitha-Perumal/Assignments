// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// CashTest.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Cash.h"
#include <stdio.h>

void TestCases ();

void TestCases () {
   int cashPaid[] = { 23, 56, 90 }, actualAmount[] = { 22, 37, 40 }, denominations[] = { 10,5,2,1 },
      expectedOutput[][4] = { { 0, 0, 0, 1 }, { 1, 1, 2, 0 }, { 5, 0, 0, 0 } },
      numOfTestCases = sizeof (cashPaid) / sizeof (cashPaid[0]);
   for (int i = 0; i < numOfTestCases; i++) {
      int change = cashPaid[i] - actualAmount[i];
      printf ("\nTestCase %d\n\nCash Paid: %d\nActual Amount: %d\nExpected Output: 10Rs. %d, "
              "5Rs. %d, 2Rs. %d, 1Rs. %d\n", i + 1, cashPaid[i], actualAmount[i],
              expectedOutput[i][0], expectedOutput[i][1], expectedOutput[i][2], expectedOutput[i][3]);
      int coins[4] = { 0 }, res = Cash (change, denominations, sizeof (denominations) / sizeof (denominations[i]), coins), isTestPassed = 1;
      if (res != 1) isTestPassed = 0;
      else {
         for (int j = 0; j < 4; j++) {
            if (coins[j] != expectedOutput[i][j]) {
               isTestPassed = 0;
               break;
            }
         }
      }
      printf ("Actual Output: 10Rs. %d, 5Rs. %d, 2Rs. %d, 1Rs. %d\n %s\n", coins[0], coins[1],
              coins[2], coins[3], isTestPassed ? "Test Passed!" : "Test Failed!");
   }
}

int main () {
   TestCases ();
   return 0;
}