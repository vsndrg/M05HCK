#include <stdio.h>

int main( void )
{
  int i;
  
  char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
  int int_arr[5] = {1, 2, 3, 4, 5};

  char *char_ptr = int_arr;
  int *int_ptr = char_arr;

  for (int i = 0; i < 5; i++)
  {
    printf("[integer pointer] points to %p which cointains the integer %d\n", int_ptr, *int_ptr);
    int_ptr = int_ptr + 1;
  }

  for (int i = 0; i < 5; i++)
  {
    printf("[char pointer] points to %p which cointains the char '%c'\n", char_ptr, *char_ptr);
    char_ptr = char_ptr + 1;
  }

  return 0;
}
