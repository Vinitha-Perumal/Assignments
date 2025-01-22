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
void PrintOutput (FILE* output, const wchar_t* character);

void PrintOutput (FILE* output, const wchar_t* character) {
   if (*character != L'\0') {
      fputws (character, output);
      wprintf (L"%s", character);
   }
}

void PrintChessBoard (FILE* output) {
   wchar_t* whitePieces[8] = { L"\u2656", L"\u2658", L"\u2657", L"\u2655", L"\u2654", L"\u2657", L"\u2658", L"\u2656" },
      * blackPieces[8] = { L"\u265C", L"\u265E", L"\u265D", L"\u265B", L"\u265A", L"\u265D", L"\u265E", L"\u265C" },
      * whitePawn = L"\u2659", * blackPawn = L"\u265F";
  // top border
   PrintOutput (output, L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
   for (int i = 0; i < 8; i++) {
      // left vertical border
      PrintOutput (output, L"┃ ");
      for (int j = 0; j < 8; j++) {
         wchar_t* piece = L'\0';
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
               piece = L" ";
               break;
         }
         PrintOutput (output, piece);
         PrintOutput (output, j < 7 ? L" ┃ " : L" ┃");
      }
      PrintOutput (output, L"\n");
      if (i < 7) PrintOutput (output, L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
   }
   // bottom border
   PrintOutput (output, L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
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