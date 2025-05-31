#include <stdio.h>
#include <time.h>

typedef unsigned char byte;

void dump_time_struct_bytes( struct tm *time_ptr, int size )
{
  int i;
  byte *raw_ptr;

  printf("bytes of struct located at %p\n", time_ptr);
  
  raw_ptr = (byte *)time_ptr;

  for (i = 0; i < size; i++)
  {
    printf("%02x ", raw_ptr[i]);
    if (i % 4 == 3)
      printf("\n");
  }
  printf("\n");
}

int main( void )
{
  long int seconds_since_epoch, prev_seconds_since_epoch;
  struct tm current_time, *time_ptr;
  int hour, minute, second, day, month, year, i, *int_ptr;

  while (1)
  {
    seconds_since_epoch = time(0);

    if (prev_seconds_since_epoch != seconds_since_epoch)
    {      
      time_ptr = &current_time;

      localtime_r(&seconds_since_epoch, time_ptr);

      dump_time_struct_bytes(&current_time, sizeof(struct tm));
      
      hour = current_time.tm_hour;
      minute = time_ptr->tm_min;
      second = *((int *)time_ptr);

      printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);
      printf("Current time is: %02d:%02d:%02d", hour, minute, second);

      minute = hour = 0;
      int_ptr = (int *)time_ptr;
      
      for (i = 0; i < 3; i++)
      {
	printf("\nint_ptr @ %p : %d", int_ptr, *int_ptr);
	int_ptr++;
      }
      
      printf("\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\033[1A\r");

      fflush(stdout);
    }

    prev_seconds_since_epoch = seconds_since_epoch;
  }
  fflush(stdout);

  return 0;
}
