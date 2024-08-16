// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program for Linked List functions.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "intlist.h"
// Function to create a new linked list
LinkedList* Create () {
	LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList)); // Allocate memory for the list structure
	if (list == NULL) {
		printf ("Memory allocation failed\n");
		return NULL;
	}
	list->head = NULL; // Initialize the head pointer to NULL, Indicating an empty list
	return list;
}

// Function to add an element to the end of the list
void Add (LinkedList* list, int val) {
	Node* newNode = (Node*)malloc (sizeof (Node)); // Allocate memory for the new node
	if (newNode == NULL) {
		fprintf (stderr, "Memory allocation failed!\n");
		exit (EXIT_FAILURE);
	}
	newNode->data = val;
	newNode->next = NULL;
	if (list->head == NULL) {
		list->head = newNode;
	}
	else {
		Node* current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

// Function to insert an element at a particular index (zero-based)
int Insert (LinkedList* list, int index, int val) {
	if (index < 0) {
		printf ("invalid index: %d\n", index);
		return 0;
	}
	Node* newNode = (Node*)malloc (sizeof (Node));
	if (newNode == NULL) {
		printf ("Memory allocation is failed!\n");
		exit (EXIT_FAILURE);
	}
	newNode->data = val;
	if (index == 0) {
		newNode->next = list->head;
		list->head = newNode; // Insert at the head of the list
	}
	else {
		Node* current = list->head;
		int i = 0;
		while (current != NULL && i < index - 1) {
			current = current->next;
			i++;
		}
		if (current == NULL) {
			printf ("index is out of bound:%d\n", index);
			free (newNode);
			return 0;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	printf ("List after inserting %d at index %d:\n", val, index);
	return 1;
}

//Function to remove the element at a particular index (zero-based)
int RemoveAt (LinkedList* list, int index) {
	if (index < 0) {
		printf ("Invalid Index: %d\n", index);
		return 0;
	}
	Node* current = list->head;
	Node* prev = NULL;
	int i = 0;
	while (current != NULL && i < index) {
		prev = current;
		current = current->next; // Traverse to the desired index
		i++;
	}
	if (current == NULL) {
		printf ("index is out of bound: %d\n", index);
		return 0;
	}
	if (prev == NULL)
		list->head = current->next;

	else {
		prev->next = current->next;
	}
	free (current);
	printf ("List after removing element at index %d:\n", index);
	return 1;
}

//Function to remove the first occurrence of a specific element
void Remove (LinkedList* list, int val) {
	if (list->head == NULL) {
		return;
	}
	Node* current = list->head;
	Node* prev = NULL;
	if (current != NULL && current->data == val) {
		list->head = current->next; // Remove the head node if it contains the value
		free (current);
		return;
	}
	while (current != NULL && current->data != val) {
		prev = current;
		current = current->next; // Traverse to find the node with the value
	}
	if (current == NULL) {
		return;
	}
	prev->next = current->next;
	free (current);
	printf ("List after removing first occurrence of element %d\n", val);
}

// Function to Return the number of elements in the list
int Count (LinkedList* list) {
	int count = 0;
	Node* current = list->head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

//Function to get the element at a particular index(zero-based)
int Get (LinkedList* list, int index) {
	Node* current = list->head;
	for (int i = 0; i < index; i++) {
		if (current == NULL) {
			printf ("Index %d is out of bound\n", index);
			return -1;
		}
		current = current->next;
	}
	if (current == NULL) {
		printf ("Index %d is out of bound\n", index);
		return -1;
	}
	printf ("Getting an element at index %d is:%d\n", index, current->data);
	return current->data;
}

// Function to delete the list and all its elements
void Delete (LinkedList* list) {
	Node* current = list->head;
	Node* next;
	while (current != NULL) {
		next = current->next;
		free (current);  // Free each node in the list
		current = next;
	}
	list->head = NULL; // Set the head pointer to NULL after deletion
	free (list);
}