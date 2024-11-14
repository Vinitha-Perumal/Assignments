// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
int main () {
   int a = _setmode (_fileno (stdout), _O_U16TEXT);
   wchar_t whitePieces[8] = { 0x2656, 0x2658, 0x2657, 0x2655, 0x2654, 0x2657, 0x2658, 0x2656 };
   wchar_t blackPieces[8] = { 0x265C, 0x265E, 0x265D, 0x265B, 0x265A, 0x265D, 0x265E, 0x265C };
   wchar_t whitePawn = 0x2659;
   wchar_t blackPawn = 0x265F;
   wprintf (L"%lc", 0x250F); //top
   for (int i = 0; i < 7; i++) wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x2533);
   wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x2513);
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
         wprintf (L"%lc ", 0x2503);
         if (i == 0) wprintf (L"%lc ", blackPieces[j]);
         else if (i == 1) wprintf (L"%lc", blackPawn);
         else if (i == 6) wprintf (L"%lc ", whitePawn);
         else if (i == 7) wprintf (L"%lc ", whitePieces[j]);
         else wprintf (L"  ");
      }
      wprintf (L"%lc\n", 0x2503);
      if (i < 7) {
         wprintf (L"%lc", 0x2523);
         for (int k = 0; k < 7; k++) wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x254B);
         wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x252B);
      }
   }
   wprintf (L"%lc", 0x2517); //bottom
   for (int i = 0; i < 7; i++) wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x253B);
   wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x251B);
   return 0;
}