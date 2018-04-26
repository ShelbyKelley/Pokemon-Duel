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
      token = strtok(NULL, ",");
      pokemon1.hp = atoi(token);

      /* Pokemon1 Attack */
      token = strtok(NULL, ",");
      pokemon1.attack = atoi(token);

      /* Pokemon1 Defense */
      token = strtok(NULL, ",");
      pokemon1.defense = atoi(token);
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
      token = strtok(NULL, ",");
      pokemon2.hp = atoi(token);

      /* Pokemon1 Attack */
      token = strtok(NULL, ",");
      pokemon2.attack = atoi(token);

      /* Pokemon1 Defense */
      token = strtok(NULL, ",");
      pokemon2.defense = atoi(token);
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


void game_attack (int player)
{
  int attack_roll = randInt();

  if ( player == 1 )
  {
    if (attack_roll > pokemon2.defense)
      pokemon2.hp -= ( pokemon1.attack / 5 );

    printf("\n   This is pokemon1 attacking pokemon2\n");
    sleep ( 5 );
  }
  
  if ( player == 2 )
  {
    if (attack_roll > pokemon1.defense)
      pokemon1.hp -= ( pokemon2.attack / 5 );

    printf("\n   This is pokemon2 attacking pokemon1\n");
    sleep ( 5 );
  }
}


int game_check (void)
{
  if( pokemon1.hp <= 0 && pokemon2.hp > 0 )
    return GAME_IS_CLT_WIN;

  if( pokemon1.hp <= 0 && pokemon2.hp <= 0 )
    return GAME_IS_DRAW;

  if( pokemon1.hp > 0 && pokemon2.hp <= 0 )
    return GAME_IS_SVR_WIN;

  return GAME_IS_ALIVE;
}

