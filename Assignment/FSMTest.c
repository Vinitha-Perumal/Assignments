// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Vinitha Perumal - GET
// ------------------------------------------------------------------
// Test.c
// Program on A6B branch.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

int ExecProgram (char* exeFilePathAndName, const char* inputFilePathAndName, char* outputFilePathAndName);
bool CompareFiles (char* file1, const char* file2, int* pos, char* ch1, char* ch2);

/// <summary>
/// This function will execute the FSM providing the input and output file names as arguments
/// </summary>
/// <param name="exeFilePathAndName"></param>
/// <param name="inputFilePathAndName"></param>
/// <param name="outputFilePathAndName"></param>
/// <returns></returns>
int ExecProgram (char* exeFilePathAndName, const char* inputFilePathAndName, char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s%s%s%s%s", exeFilePathAndName, " ", inputFilePathAndName, " ", outputFilePathAndName);

   // Set up structures for process information
   STARTUPINFOA si;
   PROCESS_INFORMATION pi;

   // Initialize memory for STARTUPINFO and PROCESS_INFORMATION structures
   ZeroMemory (&si, sizeof (si));
   si.cb = sizeof (si);
   ZeroMemory (&pi, sizeof (pi));

   // Attempt to create the process
   if (!CreateProcessA (
      NULL,            // Application name (NULL if using command line)
      cmdline,          // Command line (path to the executable)
      NULL,            // Process handle not inheritable
      NULL,            // Thread handle not inheritable
      FALSE,           // Set handle inheritance to FALSE
      0,               // No creation flags
      NULL,            // Use parent's environment block
      NULL,            // Use parent's starting directory
      &si,             // Pointer to STARTUPINFO structure
      &pi))            // Pointer to PROCESS_INFORMATION structure
   {
      // If CreateProcess fails, print an error message
      int err = GetLastError ();
      printf ("Failed to start process. Error: %lu\n", GetLastError ());
      free (cmdline);
      return 1;
   }

   // Wait until the process has finished execution
   WaitForSingleObject (pi.hProcess, INFINITE);

   // Close handles
   CloseHandle (pi.hProcess);
   CloseHandle (pi.hThread);

   free (cmdline);
   return 0;

}

bool CompareFiles (char* file1, const char* file2, int* pos, char* ch1, char* ch2) {
   FILE* f1 = fopen (file1, "r"), * f2 = fopen (file2, "r");
   if (f1 == NULL || f2 == NULL) {
      printf ("Error opening files\n");
      return false;
   }
   fseek (f1, 0, SEEK_END);
   fseek (f2, 0, SEEK_END);
   long len1 = ftell (f1), len2 = ftell (f2);
   fseek (f1, 0, SEEK_SET);
   fseek (f2, 0, SEEK_SET);
   if (len1 != len2) {
      fclose (f1);
      fclose (f2);
      return false;
   }
   char* buffer1 = (char*)malloc (len1), * buffer2 = (char*)malloc (len2);
   if (buffer1 == NULL || buffer2 == NULL) {
      printf ("Memory allocation failed\n");
      fclose (f1);
      fclose (f2);
      return false;
   }
   fread (buffer1, 1, len1, f1);
   fread (buffer2, 1, len2, f2);
   for (long i = 0; i < len1; i++) {
      if (buffer1[i] != buffer2[i]) {
         *pos = i;
         *ch1 = buffer1[i];
         *ch2 = buffer2[i];
         free (buffer1);
         free (buffer2);
         fclose (f1);
         fclose (f2);
         return false;
      }
   }
   free (buffer1);
   free (buffer2);
   fclose (f1);
   fclose (f2);
   return true;
}

/// <summary>
/// Test Harness
/// </summary>
/// <param name="argc"></param>
/// <param name="argv">argv[1] is the name of the FSM</param>
/// <returns></returns>
int main (int argc, char** argv) {
#define NTESTS 6
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n", argv[0]);
      return -1;
   }
   const char* inputFiles[] = { "test1in.txt", "test2in.txt", "test3in.txt",
                                "test4in.txt", "test5in.txt", "test6in.txt" },
      * expectedFiles[] = { "test1ref.txt", "test2ref.txt", "test3ref.txt",
                         "test4ref.txt", "test5ref.txt", "test6ref.txt" };
   char outputFile[] = { "testout.txt" };
   for (int i = 0; i < NTESTS; i++) {
      const char* inputFile = inputFiles[i], * expectedFile = expectedFiles[i];
      if (ExecProgram (argv[1], inputFile, outputFile) != 0) {
         printf ("Error executing test %d\n", i + 1);
         return 1;
      }
      int pos = 0;
      char expectedChar, actualChar;
      if (!CompareFiles (outputFile, expectedFile, &pos, &expectedChar, &actualChar)) {
         printf ("Test %d failed with input file: %s\n", i + 1, inputFile);
         printf ("Test %d failed at bit %d, Expected '%c', actual '%c'\n", i + 1, pos, expectedChar, actualChar);
         return 1;
      }
   }
   printf ("All TestCases Passed\n");
   return 0;
}