#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "list.c"

//creates the nodes in another function to test if heap memory is allocated
struct node* test_heap_memory_allocation() {
  return make_node(rand() % 100);
}

int main() {
  unsigned long t = time(NULL);
  srand(t);
  printf("seed: %lu\n", t);
  struct node* head = test_heap_memory_allocation();
  print_list(head);

  int i = 6;
  while (i--) {
    insert_front(head, rand() % 100);
    print_list(head);
  }

  free_list(head);

  return 0;
}
