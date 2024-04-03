#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;           // Data of the node (you can change this to any non-pointer data type)
    struct Node* next;  // Pointer to the next node in the list
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add a node at a specified position in the list
void insertNode(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 0 || *head == NULL) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to remove a node at a specified position
void removeNodeAt(struct Node** head, int position) {
    if (position < 0 || *head == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position.\n");
            return;
        }
        struct Node* nodeToRemove = temp->next;
        temp->next = temp->next->next;
        free(nodeToRemove);
    }
}

// Function to remove a node by value (remove the first instance)
void removeNodeByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Function to view the value of the node at a certain position (0 indexed)
void viewNodeAt(struct Node* head, int position) {
    struct Node* temp = head;
    for (int i = 0; i < position && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        printf("Value at position %d: %d\n", position, temp->data);
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Add a node to the end of the list\n");
        printf("2. Add a node to a specified location in the list\n");
        printf("3. Remove a node at a specified location\n");
        printf("4. Remove a node by value\n");
        printf("5. View the value of the node at a certain position\n");
        printf("6. Display the linked list\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;
            case 2:
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the position to insert the new node: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            case 3:
                printf("Enter the position to remove the node: ");
                scanf("%d", &position);
                removeNodeAt(&head, position);
                break;
            case 4:
                printf("Enter the value to remove: ");
                scanf("%d", &data);
                removeNodeByValue(&head, data);
                break;
            case 5:
                printf("Enter the position to view the node: ");
                scanf("%d", &position);
                viewNodeAt(head, position);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                freeList(&head);
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }

    } while (choice != 7);

    return 0;
}
