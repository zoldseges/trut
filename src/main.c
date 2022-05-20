/*
 * ATOM : [A-Z];
 *
 * OP : '&' | '|' | '>';
 *
 * FORMULA : <ATOM> | '!' <ATOM> | '(' <FORMULA> <OP> <FORMULA> ')'; 
 */

/*
 * A > B == !A | B
 */

#include <stdbool.h>

enum Type {
  ATM,
  NEG,
  KON,
  DIS,
  IMP,
  NONE,
};

typedef struct Formula Formula;

struct TrueFormula {
  Formula *left;
  Formula *right;
  bool value;
};

struct Formula {
  enum Type type;
  union {
    struct TrueFormula *formula;
    char *atom;
  } data;
};

int main(void) {
  // TOKENIZE
  // SET PRECEDENCE ( PUT BRACKETS )
  // PARSE
  return 0;
}
