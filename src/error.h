#ifndef ERROR_H_
#define ERROR_H_

#include <stdio.h>
#include <stdlib.h>

void error(char *msg) {
  fprintf(stderr, "%s:%d: %s", __FILE__, __LINE__, msg);
  exit(1);
}

#endif /* ERROR_H_ */
