/* 
 *  Independent Study Project 
 *
 *	Shelby Kelley
 */

#import <stdio.h>
#import <unistd.h>
#import <stdlib.h>
#import <string.h>

#define ARR_SIZE 256
#define BUFFER_SIZE 256

#include "pokemon.h"

extern char buffer[132];   /* general purpose scratch area */

pokemon pokemon1;    /* Pokemon for Player 1 -- can change throughtout the game */
pokemon pokemon2;    /* Pokemon for Player 2 -- constantly updated by the game */

