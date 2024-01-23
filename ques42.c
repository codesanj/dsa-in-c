#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to search for an element in the list
int searchElement(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return 1; // Element found
        }
        current = current->next;
    }
    return 0; // Element not found
}

// Function to reverse the list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* nextNode = NULL;
    
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    
    *head = prev;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to sort the list in ascending order (using bubble sort)
void sortList(struct Node* head) {
    int swapped;
    struct Node* current;
    struct Node* lastNode = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->next != lastNode) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lastNode = current;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element at the end\n");
        printf("2. Search for an element\n");
        printf("3. Sort the list in ascending order\n");
        printf("4. Reverse the list\n");
        printf("5. Print the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                if (searchElement(head, target)) {
                    printf("Element found in the list.\n");
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 3:
                sortList(head);
                printf("List sorted in ascending order.\n");
                break;
            case 4:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 5:
                printList(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
