#ifndef LIST_H_
#define LIST_H_

typedef struct List List;

struct List {
  List *next;
  char token;
};

void append(List *head, char c);
List *find(List *head, int (*f)(List *needle));
void insert_before(List **head, List *to, char c);
void insert_after(List *to, char c);
void clean(List *head);

#endif /* LIST_H_ */
