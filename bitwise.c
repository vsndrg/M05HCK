#include <stdio.h>

int main( void )
{
  int i, bit_a, bit_b;

  printf("\nbiwise OR operator |\n");

  for (i = 0; i < 4; i++)
  {
    bit_a = (i & 2) / 2;
    bit_b = (i & 1);
    printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
  }

  printf("\nbiwise AND operator &\n");
  
  for (i = 0; i < 4; i++)
  {
    bit_a = (i & 2) / 2;
    bit_b = (i & 1);
    printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
  }
}
