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

/// <summary>To print the chessboard to the given output file </summary>
void PrintChessBoard (FILE* output);

/// <summary>To compare the output file with a reference file </summary>
int CompareFiles (const char* outputFile, const char* referenceFile);

/// <summary>To print a character(or an empty space) to both the output file and the console </summary>
void PrintChar (FILE* output, int row, int col);

void PrintChar (FILE* output, int row, int col) {
   wchar_t whitePieces[8] = { 0x2656, 0x2658, 0x2657, 0x2655, 0x2654, 0x2657, 0x2658, 0x2656 },
      blackPieces[8] = { 0x265C, 0x265E, 0x265D, 0x265B, 0x265A, 0x265D, 0x265E, 0x265C },
      whitePawn = 0x2659, blackPawn = 0x265F, character = L'\0';
   switch (row) {
      case 0:
         character = blackPieces[col];
         break;
      case 1:
         character = blackPawn;
         break;
      case 6:
         character = whitePawn;
         break;
      case 7:
         character = whitePieces[col];
         break;
      default:
         character = L'\0';
         break;
   }
   if (character != L'\0') {
      fwprintf (output, L" %lc ", character);
      wprintf (L" %lc ", character);
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
   // top border
   fputws (topBorder, output);
   wprintf (L"%s", topBorder);
   for (int i = 0; i < 8; i++) {
      // left vertical border
      fputws (L"┃", output);
      wprintf (L"┃");
      for (int j = 0; j < 8; j++) {
         PrintChar (output, i, j);
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
      wchar_t outputChar = fgetwc (output), referenceChar = fgetwc (reference);
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