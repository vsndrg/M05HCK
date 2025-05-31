#include <stdio.h>

int func_one( void )
{
  printf("This is function one\n");
  return 1;
}

int func_two( void )
{
  printf("This is function two\n");
  return 2;
}

int main( void )
{
  int value;
  int (*func_ptr)();

  func_ptr = func_one;
  printf("func_ptr is %p\n", func_ptr);
  value = func_ptr();
  printf("value returned was %d\n\n", value);

  func_ptr = func_two;
  printf("func_ptr is %p\n", func_ptr);
  value = func_ptr();
  printf("value returned was %d\n", value);

  return 0;
}
