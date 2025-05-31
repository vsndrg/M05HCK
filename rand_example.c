#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
  int i;

  printf("RAND_MAX is %u\n\n", RAND_MAX);
  srand(time(0));

  printf("random values from 0 to RAND_MAX\n");
  for (i = 0; i < 8; i++)
    printf("%d\n", rand());

  printf("\nrandom values from 1 to 30\n");
  for (i = 0; i < 8; i++)
    printf("%d\n", (rand() % 30) + 1);

  return 0;
}
