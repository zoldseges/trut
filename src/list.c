#include "list.h"
#include "error.h"
#include <stdlib.h>
#include <assert.h>

void append(List *head, char c) {
  List *curr = head;
  List *p = malloc(sizeof(List));
  if(!p) error("couldn't alloc pointer\n");
  p->next = NULL;
  p->token = c;
  while(curr->next) curr = curr->next;
  p->next = NULL;
  curr->next = p;
}

List *find(List *head, int (*f)(List *needle)) {
  List *curr = head;
  for(; curr; curr = curr->next) {
    if(f(curr)) break;
  }
  return curr;
}

void insert_before(List **head, List *to, char c) {
  List *new = malloc(sizeof(List));
  if(!new) error("couldn't alloc pointer\n");
  new->token = c;

  if(*head == to) {
    new->next = *head;
    *head = new;
  } else {
    List *prev = *head;
    while(prev) {
      if(prev->next == to) {
	prev->next = new;
	new->next = to;
      }
      prev = prev->next;
    }
  }
}

void insert_after(List *to, char c) {
  List *new = malloc(sizeof(List));
  if(!new) error("couldn't alloc pointer\n");
  new->token = c;
  new->next = to->next;
  to->next = new;
}

void clean(List *head) {
  List *tmp = head;
  while(head) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}
