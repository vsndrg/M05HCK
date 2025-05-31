#include <stdio.h>
#include <time.h>

int main( void )
{
  long int seconds_since_epoch;
  struct tm current_time, *time_ptr;
  int hour, minute, second, day, month, year, prev_seconds_since_epoch;

  while (1)
  {
    seconds_since_epoch = time(0);

    if (prev_seconds_since_epoch != seconds_since_epoch)
    {
      printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);

      time_ptr = &current_time;

      localtime_r(&seconds_since_epoch, time_ptr);

      hour = current_time.tm_hour;
      minute = time_ptr->tm_min;
      second = *((int *)time_ptr);

      printf("Current time is: %02d:%02d:%02d", hour, minute, second);
      printf("\033[1A\r"); 
      fflush(stdout);
    }

    prev_seconds_since_epoch = seconds_since_epoch;
  }
}

