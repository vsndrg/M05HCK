#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

#include "hacking.h"

#define DATAFILE "/var/chance.data"

typedef struct
{
  int uid;
  int credits;
  int highscore;
  char name[100];
  int (*cur_game)();
} user;

int get_player_data( void );
int register_new_player( void );
void update_player_data( void );
void show_highscore( void );
void jackpot( void );
void input_name( void );
void print_cards( char *, char *, int );
int take_wager( int, int );
void play_the_game( void );
int pick_a_number( void );
int dealer_no_match( void );
int find_the_ace( void );

user player;

int main( void )
{
  int choise, last_game;

  srand(time(0));

  if (get_player_data() == -1)
    register_new_player();

  while (choise != 7)
  {
    printf("-=[ Game of Chance Menu ]=-\n");
    printf("1 - Play the Pick a Number game\n");
    printf("2 - Play the No Match Dealer game\n");
    printf("3 - Play the Find the Ace game\n");
    printf("4 - View current high score\n");
    printf("5 - Change your user name\n");
    printf("6 - Reset your account ar 100 credits\n");
    printf("7 - Quit\n");
    printf("[Name: %s]\n", player.name);
    printf("[You have %u credits] -> ", player.credits);
    scanf("%d", &choise);

    if (choise < 1 || choise > 7)
      printf("\n[!!] The number %d is an invalid selection.\n\n", choise);
    else if (choise < 4)
    {
      if (choise != last_game)
      {
	if (choise == 1)
	  player.cur_game = pick_a_number;
	else if (choise == 2)
	  player.cur_game = dealer_no_match;
	else
	  player.cur_game = find_the_ace;
	last_game = choise;
      }
      play_the_game();
    }
    else if (choise == 4)
      show_highscore();
    else if (choise == 5)
    {
      printf("\nChange the user name\n");
      printf("Enter your new name: \n");
      input_name();
    }
    else if (choise == 6)
    {
      printf("\nYour account has been reset with 100 credits.\n\n");
      player.credits = 100;
    }
  }
  update_player_data();
  printf("\nThanks for playing! Bye.\n");
}
