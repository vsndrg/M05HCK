
#include <stdio.h>

void function( void )
{
  int var = 5;
  static int static_var = 228;

  printf("[in funciton] var @ %p = %d\n", &var, var);
  printf("[in funciton] static_var @ %p = %d\n\n", &static_var, static_var);
  var++;
  static_var++;
}

int main( void )
{
  int i;
  static int static_var = 30;

  for (i = 0; i < 5; i++)
  {
    printf("[in main] static_var @ %p = %d\n", &static_var, static_var);
    function();
  }

  return 0;
}
