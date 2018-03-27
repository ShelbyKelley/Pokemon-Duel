/*
*/


#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <string.h>
#ifdef HAVE_STRING_H
# include <string.h>
#endif
#ifdef HAVE_STRINGS_H
# include <strings.h>		/* strncasecmp */
#endif

#define NO_EXTERNALS
#include "board.h"

#import <stdio.h>
#import <unistd.h>
#import <stdlib.h>
#import <string.h>
#import <time.h>

#include "terminal.h"

#define ARR_SIZE 151
#define BUFFER_SIZE 256

/* Choose a random number for Pokemon1 & Pokemon2 */
int randInt()
{  
  int num = ( (rand() % 151) + 1 );
  return num;
}


int pokemon_server (char *filename, int num)
{
    FILE *fp;
    char *buffer;
    char *token;
    int count = 0;

    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf ("file cannot be opened");
    return 1;
    }

    buffer = malloc(BUFFER_SIZE);
    if(buffer == NULL)
    {
        printf("Error: Out of Memory");
        return 1;
    }

    fgets(buffer, BUFFER_SIZE, fp);
    while( (fgets(buffer, BUFFER_SIZE, fp)) != NULL )
    {
      count += 1;

      if(count == num)
      {
        /* Pokemon1 Number */
        token = strtok(buffer, ",");
        pokemon1.number = atoi(token);
        
        /* Pokemon1 Name */
        token = strtok(NULL, ",");
        strcpy(pokemon1.name, token);

        /* Pokemon1 HP */
        token = strtok(NULL, ", ");
        pokemon1.hp = atoi(token);

        /* Pokemon1 Attack */
        token = strtok(NULL, ", ");
        pokemon1.attack = atoi(token);

        /* Pokemon1 Defense */
        token = strtok(NULL, ", ");
        pokemon1.defense = atoi(token);

        /* Pokemon1 Speed */
        token = strtok(NULL, ", ");
        pokemon1.speed = atoi(token);
      }
    }

    free(buffer);
    fclose(fp);

    return 0;
}


int pokemon_client(char *filename, int num)
{
    FILE *fp;
    char *buffer;
    char *token;
    int count = 0;

    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf ("file cannot be opened");
    return 1;
    }

    buffer = malloc(BUFFER_SIZE);
    if(buffer == NULL)
    {
        printf("Error: Out of Memory");
        return 1;
    }

    fgets(buffer, BUFFER_SIZE, fp);
    while( (fgets(buffer, BUFFER_SIZE, fp)) != NULL )
    {
      count += 1;

      if(count == num)
      {
        /* Pokemon1 Number */
        token = strtok(buffer, ",");
        pokemon2.number = atoi(token);
        
        /* Pokemon1 Name */
        token = strtok(NULL, ",");
        strcpy(pokemon2.name, token);

        /* Pokemon1 HP */
        token = strtok(NULL, ", ");
        pokemon2.hp = atoi(token);

        /* Pokemon1 Attack */
        token = strtok(NULL, ", ");
        pokemon2.attack = atoi(token);

        /* Pokemon1 Defense */
        token = strtok(NULL, ", ");
        pokemon2.defense = atoi(token);

        /* Pokemon1 Speed */
        token = strtok(NULL, ", ");
        pokemon2.speed = atoi(token);
      }
    }

    free(buffer);
    fclose(fp);

    return 0;
}


void init_pokemon_server (void)
{
  char *filename = "pokemon.csv";

  srand(time(NULL));   /* should only be called once */

  int ran_serv = randInt();

  pokemon_server(filename, ran_serv);
}


void init_pokemon_client (void)
{
  char *filename = "pokemon.csv";

  int ran_client = randInt();

  pokemon_client(filename, ran_client);
}


int game_check (void)
{
  /*
  int n;

  for (n = 0; n < 8; n++)
    {
      struct endpoints line = winning_line[n];

      if ( *board[line.first] == *board[line.last]
	  && *board[line.first] == *board[(line.first + line.last) / 2] )
	{
	  // Disregard empty lines. 
	  if (*board[line.first] != 'X' && *board[line.first] != 'O')
	    continue;

	  // Identical pawns in a winning line! 
	  return ((*board[line.first] == 'X') ? GAME_IS_X_WIN
					      : GAME_IS_O_WIN);
	}
    }

  // Is the board exhausted? 
  if ( (c11 != ' ') && (c12 != ' ') && (c13 != ' ')
      && (c21 != ' ') && (c22 != ' ') && (c23 != ' ')
      && (c31 != ' ') && (c32 != ' ') & (c33 != ' ') )
    {
      return GAME_IS_DRAW;
    }
  */
  return GAME_IS_ALIVE;
}

struct good_move {
  /*
  char * string;
  char * position;
} good_moves[] = {
  { "a1", &c11 },
  { "a2", &c12 },
  { "a3", &c13 },
  { "b1", &c21 },
  { "b2", &c22 },
  { "b3", &c23 },
  { "c1", &c31 },
  { "c2", &c32 },
  { "c3", &c33 },
#ifndef HAVE_STRNCASECMP
  { "A1", &c11 },
  { "A2", &c12 },
  { "A3", &c13 },
  { "B1", &c21 },
  { "B2", &c22 },
  { "B3", &c23 },
  { "C1", &c31 },
  { "C2", &c32 },
  { "C3", &c33 },
#endif // !HAVE_STRNCASECMP
  { NULL, NULL },
*/
};

int attempt_move (const char *move, char pawn)
{
  /*
  struct good_move *p;

  for (p = good_moves; p->string && p->position; p++)
    {
#ifdef HAVE_STRNCASECMP
      if (!strncasecmp (move, p->string, strlen (p->string)))
#else // !HAVE_STRNCASECMP
      if (!strncmp (move, p->string, strlen (p->string)))
#endif
	{
	  if (*p->position == ' ')
	    {
	      *p->position = pawn;
	      return VALID_MOVE;
	    }
	}
    }
  */
  return INVALID_MOVE;
}
