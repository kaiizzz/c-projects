#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a node in the linked list
typedef struct Node {
    void* data;            // A void pointer to store any data type
    struct Node* next;     // Pointer to the next node
} Node;

// Function prototypes for linked list operations

// Create a new node with the given data (void*)
Node* create_node(void* data);

// Insert a new node at the beginning of the list
void insert_at_head(Node** head, void* data);

// Insert a new node at the end of the list
void insert_at_tail(Node** head, void* data);

// Search for a node with specific data (requires a comparison function)
Node* search(Node* head, void* data, int (*cmp_func)(void*, void*));

// Delete a node with specific data (requires a comparison function)
void delete_node(Node** head, void* data, int (*cmp_func)(void*, void*));

// Print the elements in the list (requires a print function)
void print_list(Node* head, void (*print_func)(void*));

// Free all the nodes in the list
void free_list(Node** head);

#endif /* LINKED_LIST_H */
