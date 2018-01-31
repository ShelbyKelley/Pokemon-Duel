/* 
 *  Independent Study Project 
 *
 *	Dueling Pokemon
 *	v1. Parse the .csv and randomly select
 *		two pokemon.
 *
 *	Shelby Kelley
 */

#import <stdio.h>
#import <unistd.h>
#import <stdlib.h>
#import <string.h>

#define ARR_SIZE 4096
#define BUFFER_SIZE 256

struct Pokemon
{
	int number;
	char *name;
	char *type1; 
	char *type2;
	int total;
	int hp;
	int attack;
	int defense;
	int spAttack;
	int spDefense;
	int speed;
};

int count = 0;
struct Pokemon pokedex[ARR_SIZE];

/* Prototypes */
int poke_parse(char *filename);


int main(int ac, char *av[]) 
{
	int i = 0;
	char *filename = "pokemon.csv";

	if( (poke_parse(filename)) == 1 )
		return 1;

	// for(i = 0; i <= count; i++)
	// {
	// 	printf ("Number: %d\n", pokedex[i].number);
 //    	printf ("Name: %s\n", pokedex[i].name);
 //    	printf ("Total: %d\n", pokedex[i].total);
 //    	printf ("HP: %d\n", pokedex[i].hp);
	//     printf ("Attack: %d\n", pokedex[i].attack);
	//     printf ("Defense: %d\n", pokedex[i].defense);
	//     printf ("Special Attack: %d\n", pokedex[i].spAttack);
	//     printf ("Special Defense: %d\n", pokedex[i].spDefense);
	//     printf ("Speed: %d\n", pokedex[i].speed);
	//     printf ("\n");
	// }

    return 0;
}


int poke_parse(char *filename) 
{
	FILE *fp;
	char *buffer;
    char *token;

    struct Pokemon p;

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
    for(count = 0; count < ARR_SIZE; count++)
    {
	    while( (fgets(buffer, BUFFER_SIZE, fp)) != NULL )
	    {
	    	/* Pokemon Number */
	    	token = strtok(buffer, ",");
	    	p.number = atoi(token);
	    	
	    	/* Pokemon Name */
	    	token = strtok(NULL, ",");
	    	p.name = token;

	    	/* Pokemon Type 1 */
	    	token = strtok(NULL, ",");
	    	p.type1 = token;

	    	/* Pokemon Type 2 */
	    	token = strtok(NULL, ",");
	    	p.type2 = token;

	    	/* Pokemon Total */
	    	token = strtok(NULL, ",");
	    	p.total = atoi(token);

	    	/* Pokemon HP */
	    	token = strtok(NULL, ", ");
	    	p.hp = atoi(token);

	    	/* Pokemon Attack */
	    	token = strtok(NULL, ", ");
	    	p.attack = atoi(token);

	    	/* Pokemon Defense */
	    	 token = strtok(NULL, ", ");
	    	 p.defense = atoi(token);

	    	/* Pokemon Special Attack */
	    	 token = strtok(NULL, ", ");
	    	 p.spAttack = atoi(token);

	    	/* Pokemon Special Defense */
	    	 token = strtok(NULL, ", ");
	    	 p.spDefense = atoi(token);

	    	/* Pokemon Speed */
	    	 token = strtok(NULL, ", ");
	    	 p.speed = atoi(token);


	    	pokedex[count] = p;

	    	// printf("\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d \n", pokedex[count].number, pokedex[count].name, pokedex[count].type1, pokedex[count].type2,
	    	//  pokedex[count].total, pokedex[count].hp, pokedex[count].attack, pokedex[count].defense, pokedex[count].spAttack, pokedex[count].spDefense, pokedex[count].speed);
	    }
	}


    free(buffer);
    fclose(fp);

    return 0;
}