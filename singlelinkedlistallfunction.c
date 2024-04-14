#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

// (1) Function to create a node and add it to the end of the linked list
void create(struct node **first, int dat) {
  struct node *ptr, *ctr;
  ctr = *first;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = dat;
  ptr->link = NULL;
  if (*first == NULL) {
    *first = ptr;
  }
  else {
    while (ctr->link != NULL) {
      ctr = ctr->link;
    }
    ctr->link = ptr;
  }
}

// (2) Function to recursively copy a linked list
struct node* copyList(struct node* head) {
  if (head == NULL) { 
    return NULL; 
  } 
  else { 
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = head->data; 
    newNode->link = copyList(head->link); 
    return newNode; 
  } 
}

// (3) Function to insert a new node at the beginning of the linked list
void insertatbegining(struct node **first,int dat){
  struct node * ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr -> data = dat;
  ptr -> link = *first;
  * first = ptr;
}

// (4) Function to display the elements of the linked list
void display(struct node *first) {
  struct node *ptr;
  ptr = first;
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->link;
  }
}

// (5) Function to insert a new node after a specific node in the linked list
void insertafternode(struct node** first,int check , int dat){
  struct node *ptr,*ctr,*ktr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = dat;
  ctr = *first;
  ktr = ctr->link;
  while(ctr->data != check){
    ctr = ctr -> link;
    ktr = ktr->link;
  }
  ctr->link = ptr;
  ptr-> link =ktr;
}

// (6) Function to insert a new node at the end of the linked list
void insertatlast(struct node** first, int dat){
  struct node *ptr,*ctr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ctr = *first;
  ptr->data = dat;
  ptr->link = NULL;
  while(ctr->link!=NULL){
    ctr = ctr-> link;
  }
  ctr ->link = ptr;
}

// (7) Function to delete the first node of the linked list
void deletefirstnode(struct node ** first){
  struct node * ptr;
  ptr = *first;
  *first=ptr-> link;
  free(ptr);
}

// (8) Function to delete the last node of the linked list
void deletelastnode(struct node ** first){
  struct node * ptr,*ctr;
  ptr = *first;
  ctr= ptr->link;
  while(ctr->link!= NULL){
    ptr = ptr-> link;
    ctr = ctr-> link;
  }
  ptr->link = NULL;
  free(ctr);
}

// (9) Function to delete a specific node from the linked list
void deletethespecific(struct node ** first,int dat){
  struct node * ptr,*ctr;
  ptr = *first;
  ctr =ptr->link;
  while(ctr->data!= dat){
    ptr= ptr-> link;
    ctr= ctr-> link;
  }
  ptr->link = ctr->link;
  free(ctr);
}

// (10) Function to reverse the linked list
void reversal(struct node **first){
  struct node * current,*next , *prev;
  current = *first;
  next = NULL;
  prev= NULL;
  while(current != NULL){
    next = current->link;
    current -> link = prev;
    prev = current;
    current = next;
  }
  *first = prev;
}

// (11) Function to concatenate two linked lists
void concatu(struct node**first,struct node **second){
  struct node*ctr,*ptr;
  ctr = *first;
  ptr= *second;
  while(ctr->link != NULL){
    ctr = ctr->link;
  }
  ctr->link = *second;
  *second = NULL;
}

// (12) Function to copy elements from one linked list to another
void copy (struct node**first,struct node **thir){
  struct node *ctr,*ptr,*head;
  ctr = (struct node*)malloc(sizeof(struct node));
  ptr = *first;
  ctr = *thir;
  ctr = ctr->link;
  while(ptr != NULL){
    ctr->data= ptr->data;
    ctr->link = ptr->link;
    ctr = ctr -> link;
    ptr = ptr ->link;
  }
}

// (13) Function to find the middle node of the linked list
int middlenode(struct node ** first){
  struct node *ptr,*ctr;
  ptr =*first;
  ctr =ptr->link->link;
  while(ctr->link != NULL){
    ptr = ptr ->link;
    ctr = ctr->link;
  }
  return ptr->data;
}

int main() {
  struct node *first = NULL;
  struct node *second = NULL;
  struct node *thir = NULL;
  
  create(&first, 10);
  create(&first, 20);
  create(&first, 30);
  create(&first, 40);
  create(&first, 50);
  create(&first, 60);
  
  create(&second, 10);
  create(&second, 20);
  create(&second, 30);
  create(&second, 40);
  create(&second, 50);
  create(&second, 60);

  // Uncomment below to test individual functions
  // display(first);
  // display(second);
  // copy(&first,&thir);
  thir = copyList(first);
  display(thir);
  int a = middlenode(&first);
  printf("\nMiddle node: %d\n", a);
  
  // Uncomment below to test other functions
  // insertatbegining(&first, 70);
  // insertafternode(&first,40,80);
  // deletefirstnode(&first);
  // deletelastnode(&first);
  // deletethespecific(&first,40);
  // insertatlast(&first,90);
  // display(first);
  // reversal(&first);
  // display(first);
  // concatu(&first,&second);
  // display(first);
  
  return 0;
}
