#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main(int argc, char** argv) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getopl(s)) != EOF) {
    switch (type) {
    case NUMBER:
      pushy(atof(s));
      break;
    case '+':
      pushy(popy() + popy());
      break;
    case '*':
      pushy(popy() * popy());
      break;
    case '-':
      op2 = popy();
      pushy(popy() - op2);
      break;
    case '/':
      op2 = popy();
      if (op2 != 0.0)
        pushy(popy() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", popy());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
