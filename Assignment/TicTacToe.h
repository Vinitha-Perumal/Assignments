// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// TicTacToe.h
// Program on Test3.2 branch.
// ------------------------------------------------------------------------------------------------
#ifndef TICTACTOE_H
#define TICTACTOE_H

extern char board[3][3], player1Symbol, player2Symbol, currentPlayer;

/// <summary>To initialize the board with empty cells</summary>
void InitializeBoard ();

/// <summary>To check if the current player has won</summary>
int CheckWinner ();

/// <summary>To check if the board is full</summary>
int IsBoardFull ();

/// <summary>To handle the player's move</summary>
int MakeMove (int move);

/// <summary>To switch players</summary>
void SwitchPlayer ();

#endif