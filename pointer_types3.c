#include <stdio.h>

int main( void )
{
  int i;
  
  char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
  int int_arr[5] = {1, 2, 3, 4, 5};

  char *char_ptr;
  int *int_ptr;

  char_ptr = (char *)int_arr;
  int_ptr = (int *)char_arr;

  for (i = 0; i < 5; i++)
  {
    printf("[integer pointer] points to %p which cointains the integer %c\n", int_ptr, *int_ptr);
    int_ptr = (int *)((char *)int_ptr + 1);
  }

  for (i = 0; i < 5; i++)
  {
    printf("[char pointer] points to %p which cointains the char '%d'\n", char_ptr, *char_ptr);
    char_ptr = (char *)((int *)char_ptr + 1);
  }

  return 0;
}
