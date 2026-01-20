#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create list
void createList() {
    int n, i, value;
    struct node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("List created successfully.\n");
}

// Function to insert at beginning
void insertAtBeginning() {
    struct node *newNode;
    int value;

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Function to display list
void display() {
    struct node *temp;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete at end
void deleteAtEnd() {
    struct node *temp, *prev;

    if(head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n---- MENU ----\n");
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Display list\n");
        printf("4. Delete at end\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("\nBefore insertion:\n");
                display();
                insertAtBeginning();
                printf("After insertion:\n");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}