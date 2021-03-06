#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node* make_node(int i) {
  struct node* n;
  n = calloc(sizeof(struct node), 1);
  n->i = i;
  n->next = NULL;
  return n;
}

void print_list(struct node* n) {
  if (n == NULL) {
    printf("\x1b[31mNULL\x1b[0m\n");
    return;
  }
  struct node* p = n;
  int i = 4;
  while (p != NULL) {
    printf("| %d | --> ", p->i);
    if (p->next == NULL) break;
    p = p->next;
  }
  printf("\x1b[31mNULL\x1b[0m\n");
}

struct node* insert_front(struct node* n, int i) {
  //Accidentally added to the end xD
  //
  // //go through list to end
  // struct node* p = n;
  // while (p->next != NULL) {
  //   p = p->next;
  // }
  //
  // //add node
  // p->next = make_node(i);
  //
  // return n;

  //allocate memory for new node
  struct node* new = calloc(sizeof(struct node), 1);

  //set value
  new->i = i;

  //point to old head
  new->next = n;

  //return
  return new;
}

//recursive free_list
//if you're at the end of the list, free yourself
//else, tell the next el to free itself then free yourself
//returns ptr to location of 1st element (which should be freed)
struct node* free_list(struct node* n) {
  if (n->next == NULL) {
    free(n);
    n = NULL;
  }
  else {
    free_list(n->next);
    free(n);
    n = NULL;
  }
  return n;
}
