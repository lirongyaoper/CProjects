#include <stdio.h>
#include <stdlib.h>

// Define the structure of a singly linked list node
typedef struct ListNode {
    int val;             // The value stored in the node
    struct ListNode *next; // Pointer to the next node
} ListNode;

// Create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;  // Assign a value to the new node
    newNode->next = NULL; // Initialize the next pointer of the new node to NULL
    return newNode;
}

// Reverse the singly linked list recursively
ListNode* reverseListRecursive(ListNode** head) {
    // If the linked list is empty or has only one node, return the head directly
    if ((*head) == NULL || (*head)->next == NULL) {
        return (*head);
    }
    // Recursively call the function to reverse the linked list after the current node
    ListNode* newHead = reverseListRecursive(&(*head)->next);
    // Make the next pointer of the next node of the current node point to the current node, 
    //achieving local reversal
    //(*head)->next->next = (*head);
    ListNode* temp = (*head) ->next;
    // Set the next pointer of the current node to NULL
    //(*head)->next = NULL;
    temp -> next = (*head);
    (*head)->next = NULL;
    // Return the new head node
    return newHead;
}

// Print the singly linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val); // Print the value of the current node
        temp = temp->next;        // Move to the next node
    }
    printf("\n");
}

// Free the memory of the linked list
void freeList(ListNode* head) {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create a simple linked list: 1 -> 2 -> 3
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list recursively
    head = reverseListRecursive(&head);

    printf("Reversed linked list: ");
    printList(head);

    // Free the memory of the linked list
    freeList(head);

    return 0;
}    