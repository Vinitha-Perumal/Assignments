// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Program on testing the Linked List function.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "intlist.h"

void PrintList (LinkedList* list) {
   if (list->head == NULL) printf ("The list is empty\n");
   else {
      Node* current = list->head;
      while (current != NULL) {
         printf ("%d -> ", current->data);
         current = current->next;
      }
      printf ("NULL\n");
   }
}

int main () {
   LinkedList* list = Create ();
   if (list == NULL) {
      fprintf (stderr, "Failed to create the list\n");
      return 1;
   }
   printf ("The list has been created!\n");
   printf ("\n");

   // Adding elements
   Add (list,-3);
   Add (list, 3);
   Add (list, 2);
   Add (list, 5);
   printf ("Initial List is:\n");
   PrintList (list);
   printf ("\n");

   // Insert an element
   int indexToInsert = 1;
   int valToInsert = 5;
   int res = Insert (list, indexToInsert, valToInsert);
   if (res == SUCCESS) printf ("List after inserting %d at index %d:\n", valToInsert, indexToInsert);
   else fprintf (stderr, "Failed to insert element %d at index %d\n", valToInsert, indexToInsert);
   PrintList (list);
   printf ("\n");

   // Remove an element by index
   int indexToRemoveAt = 2;
   if (RemoveAt (list, indexToRemoveAt) == SUCCESS) printf ("List after removing element at index %d:\n", indexToRemoveAt);
   else fprintf (stderr, "Failed to remove element at index %d\n", indexToRemoveAt);
   PrintList (list);
   printf ("\n");

   // Remove an element by value
   int valueToRemove = 5;
   if (Remove (list, valueToRemove) == SUCCESS) printf ("List after removing element %d:\n", valueToRemove);
   else fprintf (stderr, "Failed to remove element %d\n", valueToRemove);
   PrintList (list);
   printf ("\n");

   // Count the elements
   printf ("Number of elements in the list: %d\n", Count (list));
   printf ("\n");

   // Get an element by index
   int val;
   res = Get (list, 0, &val);
   if (res == ERROR_OUT_OF_BOUNDS) fprintf (stderr, "Failed to get element at index %d, error code: %d\n", 0, res); 
   else printf ("Element at index %d is: %d\n", 0, val);
   printf ("\n");

   // Delete the list
   Delete (list);
   printf ("The list has been deleted\n");
   printf ("\n");

   return 0;
}