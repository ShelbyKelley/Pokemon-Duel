/* 
*/


#ifndef SERVER_PORT_NUMBER
# ifdef NETTOE_PORT
#  define SERVER_PORT_NUMBER NETTOE_PORT
# else
#  define SERVER_PORT_NUMBER 7501
# endif
#endif

#define MAXDATASIZE 50
#define MAX_PNAME_LEN 32 /* this define max chars for the player names*/

int NO_BEEP;

int NO_COLORS;

int addrfamily;
