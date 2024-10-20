#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Create a new node with void* data
Node* create_node(void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert at the head of the list
void insert_at_head(Node** head, void* data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert at the tail of the list
void insert_at_tail(Node** head, void* data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Search for a node with a specific value using a comparison function
Node* search(Node* head, void* data, int (*cmp_func)(void*, void*)) {
    Node* temp = head;
    while (temp != NULL) {
        if (cmp_func(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Delete a node with a specific value using a comparison function
void delete_node(Node** head, void* data, int (*cmp_func)(void*, void*)) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && cmp_func(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return; // Node with the given data not found
    }

    if (prev == NULL) {
        *head = temp->next;  // Node to delete is the head
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Print the list using a provided print function
void print_list(Node* head, void (*print_func)(void*)) {
    Node* temp = head;
    while (temp != NULL) {
        print_func(temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the entire list
void free_list(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
