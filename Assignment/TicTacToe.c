// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// TicTacToe.c
// Program on Test3.2 branch.
// ------------------------------------------------------------------------------------------------
#include "TicTacToe.h"
#define EMPTY ' '  
char board[3][3], currentPlayer, player1Symbol, player2Symbol;

void InitializeBoard () {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) board[i][j] = EMPTY;
   }
}

int CheckWinner () {
   for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
         return 1;
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
         return 1;
   }
   if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
      return 1;
   if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
      return 1;
   return 0;
}

int IsBoardFull () {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (board[i][j] == EMPTY) return 0;
      }
   }
   return 1;
}

int MakeMove (int move) {
   if (move < 1 || move > 9) return 0;
   int row = (move - 1) / 3, col = (move - 1) % 3;
   if (board[row][col] == EMPTY) {
      board[row][col] = currentPlayer;
      return 1;
   }
   return 0;
}

void SwitchPlayer () {
   currentPlayer = (currentPlayer == player1Symbol) ? player2Symbol : player1Symbol;
}