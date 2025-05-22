#include <stdio.h>

int main( void )
{
  int i;
  
  char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
  int int_arr[5] = {1, 2, 3, 4, 5};

  void *void_ptr = (void *)char_arr;

  for (i = 0; i < 5; i++)
  {
    printf("[char pointer] points to %p which cointains the char '%c'\n", void_ptr, *((char *)void_ptr));
    void_ptr = (void *)((char *)void_ptr + 1);
  }

  void_ptr = (void *)int_arr;
  
  for (i = 0; i < 5; i++)
  {
    printf("[integer pointer] points to %p which cointains the integer %d\n", void_ptr, *((int *)void_ptr));
    void_ptr = (void *)((int *)void_ptr + 1);
  }

  return 0;
}
