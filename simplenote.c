#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <x86_64-linux-gnu/sys/stat.h>

void usage( char *prog_name, char *filename )
{
  printf("Usage: %s <data to add to %s>\n", prog_name, filename);
  exit(0);
}

void fatal( char *message );

void * ec_malloc( unsigned int size );

int main( int argc, char *argv[] )
{
  int fd, i;
  char *buffer, *filename;

  buffer = (char *)ec_malloc(100);
  filename = (char *)ec_malloc(20);
  strcpy(filename, "/tmp/notes");

  if (argc < 2)
    usage(argv[0], filename);

  strcpy(buffer, argv[1]);
    
  printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
  printf("[DEBUG] filename @ %p: \'%s\'\n", filename, filename);

  strcat(buffer, "\n");

  fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
  if (fd == -1)
    fatal("in main() while opening file");
  printf("[DEBUG] file descriptor is %d\n", fd);

  if (write(fd, buffer, strlen(buffer)) == -1)
    fatal("in main() while writing buffer to file");

  if (close(fd) == -1)
    fatal("int main() while closing file");

  printf("Note has been saved.\n");
  free(buffer);
  free(filename);
}

void fatal( char *message )
{
  char error_message[100];

  strcpy(error_message, "[!!] Fatal Error ");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}

void * ec_malloc( unsigned int size )
{
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    fprintf(stderr, "Error: could not allocate heap memory.\n");
    exit(-1);
  }
  return ptr;
}

