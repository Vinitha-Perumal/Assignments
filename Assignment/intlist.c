// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program for Linked List functions.
// ------------------------------------------------------------------------------------------------

#include <malloc.h> 
#include "intlist.h"

LinkedList* Create () {
   LinkedList* list = (LinkedList*)malloc (sizeof (LinkedList)); 
   if (list == NULL) return NULL;
   list->head = NULL; // Initialize the head pointer to NULL, Indicating an empty list
   return list;
}

int Add (LinkedList* list, int val) {
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) return ERROR_MEMORY_ALLOCATION;
   newNode->data = val;
   newNode->next = NULL;
   if (list->head == NULL) list->head = newNode;
   else {
      Node* current = list->head;
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = newNode;
   }
   return SUCCESS;
}

int Insert (LinkedList* list, int index, int val) {
   if (index < 0) return ERROR_INVALID_INDEX;
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) return ERROR_MEMORY_ALLOCATION;
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

int RemoveAt (LinkedList* list, int index) {
   if (index < 0) return ERROR_INVALID_INDEX;
   Node* current = list->head;
   Node* prev = NULL;
   for (int i = 0; i < index; i++) {
      if (current == NULL) return ERROR_OUT_OF_BOUNDS;
      prev = current;
      current = current->next;
   }
   if (current == NULL) return ERROR_OUT_OF_BOUNDS;
   if (prev == NULL) list->head = current->next;
   else prev->next = current->next;
   free (current);
   return SUCCESS;
}

int Remove (LinkedList* list, int val) {
   if (list->head == NULL) return ERROR_NOT_FOUND;
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
   if (current == NULL) return ERROR_NOT_FOUND;
   prev->next = current->next;
   free (current);
   return SUCCESS;
}

int Count (LinkedList* list) {
   int count = 0;
   Node* current = list->head;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}

int Get (LinkedList* list, int index, int* val) {
   if (index < 0) return ERROR_INVALID_INDEX;
   Node* current = list->head;
   for (int i = 0; i < index; i++) {
      if (current == NULL) return ERROR_OUT_OF_BOUNDS;
      current = current->next;
   }
   if (current == NULL) return ERROR_OUT_OF_BOUNDS;
   *val = current->data;
   return SUCCESS;
}

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