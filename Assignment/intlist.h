// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------
/// <summary>
/// Implementation of a linked list data structure to handle integer elements.The implementation will consist of three files :
/// intlist.h - the header file
/// intlist.c - the code.
/// testintlist.c - the program that tests the implementation.
/// -------------------------------------------------------------------
/// The following functions have been implemented:
/// a)	Create – this will create a new linked list.
/// b)	Delete – this will delete the list and all the linked elements.
/// c)	Add – this will add an element to the end of the list.
/// d)	Insert – this will insert an element at a particular index(zero based).
/// e)	RemoveAt – this will remove the element at a particular index(zero based).
/// f)	Remove – removes the first occurrence of a specific element.
/// g)	Count – number of elements in the list.
/// h)	Get – gets the element at a particular index.
/// --------------------------------------------------------------------
/// </summary>
// intlist.h
// Program for Linked List Header file.
// ------------------------------------------------------------------------------------------------

#ifndef INTLIST_H
#define INTLIST_H
// Error codes
#define SUCCESS 0                  
#define ERROR_MEMORY_ALLOCATION -1 
#define ERROR_INVALID_INDEX -2    
#define ERROR_OUT_OF_BOUNDS -3     
#define ERROR_NOT_FOUND -4         

// Define the structure for a node in the linked list
typedef struct Node {
   int data;
   struct Node* next;
} Node;

// Define the structure for the linked list
typedef struct LinkedList {
   Node* head;
} LinkedList;

/// <summary>Creates and initializes a new linked list.</summary>
LinkedList* Create ();

/// <summary>Print the elements of the linked list.</summary>
void PrintList (LinkedList* list);

/// <summary>Adds a new element to the end of the linked list.</summary>
int Add (LinkedList* list, int val);

/// <summary>Inserts a new element at the specified index in the list.</summary>
int Insert (LinkedList* list, int index, int val);

/// <summary>Removes the node at the specified index from the list.</summary>
int RemoveAt (LinkedList* list, int index);

/// <summary>Removes the first occurrence of the specified value from the list.</summary>
int Remove (LinkedList* list, int val);

/// <summary>Counts the total number of elements in the list.</summary>
int Count (LinkedList* list);

/// <summary>Retrieves the value of the node at the specified index in the list.</summary>
int Get (LinkedList* list, int index, int* val);

/// <summary>Frees all nodes and the list structure itself.</summary>
void Delete (LinkedList* list);

#endif

