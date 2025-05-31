#include <stdio.h>
#include <stdlib.h>

#define ADDRESS_WIDTH 30

int global_var;
int global_initialized_var = 30;

void print_address( char *text, void *ptr )
{
  printf("%-41s %*p\n", text, ADDRESS_WIDTH, ptr);
}

void nextl( void )
{
  printf("\n");
}

void function( void )
{
  int stack_var;
  
  print_address("the function's stack_var is at address", &stack_var);
}

int main( void )
{
  int stack_var;

  static int static_initialized_var = 30;
  static int static_var;

  int *heap_var_ptr;

  heap_var_ptr = (int *)malloc(sizeof(int));

  print_address("global_initialized_var is at address", &global_initialized_var);
  print_address("static_initialized_var is at address", &static_initialized_var);
  nextl();
  
  print_address("global_var is at address", &global_var);
  print_address("static_var is at address", &static_var);
  nextl();

  print_address("heap_var is at address", heap_var_ptr);
  nextl();

  print_address("stack_var is at address", &stack_var);
  function();
}

