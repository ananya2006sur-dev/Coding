#include <stdio.h>

extern int reps = 0;

void f(void)
{ static int called = 0;
  called++;
  reps = reps +called;
}

int main(void)
{ auto int i;
  const int limit = 3;
  for (i = 0; i <= limit; i++)
  { f(); }
  printf("i = %d , reps = %d\n", i, reps);
  return 0;
}