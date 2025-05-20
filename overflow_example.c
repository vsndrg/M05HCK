#include <stdio.h>
#include <string.h>
#include <math.h>

int main( int argc, char *argv[] )
{
  int value = 5;
  char buffer2[8], buffer1[8];

  strcpy(buffer1, "one");
  strcpy(buffer2, "two");

  printf("[BEFORE] buffer2 is at %p and contains \'%s\'\n", buffer2, buffer2);
  printf("[BEFORE] buffer1 is at %p and contains \'%s\'\n", buffer1, buffer1);
  printf("[BEFORE] value is at %p and is %d (0x%08x)\n", &value, value, value);

  if (argc > 1)
    printf("\n[STRCPY] copying %d bytes into buffer_two\n\n", strlen(argv[1]));
  else
  {
    printf("Add more argumens in command line\n");
    return 0;
  }
  strcpy(buffer2, argv[1]);

  printf("[AFTER] buffer2 is at %p and contains \'%s\'\n", buffer2, buffer2);
  printf("[AFTER] buffer1 is at %p and contains \'%s\'\n", buffer1, buffer1);
  printf("[AFTER] value is at %p and is %d (0x%08x)\n", &value, value, value);

  return 0;
}
