// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------
// Implementation of a linked list data structure to handle integer elements.The implementation will consist of three files :
// intlist.h - the header file
// intlist.c - the code.
// testintlist.c - the program that tests the implementation.
// -------------------------------------------------------------------
// The following functions have been implemented:
// a)	Create – this will create a new linked list.
// b)	Delete – this will delete the list and all the linked elements.
// c)	Add – this will add an element to the end of the list.
// d)	Insert – this will insert an element at a particular index(zero based).
// e)	RemoveAt – this will remove the element at a particular index(zero based).
// f)	Remove – removes the first occurrence of a specific element.
// g)	Count – number of elements in the list.
// h)	Get – gets the element at a particular index.
// --------------------------------------------------------------------
// intlist.h
// Program for Linked List Header file.
// ------------------------------------------------------------------------------------------------
#ifndef INTLIST_H
#define INTLIST_H
// Define the structure for a node in the linked list
typedef struct Node {
	int data;
	struct Node* next;
} Node;
// Define the structure for the linked list
typedef struct LinkedList {
	Node* head;
} LinkedList;
// Function prototypes
LinkedList* Create ();
void PrintList (LinkedList* list);
void Add (LinkedList* list, int val);
int Insert (LinkedList* list, int index, int val);
int RemoveAt (LinkedList* list, int index);
void Remove (LinkedList* list, int val);
int Count (LinkedList* list);
int Get (LinkedList* list, int index);
void Delete (LinkedList* list);

#endif

