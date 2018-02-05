/* 
 *  Independent Study Project 
 *
 *	Shelby Kelley
 */

#import <stdio.h>
#import <unistd.h>
#import <stdlib.h>
#import <string.h>
#import <time.h>

#define ARR_SIZE 151
#define NAMESIZE 132
#define BUFFER_SIZE 256

struct pokemon
{
	int number;
	char name[NAMESIZE];
	int hp;
	int attack;
	int defense;
	int speed;
};

struct pokemon pokemon1;  /* Pokemon for Player 1 -- can change throughtout the game */
struct pokemon pokemon2;  /* Pokemon for Player 2 -- constantly updated by the game */


/* Choose a random number for Pokemon1 & Pokemon2 */
int randInt()
{
	int num = ( (rand() % 151) + 1 );
	return num;
}


/* Summary of the status of the Pokemon */
void pokemonSummary(struct pokemon p)
{
  	printf("Number: %d\nName: %s\nHP: %d\nAttack: %d\nDefense: %d\nSpeed: %d\n\n",  
  			p.number, p.name, p.hp, p.attack, p.defense, p.speed);
}


/* Parse in the pokemon.csv */
int pokemonFinder(char *filename, int rand1, int rand2) 
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

    	if(count == rand1)
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
    	else if(count == rand2)
    	{
    		/* Pokemon2 Number */
	    	token = strtok(buffer, ",");
	    	pokemon2.number = atoi(token);
	    	
	    	/* Pokemon2 Name */
	    	token = strtok(NULL, ",");
	    	strcpy(pokemon2.name, token);

	    	/* Pokemon2 HP */
	    	token = strtok(NULL, ", ");
	    	pokemon2.hp = atoi(token);

	    	/* Pokemon2 Attack */
	    	token = strtok(NULL, ", ");
	    	pokemon2.attack = atoi(token);

	    	/* Pokemon2 Defense */
	    	token = strtok(NULL, ", ");
	    	pokemon2.defense = atoi(token);

	    	/* Pokemon2 Speed */
	    	token = strtok(NULL, ", ");
	    	pokemon2.speed = atoi(token);
    	}
	}

    free(buffer);
    fclose(fp);

    return 0;
}


int main(int ac, char *av[]) 
{
	char *filename = "pokemon.csv";

	srand(time(NULL));   /* should only be called once */

	int rand1 = randInt();
	int rand2 = randInt();
	printf("Rand1: %d Rand2: %d\n\n", rand1, rand2);

	pokemonFinder(filename, rand1, rand2);

	pokemonSummary(pokemon1);
	pokemonSummary(pokemon2);

    return 0;
}

