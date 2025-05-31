#include <stdio.h>
#include <unistd.h>

int main( void )
{
  printf("real uid: %d\n", getuid());
  printf("effective uid: %d\n", geteuid());
}

