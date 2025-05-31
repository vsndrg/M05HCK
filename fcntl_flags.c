#include <stdio.h>
#include <fcntl.h>

typedef unsigned int uint;

void display_flags( char *, uint );
void binary_print( uint );

int main( void )
{
  display_flags("O_RDONLY\t\t", O_RDONLY);
  display_flags("O_WRONLY\t\t", O_WRONLY);
  display_flags("O_RDWR\t\t\t", O_RDWR);
  printf("\n");
  display_flags("O_APPEND\t\t", O_APPEND);
  display_flags("O_TRUNC\t\t\t", O_TRUNC);
  display_flags("O_CREAT\t\t\t", O_CREAT);
  printf("\n");
  display_flags("O_WRONLY | O_APPEND | O_CREAT", O_WRONLY | O_APPEND | O_CREAT);
}

void display_flags( char *label, uint value )
{
  printf("%s\t: %d\t:", label, value);
  binary_print(value);
  printf("\n");
}

void binary_print( uint value )
{
  uint mask = 0xff000000;
  uint shift = 1 << 24;
  uint byte, byte_it, bit_it;

  for (byte_it = 0; byte_it < 4; byte_it++)
  {
    byte = (value & mask) / shift;
    printf(" ");

    for (bit_it = 0; bit_it < 8; bit_it++)
    {
      if (byte & 0x80)
	printf("1");
      else
	printf("0");

      byte <<= 1;
    }
    mask >>= 8;
    shift >>= 8;
  }
}

