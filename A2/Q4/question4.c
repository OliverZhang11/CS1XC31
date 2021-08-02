#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct node {
  int value;
  struct node *next;
  struct node *prev;
};

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}

void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
}

struct node *element(struct node *dll, int i) {
  struct node *ptr=dll;
  for(int index=0;index!=i && ptr!=NULL;index++) {
    ptr=ptr->next;
  }
  return ptr;
}


struct node *add(struct node *dll, int i, int value) {
  struct node * newnode = malloc(sizeof(struct node));
  newnode->value=value;
  newnode->next=NULL;
  newnode->prev=NULL;
    if(dll == NULL || i==0) {
      newnode->next=dll;
      if(dll!=NULL) {
        dll->prev=newnode;
      }
      return newnode; 
    }
    else {
      struct node *prev=dll;
      for(int index=0;index!=(i-1) && prev->next!=NULL;index++) {
        prev=prev->next;
      }
      newnode->next=prev->next;
      newnode->prev=prev;
      if(prev->next!=NULL) {
        prev->next->prev=newnode;
      }
      prev->next=newnode;
      return dll; 
    }
}

struct node *delete(struct node *dll, int i) {
  struct node *ptr=element(dll,i);
  if(ptr!=NULL) {
    if(ptr==dll) {
      dll=dll->next;
      if(dll!=NULL) {
        dll->prev=NULL;
      }
    }
    else {
      ptr->prev->next=ptr->next;
      if(ptr->next!=NULL) {
        ptr->next->prev=ptr->prev;
      }
    }
    free(ptr);
  }
  return dll;
}
