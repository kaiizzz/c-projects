#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Function to compare integers (for use in search/delete)
int compare_int(void* a, void* b) {
    return (*(int*)a) - (*(int*)b);
}

// Function to print an integer (for use in print_list)
void print_int(void* data) {
    printf("%d -> ", *(int*)data);
}

int main() {
    Node* head = NULL;

    // Dynamically allocate integers to insert into the list
    int* val1 = malloc(sizeof(int));
    int* val2 = malloc(sizeof(int));
    int* val3 = malloc(sizeof(int));

    *val1 = 10;
    *val2 = 20;
    *val3 = 30;

    // Insert values into the list
    insert_at_head(&head, val1);
    insert_at_head(&head, val2);
    insert_at_tail(&head, val3);

    // Print the list
    printf("List: ");
    print_list(head, print_int);

    // Search for a value
    Node* found = search(head, val2, compare_int);
    if (found) {
        printf("\nFound value: %d\n", *(int*)found->data);
    } else {
        printf("\nValue not found\n");
    }

    // Delete a value
    delete_node(&head, val2, compare_int);
    printf("After deleting 20: ");
    print_list(head, print_int);

    // Free the list
    free_list(&head);

    // Free dynamically allocated memory for integers
    free(val1);
    free(val2);
    free(val3);

    return 0;
}
