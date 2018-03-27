/*
 */


#ifndef _BOARD_H
# define _BOARD_H

#define GAME_IS_ALIVE	0
#define GAME_IS_X_WIN	1
#define GAME_IS_O_WIN	2
#define GAME_IS_DRAW	3

#define INVALID_MOVE	0
#define VALID_MOVE	    1  

#define NAMESIZE 132

struct endpoints {
  int first, last;
};

struct pokemon {
  int number;
  char name[NAMESIZE];
  int hp;
  int attack;
  int defense;
  int speed;
};

struct pokemon pokemon1;  /* Pokemon for Player 1 -- can change throughtout the game */
struct pokemon pokemon2;  /* Pokemon for Player 2 -- constantly updated by the game */

int randInt();
int pokemon_server(char *filename, int num);
int pokemon_client(char *filename, int num);
void init_pokemon_server (void);
void init_pokemon_client (void);
int game_check (void);
int attempt_move (const char *, char);
#endif /* _BOARD_H */
