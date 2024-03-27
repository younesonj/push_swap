#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to push a new node onto the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to move the first node to the end and the last node to the beginning
void moveFirstToEnd(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    struct Node* last = *head_ref;
    struct Node* secondLast = NULL;

    // Traverse to the last node and find the second-to-last node
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // Make the last node point to the first node
    last->next = *head_ref;

    // Update the head of the list to point to the second node (previous first node)
    *head_ref = (*head_ref)->next;

    // Update the second-to-last node to point to NULL
    secondLast->next = NULL;
}


// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test functions
int main() {
    struct Node* head = NULL;
    
    // Push elements onto the list
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    printf("Original Linked List: ");
    printList(head);
    
    // Move the first node to the end and the last node to the beginning
    moveFirstToEnd(&head);
    
    printf("Linked List after moving first node to end and last node to beginning: ");
    printList(head);
    
    return 0;
}
