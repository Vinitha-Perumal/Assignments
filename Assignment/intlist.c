// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program for Linked List functions.
// ------------------------------------------------------------------------------------------------

#include <malloc.h>
#include "intlist.h"

/// <summary>
/// Function to create a new linked list
/// </summary>
/// <returns>Pointer to the newly created LinkedList</returns>
LinkedList* Create () {
	LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList)); // Allocate memory for the list structure
	if (list == NULL) {
		return NULL;
	}
	list->head = NULL; // Initialize the head pointer to NULL, Indicating an empty list
	return list;
}

/// <summary>
/// Add an element to the end of the list
/// </summary>
/// <param name="list"></param>
/// <param name="val"></param>
/// <returns>Error code (if any)</returns>
int Add (LinkedList* list, int val) {
	Node* newNode = (Node*)malloc (sizeof (Node)); // Allocate memory for the new node
	if (newNode == NULL) {
		return ERROR_MEMORY_ALLOCATION;
	}
	newNode->data = val;
	newNode->next = NULL;
	if (list->head == NULL) 
		list->head = newNode;
	
	else {
		Node* current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
	return SUCCESS;
}

/// <summary>
/// Insert an element at a particular index (zero-based)
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <param name="val"></param>
/// <returns>Error code (if any)</returns>
int Insert (LinkedList* list, int index, int val) {
	if (index < 0) {
		return ERROR_INVALID_INDEX;
	}
	Node* newNode = (Node*)malloc (sizeof (Node));
	if (newNode == NULL) {
		return ERROR_MEMORY_ALLOCATION;
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
			free (newNode);
			return ERROR_OUT_OF_BOUNDS;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	return SUCCESS;
}

/// <summary>
/// Remove the element at a particular index (zero-based)
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>Error code (if any)</returns>
int RemoveAt (LinkedList* list, int index) {
	if (index < 0) {
		return ERROR_INVALID_INDEX;
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
		return ERROR_OUT_OF_BOUNDS;
	}
	if (prev == NULL)
		list->head = current->next;
	
	else 
		prev->next = current->next;
	
	free (current);
	return SUCCESS;
}

/// <summary>
/// Remove the first occurrence of a specific element
/// </summary>
/// <param name="list"></param>
/// <param name="val"></param>
/// <returns>Error code (if any)</returns>
int Remove (LinkedList* list, int val) {
	if (list->head == NULL) {
		return ERROR_NOT_FOUND;
	}
	Node* current = list->head;
	Node* prev = NULL;
	if (current != NULL && current->data == val) {
		list->head = current->next; // Remove the head node if it contains the value
		free (current);
		return SUCCESS;
	}
   // Traverse the list to find the first node with the given value
	// If found, update the previous node's next pointer to bypass the node to be removed
	while (current != NULL && current->data != val) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) 
		return ERROR_NOT_FOUND;

	prev->next = current->next;
	free (current);
	return SUCCESS;
}

/// <summary>
/// Return the number of elements in the list
/// </summary>
/// <param name="list"></param>
/// <returns>The number of nodes in the linked list</returns>
int Count (LinkedList* list) {
	int count = 0;
	Node* current = list->head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

/// <summary>
/// Get the element at a particular index(zero-based)
/// </summary>
/// <param name="list"></param>
/// <param name="index"></param>
/// <returns>The value of the node at the specified index</returns>
int Get (LinkedList* list, int index) {
	Node* current = list->head;
	for (int i = 0; i < index; i++) {
		if (current == NULL) {
			return ERROR_OUT_OF_BOUNDS;
		}
		current = current->next;
	}
	if (current == NULL) {
		return ERROR_OUT_OF_BOUNDS;
	}
	return current->data;
}

/// <summary>
/// Delete the list
/// </summary>
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