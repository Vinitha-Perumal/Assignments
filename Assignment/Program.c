// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Program.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <io.h>
#include <fcntl.h>

/// <summary>To print the chessboard to the given output file </summary>
void PrintChessBoard (FILE* output);

/// <summary>To compare the output file with a reference file </summary>
bool CompareFiles (const char* outputFile, const char* referenceFile, int* mismatchRow, int* mismatchCol);

/// <summary>To print a character(or an empty space) to both the output file and the console </summary>
void PrintChar (FILE* output, wchar_t character);

void PrintChar (FILE* output, wchar_t character) {
   if (character != L'\0') {
      wchar_t tempArray[] = { character, L'\0' };
      fputws (tempArray, output);
      wprintf (L"%s", tempArray);
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
      fputws (L"┃ ", output);
      wprintf (L"┃ ");
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
            default:
               piece = L' ';
               break;
         }
         PrintChar (output, piece);
         fputws (L" ┃ ", output);
         wprintf (L" ┃ ");
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

bool CompareFiles (const char* outputFile, const char* referenceFile, int* mismatchRow, int* mismatchCol) {
   FILE* output = fopen (outputFile, "r, ccs=UTF-8"),
      * reference = fopen (referenceFile, "r, ccs=UTF-8");
   if (output == NULL || reference == NULL) return false;
   int row = 1, col = 1;
   while (1) {
      wchar_t outputChar = fgetwc (output), referenceChar = fgetwc (reference);
      if (outputChar == WEOF && referenceChar == WEOF) {
         fclose (output);
         fclose (reference);
         return true;
      }
      if (outputChar != referenceChar) {
         *mismatchRow = row, * mismatchCol = col;
         fclose (output);
         fclose (reference);
         return false;
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
   int mismatchRow = 0, mismatchCol = 0;
   bool res = CompareFiles ("output.txt", "ref.txt", &mismatchRow, &mismatchCol);
   wprintf (res ? L"\n\nTest Passed\n" : L"\nMismatch at row %d, column %d\n", mismatchRow, mismatchCol);
}