#include "../../src/list.c"
#include <stdio.h>
#include <string.h>

List *str_to_list(char *str) {
  List *head = malloc(sizeof(List));
  if(!head) error("couldn't alloc pointer");
  List *curr = head;
  curr->next = NULL;
  for(int i = 0; str[i]; i++) {
    curr->token = str[i];
    if(str[i+1]) {
      curr->next = malloc(sizeof(List));
      if(!curr->next) error("couldn't alloc pointer");
      curr = curr->next;
      curr->next = NULL;
    }
  }
  return head;
}

void copy_list(List head, char *to) {
  List *curr = &head;
  int i = 0;
  for(; curr != NULL; curr = curr->next, ++i) {
    to[i] = curr->token;
  }
  to[i] = '\0';
}

void fill_list_after(List **head, char *nums) {
  List *curr;
  for(int i = 0; nums[i]; ++i) {
    curr = *head;
    if(curr->token > nums[i]) {
      insert_before(head, *head, nums[i]);
      continue;
    }
    while(curr) {
      if((curr->next &&
	  curr->next->token > nums[i])
	 || !curr->next) {
	insert_after(curr, nums[i]);
	break;
      }
      curr = curr->next;
    }
  }
}

void fill_list_before(List **head, char *nums) {
  List *curr;
  for(int i = 0; nums[i]; ++i) {
    curr = *head;
    while(curr) {
      if(curr->token > nums[i]) {
	insert_before(head, curr, nums[i]);
	break;
      } else if (!curr->next) {
	append(*head, nums[i]);
	break;
      } 
      curr = curr->next;
    }
  }
}

int f(List *l) {
  return l->token == 'D';
}

int main(void) {
  /* find function test*/
  char *afternums = "0526";
  char *beforenums = "8719";
  char result[100] = {0};
  List **head = malloc(sizeof(List));

  List *find_test = str_to_list("abcDefg");
  copy_list(*find_test, result);
  find_test = find(find_test, f);
  copy_list(*find_test, result);
  assert(!strcmp(result, "Defg"));
  /* end find function test 
   * test append, insert before, and insert after
   */
  List *start = malloc(sizeof(List));
  start->token = '3';
  start->next = NULL;
  
  *head = start;
  append(*head, '4');
  fill_list_after(head, afternums);
  fill_list_before(head, beforenums);
  copy_list(**head, result);
  assert(!strcmp(result, "0123456789"));
  clean(*head);
}
