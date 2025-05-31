#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "hacking.h"

#define FILENAME "/var/notes"

int print_notes( int, int, char * );
int find_user_note( int, int );

int search_note( char *, char * );


int main( int argc, char *argv[] )
{
  int userid, printing = 1, fd;
  char searchstr[100];

  if (argc > 1)
    strcpy(searchstr, argv[1]);
  else
    searchstr[0] = 0;

  userid = getuid();

  if ((fd = open(FILENAME, O_RDONLY)) == -1)
    fatal("in main() while opening file for reading");

  while (printing)
    printing = print_notes(fd, userid, searchstr);

  printf("--------[ end of note data ]--------\n");
  
  if (close(fd) == -1)
    fatal("in main() while closing file");
}

int print_notes( int fd, int uid, char *searchstr )
{
  int note_length;
  char note_buffer[100];

  note_length = find_user_note(fd, uid);

  if (note_length == -1)
    return 0;

  read(fd, note_buffer, note_length);
  note_buffer[note_length] = 0;

  if (search_note(note_buffer, searchstr))
    printf("%s", note_buffer);

  return 1;
}

int find_user_note( int fd, int user_uid )
{
  int note_uid = -1;
  unsigned char byte;
  int len;

  while (note_uid != user_uid)
  {
    if (read(fd, &note_uid, 4) != 4)
      return -1;

    if (read(fd, &byte, 1) != 1)
      return -1;

    len = byte = 0;

    while (byte != '\n')
    {
      if (read(fd, &byte, 1) != 1)
	return -1;
      len++;
    }
  }
  lseek(fd, len * -1, SEEK_CUR);

  printf("[DEBUG] found a %d byte note for user id %d\n", len, note_uid);
  return len;
}

int search_note( char *note, char *kw )
{
  int i, kw_len, match = 0;

  kw_len = strlen(kw);
  if (kw_len == 0)
    return 1;
 
  for (i = 0; i < strlen(note); i++)
  {
    if (note[i] == kw[match])
      match++;
    else
      if (note[i] == kw[0])
	match = 1;
      else
	match = 0;

    if (match == kw_len)
      return 1;
  }
  return 0;  
}
