#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
  struct node *prev;
};
void node_crearet(struct node **v, int d) {
  struct node *nn;
  nn = (struct node *)malloc(sizeof(struct node));
  nn->data = d;
  nn->next = NULL;
  nn->prev = NULL;
  *v = nn;
}
void insert_at_beg(struct node **v, int d) {
  struct node *nn;
  nn = (struct node *)malloc(sizeof(struct node));
  nn->data = d;
  nn->prev = NULL;
  nn->next = NULL;
  if (*v == NULL) {
    *v = nn;
  } else {
    nn->next = (*v);
    (*v)->prev = nn;
    *v = nn;
  }
}
void insert_at_end(struct node **v, int d) {

  struct node *nn;
  nn = (struct node *)malloc(sizeof(struct node));
  nn->data = d;
  nn->prev = NULL;
  nn->next = NULL;
  if (*v == NULL) {
    *v = nn;
  } else {
    struct node *temp;
    temp = (*v);
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->prev = nn;
    nn->next = temp;
  }
}

void display(struct node *v) {
  while (v != NULL) {
    printf("%d ", v->data);
    v = v->next;
  }
  printf("\n");
}
int main() {
  struct node *head = NULL;

  node_crearet(&head, 72);
  insert_at_beg(&head, 80);
  insert_at_beg(&head, 74);
  insert_at_end(&head, 78);

  printf("Doubly linked list: ");
  display(head);

  return 0;
}