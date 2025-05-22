#include <stdio.h>

void function( void )
{
  int var = 5;
  static int static_var = 228;

  printf("[in funciton] var = %d\n", var);
  printf("[in funciton] static_var = %d\n", static_var);
  var++;
  static_var++;
}

int main( void )
{
  int i;
  static int static_var = 30;

  for (i = 0; i < 5; i++)
  {
    printf("[in main] static_var = %d\n", static_var);
    function();
  }

  return 0;
}
