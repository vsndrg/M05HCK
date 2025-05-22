
#include <stdio.h>
#include <stdlib.h>

void usage( char *program_name )
{
  printf("Usage: %s <message> <# of times to repeat>\n", program_name);
  exit(1);
}

int main( int argc, char *argv[] )
{
  int i, cnt;

  /*
  if (argc < 3)
    usage(argv[0]);
  */

  cnt = atoi(argv[2]);
  printf("Repeating %d times...\n", cnt);

  for (i = 0; i < cnt; i++)
    printf("%d - %s\n", i, argv[1]);

  return 0;
}

