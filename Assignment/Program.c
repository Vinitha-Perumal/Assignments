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

void PrintChessBoard (FILE* output);
int CompareFiles (const char* outputFile, const char* referenceFile);

void PrintChessBoard (FILE* output) {
   wchar_t whitePieces[8] = { 0x2656, 0x2658, 0x2657, 0x2655, 0x2654, 0x2657, 0x2658, 0x2656 },
      blackPieces[8] = { 0x265C, 0x265E, 0x265D, 0x265B, 0x265A, 0x265D, 0x265E, 0x265C },
      whitePawn = 0x2659, blackPawn = 0x265F;
   // top border
   wprintf (L"%lc", 0x250F);
   fwprintf (output, L"%lc", 0x250F);
   for (int i = 0; i < 7; i++) {
      wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x2533);
      fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x2533);
   }
   wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x2513);
   fwprintf (output, L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x2513);
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
         wprintf (L"%lc ", 0x2503);
         fwprintf (output, L"%lc ", 0x2503);
         if (i == 0) {
            wprintf (L"%lc ", blackPieces[j]);
            fwprintf (output, L"%lc ", blackPieces[j]);
         }
         else if (i == 1) {
            wprintf (L"%lc", blackPawn);
            fwprintf (output, L"%lc", blackPawn);
         }
         else if (i == 6) {
            wprintf (L"%lc ", whitePawn);
            fwprintf (output, L"%lc ", whitePawn);
         }
         else if (i == 7) {
            wprintf (L"%lc ", whitePieces[j]);
            fwprintf (output, L"%lc ", whitePieces[j]);
         }
         else {
            wprintf (L"  ");
            fwprintf (output, L"  ");
         }
      }
      wprintf (L"%lc\n", 0x2503);
      fwprintf (output, L"%lc\n", 0x2503);
      if (i < 7) {
         wprintf (L"%lc", 0x2523);
         fwprintf (output, L"%lc", 0x2523);
         for (int k = 0; k < 7; k++) {
            wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x254B);
            fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x254B);
         }
         wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x252B);
         fwprintf (output, L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x252B);
      }
   }
   // bottom border
   wprintf (L"%lc", 0x2517);
   fwprintf (output, L"%lc", 0x2517);
   for (int i = 0; i < 7; i++) {
      wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x253B);
      fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x253B);
   }
   wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x251B);
   fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x251B);
}

int CompareFiles (const char* outputFile, const char* referenceFile) {
   FILE* output = fopen (outputFile, "r, ccs=UTF-8"),
      * reference = fopen (referenceFile, "r, ccs=UTF-8");
   if (output == NULL || reference == NULL) {
      wprintf (L"Error opening files for comparison.\n");
      return -1;
   }
   int row = 1, col = 1;
   wchar_t outputChar, referenceChar;
   while (1) {
      outputChar = fgetwc (output);
      referenceChar = fgetwc (reference);
      if (outputChar == WEOF && referenceChar == WEOF) {
         wprintf (L"\n\nTest Passed\n");
         fclose (output);
         fclose (reference);
         return 0;
      }
      if (outputChar != referenceChar) {
         wprintf (L"\nMismatch at row %d, column %d\n", row, col);
         fclose (output);
         fclose (reference);
         return -2;
      }
      if (outputChar == L'\n' || referenceChar == L'\n') {
         row++;
         col = 1;
      }
      else col++;
   }
}

int main () {
   int a = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* output = fopen ("output.txt", "w, ccs=UTF-8");
   if (output == NULL) {
      wprintf (L"Failed to open output file.\n");
      return -1;
   }
   PrintChessBoard (output);
   fclose (output);
   int result = CompareFiles ("output.txt", "ref.txt");
   return result;
}