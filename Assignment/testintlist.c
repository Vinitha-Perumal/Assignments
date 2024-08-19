// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Program on testing the Linked List function.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "intlist.h"
// Function to print the list
void PrintList (LinkedList* list) {
	if (list->head == NULL) {
		printf ("The list is empty\n");
	}
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
		printf ("Failed to create the list\n");
		return 1;
	}
	printf ("The list has been created!\n");
	printf ("\n");

	// Adding elements
	Add (list, 7);
	Add (list, 3);
	Add (list, 2);
	Add (list, 5);
	printf ("Initial List is:\n");
	PrintList (list);
	printf ("\n");

	// Insert an element
	Insert (list, 1, 5);
	PrintList (list);
	printf ("\n");

	// Remove an element by index
	RemoveAt (list, 2);
	PrintList (list);
	printf ("\n");

	// Remove an element by value
	Remove (list, 5);
	PrintList (list);
	printf ("\n");

	// Count the elements
	printf ("Number of elements in the list: %d\n", Count (list));
	printf ("\n");

	// Get an element by index
	Get (list, 0);
	printf ("\n");

	// Delete the list
	Delete (list);
	printf ("The list has been deleted\n");
	PrintList (list);
	printf ("\n");

	return 0;
}