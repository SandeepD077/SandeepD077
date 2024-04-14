#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};

// Function to create a new node
struct node* createNode(int dat) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = dat;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct node **head, int dat) {
  struct node *newNode = createNode(dat);
  if (*head == NULL) {
    *head = newNode;
  } else {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct node **head, int dat) {
  struct node *newNode = createNode(dat);
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

// Function to insert a node after a specific node in the doubly linked list
void insertAfterNode(struct node *prevNode, int dat) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL.\n");
    return;
  }
  struct node *newNode = createNode(dat);
  newNode->next = prevNode->next;
  if (prevNode->next != NULL) {
    prevNode->next->prev = newNode;
  }
  prevNode->next = newNode;
  newNode->prev = prevNode;
}

// Function to delete the first node of the doubly linked list
void deleteFirstNode(struct node **head) {
  if (*head == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
  }
  struct node *temp = *head;
  *head = (*head)->next;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
  free(temp);
}

// Function to delete the last node of the doubly linked list
void deleteLastNode(struct node **head) {
  if (*head == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
  }
  struct node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    *head = NULL;
  }
  free(temp);
}

// Function to delete a specific node from the doubly linked list
void deleteNode(struct node **head, struct node *delNode) {
  if (*head == NULL || delNode == NULL) {
    printf("List is empty or the node to be deleted is NULL.\n");
    return;
  }
  if (*head == delNode) {
    *head = delNode->next;
  }
  if (delNode->next != NULL) {
    delNode->next->prev = delNode->prev;
  }
  if (delNode->prev != NULL) {
    delNode->prev->next = delNode->next;
  }
  free(delNode);
}

// Function to display the elements of the doubly linked list
void display(struct node *head) {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct node *head = NULL;

  // Inserting elements at the beginning of the doubly linked list
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);

  // Displaying the doubly linked list
  printf("Doubly Linked List: ");
  display(head);

  // Inserting elements at the end of the doubly linked list
  insertAtEnd(&head, 40);
  insertAtEnd(&head, 50);

  // Displaying the doubly linked list
  printf("Doubly Linked List after insertion at end: ");
  display(head);

  // Inserting element after a specific node
  insertAfterNode(head->next, 25);
  printf("Doubly Linked List after insertion after a specific node: ");
  display(head);

  // Deleting the first node
  deleteFirstNode(&head);
  printf("Doubly Linked List after deleting the first node: ");
  display(head);

  // Deleting the last node
  deleteLastNode(&head);
  printf("Doubly Linked List after deleting the last node: ");
  display(head);

  // Deleting a specific node
  deleteNode(&head, head->next);
  printf("Doubly Linked List after deleting a specific node: ");
  display(head);

  return 0;
}
