// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// TicTacToe.c
// Program on Test3.2 branch.
// ------------------------------------------------------------------------------------------------
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#define EMPTY ' '  

void InitializeBoard (char board[3][3]);
void PrintBoard (const char board[3][3]);
int CheckWinner (const char board[3][3], char currentPlayer);
int IsBoardFull (const char board[3][3]);
int MakeMove (char board[3][3], char currentPlayer, int move);
void SwitchPlayer (char* currentPlayer, char player1Symbol, char player2Symbol);
void GetPlayerSymbols (char* player1Symbol, char* player2Symbol);

void InitializeBoard (char board[3][3]) {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) board[i][j] = EMPTY;
   }
}

void PrintBoard (const char board[3][3]) {
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

int CheckWinner (const char board[3][3], char currentPlayer) {
   for (int i = 0; i < 3; i++) {
      if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == currentPlayer) ||
          (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == currentPlayer))
         return 1;
   }
   if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == currentPlayer) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == currentPlayer))
      return 1;
   return 0;
}

int IsBoardFull (const char board[3][3]) {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
         if (board[i][j] == EMPTY) return 0;
   }
   return 1;
}

int MakeMove (char board[3][3], char currentPlayer, int move) {
   int row = (move - 1) / 3, col = (move - 1) % 3;
   if (board[row][col] != EMPTY) return 0;
   board[row][col] = currentPlayer;
   return 1;
}

void SwitchPlayer (char* currentPlayer, char player1Symbol, char player2Symbol) {
   *currentPlayer = (*currentPlayer == player1Symbol) ? player2Symbol : player1Symbol;
}

void GetPlayerSymbols (char* player1Symbol, char* player2Symbol) {
   char input[3];
   printf ("Player 1, choose your symbol (X/O): ");
   while (true) {
      fgets (input, sizeof (input), stdin);
      if (input[strlen (input) - 1] != '\n') while (getchar () != '\n');
      char symbol = tolower (input[0]);
      switch (symbol) {
         case 'x':
            *player1Symbol = 'X';
            *player2Symbol = 'O';
            printf ("Player 2, your symbol is '%c'\n", *player2Symbol);
            return;
         case 'o':
            *player1Symbol = 'O';
            *player2Symbol = 'X';
            printf ("Player 2, your symbol is '%c'\n", *player2Symbol);
            return;
         default:
            printf ("Invalid choice! Please choose 'X' or 'O': ");
      }
   }
}

int main () {
   char board[3][3], currentPlayer, player1Symbol, player2Symbol;
   int gameOver = 0, move = 0;
   GetPlayerSymbols (&player1Symbol, &player2Symbol);
   currentPlayer = player1Symbol;
   InitializeBoard (board);
   while (!gameOver) {
      PrintBoard (board);
      while (true) {
         char input[10];
         printf ("Player %c, enter a cell (1-9): ", currentPlayer);
         if (!fgets (input, sizeof (input), stdin)) {
            printf ("error reading input, try again\n");
            continue;
         }
         char* endptr;
         move = strtol (input, &endptr, 10);
         if (endptr == input || *endptr != '\n' || move < 1 || move > 9) {
            printf ("\nInvalid move! Please enter a number between 1 and 9: ");
            continue;
         }
         if (MakeMove (board, currentPlayer, move)) break;
         else printf ("Invalid move! The cell is already taken. Try again: ");
      }
      if (CheckWinner (board, currentPlayer)) {
         PrintBoard (board);
         printf ("Player %c wins!\n", currentPlayer);
         gameOver = 1;
      }
      else if (IsBoardFull (board)) {
         PrintBoard (board);
         printf ("It's a draw!\n");
         gameOver = 1;
      }
      else SwitchPlayer (&currentPlayer, player1Symbol, player2Symbol);
   }
   return 0;
}