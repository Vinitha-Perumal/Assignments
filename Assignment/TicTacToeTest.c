// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// TicTacToeTest.c
// Program on Test3.2 branch.
// ------------------------------------------------------------------------------------------------
#include "TicTacToe.h"
#include <stdio.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void PrintBoard ();
void GetPlayerSymbols ();

void PrintBoard () {
   printf ("\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         printf (" %c ", board[i][j]);
         if (j < 2) printf ("|");
      }
      printf ("\n");
      if (i < 2) printf ("---|---|---\n");
   }
   printf ("\n");
}

void GetPlayerSymbols () {
   char symbol;
   printf ("Player 1, choose your symbol (X/O): ");
   while (1) {
      scanf (" %c", &symbol);
      if (symbol == 'X' || symbol == 'x') {
         player1Symbol = 'X';
         player2Symbol = 'O';
         break;
      }
      else if (symbol == 'O' || symbol == 'o') {
         player1Symbol = 'O';
         player2Symbol = 'X';
         break;
      }
      else printf ("Invalid choice! Please choose 'X' or 'O': ");
   }
   printf ("Player 2, your symbol is '%c'.\n", player2Symbol);
}

int main () {
   int gameOver = 0, move = 0;
   GetPlayerSymbols (player1Symbol);
   currentPlayer = player1Symbol;
   InitializeBoard ();
   while (!gameOver) {
      PrintBoard ();
      printf ("Player %c, enter a cell (1-9): ", currentPlayer);
      while (1) {  // Keep prompting the player until they make a valid move
         if (scanf ("%d", &move) != 1) {
            while (getchar () != '\n');  // Clear the buffer
            printf ("Invalid input! Please enter a number between 1 and 9: ");
            continue;
         }
         if (move < 1 || move > 9) printf ("\nInvalid move! Please enter a number between 1 and 9: ");
         else {
            if (MakeMove (move)) break;
            else printf ("Invalid move! The cell is already taken. Try again: ");
         }
      }
      if (CheckWinner ()) {
         PrintBoard ();
         printf ("Player %c wins!\n", currentPlayer);
         gameOver = 1;
      }
      else if (IsBoardFull ()) {
         PrintBoard ();
         printf ("It's a draw!\n");
         gameOver = 1;
      }
      else SwitchPlayer ();
   }
   return 0;
}