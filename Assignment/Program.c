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
void PrintCell (FILE* output, wchar_t piece);

void PrintCell (FILE* output, wchar_t piece) {
   if (piece != L'\0') {
      fwprintf (output, L" %lc ", piece);
      wprintf (L" %lc ", piece);
   }
   else {
      fputws (L"   ", output);
      wprintf (L"   ");
   }
}

void PrintChessBoard (FILE* output) {
   const wchar_t* topBorder = L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n",
      * middleBorder = L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n",
      * bottomBorder = L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n";
   wchar_t whitePieces[8] = { 0x2656, 0x2658, 0x2657, 0x2655, 0x2654, 0x2657, 0x2658, 0x2656 },
      blackPieces[8] = { 0x265C, 0x265E, 0x265D, 0x265B, 0x265A, 0x265D, 0x265E, 0x265C },
      whitePawn = 0x2659, blackPawn = 0x265F;
   // top border
   fputws (topBorder, output);
   wprintf (L"%s", topBorder);
   for (int i = 0; i < 8; i++) {
      // left vertical border
      fputws (L"┃", output);
      wprintf (L"┃");
      for (int j = 0; j < 8; j++) {
         wchar_t piece = L'\0';
         switch (i) {
            case 0:
               piece = blackPieces[j];
               break;
            case 1:
               piece = blackPawn;
               break;
            case 6:
               piece = whitePawn;
               break;
            case 7:
               piece = whitePieces[j];
               break;
         }
         PrintCell (output, piece);
         fputws (L"┃", output);
         wprintf (L"┃");
      }
      wprintf (L"\n");
      fputws (L"\n", output);
      if (i < 7) {
         fputws (middleBorder, output);
         wprintf (L"%s", middleBorder);
      }
   }
   // bottom border
   fputws (bottomBorder, output);
   wprintf (L"%s", bottomBorder);
}

int CompareFiles (const char* outputFile, const char* referenceFile) {
   FILE* output = fopen (outputFile, "r, ccs=UTF-8"),
      * reference = fopen (referenceFile, "r, ccs=UTF-8");
   if (output == NULL || reference == NULL) {
      wprintf (L"Error opening files for comparison.\n");
      return -1;
   }
   int row = 1, col = 1;
   while (1) {
      wchar_t outputChar, referenceChar;
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
   return CompareFiles ("output.txt", "ref.txt");
}