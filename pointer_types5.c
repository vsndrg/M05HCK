#include <stdio.h>

typedef unsigned long int uint;

int main( void )
{
  int i;
  
  char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
  int int_arr[5] = {1, 2, 3, 4, 5};

  uint hacky_noptr = (uint)char_arr;

  for (i = 0; i < 5; i++)
  {
    printf("[hacky_noptr] points to %p which cointains the char '%c'\n", hacky_noptr, *((char *)hacky_noptr));
    hacky_noptr = hacky_noptr + sizeof(char);
  }

  hacky_noptr = (uint)int_arr;
  
  for (i = 0; i < 5; i++)
  {
    printf("[hacky_noptr] points to %p which cointains the integer %d\n", hacky_noptr, *((int *)hacky_noptr));
    hacky_noptr = hacky_noptr + sizeof(int);
  }

  return 0;
}
