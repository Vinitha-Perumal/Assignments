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

int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName);
bool CompareFiles (char* file1, char* file2);

/// <summary>
/// This function will execute the FSM providing the input and output file names as arguments
/// </summary>
/// <param name="exeFilePathAndName"></param>
/// <param name="inputFilePathAndName"></param>
/// <param name="outputFilePathAndName"></param>
/// <returns></returns>
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName) {
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

bool CompareFiles (char* file1, char* file2) {
   FILE* f1 = fopen (file1, "r"), * f2 = fopen (file2, "r");
   if (f1 == NULL || f2 == NULL) {
      printf ("Error opening files\n");
      return false;
   }
   int pos = 0, ch1, ch2;
   while ((ch1 = fgetc (f1)) != EOF && (ch2 = fgetc (f2)) != EOF) {
      if (ch1 != ch2) {
         printf ("Error at bit no. %d, Expected %c, Actual %c\n", pos, ch1, ch2);
         fclose (f1);
         fclose (f2);
         return false;
      }
      pos++;
   }
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
#define NTESTS 7
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n", argv[0]);
      return -1;
   }
   char* inputFiles[] = { "test1in.txt", "test2in.txt", "test3in.txt", "test4in.txt",
                                "test5in.txt", "test6in.txt", "test7in.txt" },
      * outputFiles[] = { "test1out.txt", "test2out.txt", "test3out.txt", "test4out.txt",
                          "test5out.txt", "test6out.txt", "test7out.txt" },
      * expectedFiles[] = { "test1ref.txt", "test2ref.txt", "test3ref.txt", "test4ref.txt",
                          "test5ref.txt", "test6ref.txt", "test7ref.txt" };

   for (int i = 0; i < NTESTS; i++) {
      char* inputFile = inputFiles[i],
         * outputFile = outputFiles[i],
         * expectedFile = expectedFiles[i];
      printf ("Running test %d with input file: %s\n", i + 1, inputFile);
      if (ExecProgram (argv[1], inputFile, outputFile) != 0) {
         printf ("Error executing test %d\n", i + 1);
         continue;
      }
      // Compare the output with the expected reference file
      if (CompareFiles (outputFile, expectedFile)) printf ("Test %d passed\n\n", i + 1);
      else printf ("Test %d failed\n\n", i + 1);
   }
   return 0;
}