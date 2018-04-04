/* 
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

/* Macros AF_* for address families. */
#ifdef HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#  include <sys/socket.h>
#endif
#ifdef HAVE_NETINET_IN_H
#  include <netinet/in.h>
#endif


#include "game.h"
#include "misc.h"
#include "terminal.h"


int who_start_first (void)
{
	long generated_number;

	generated_number = 1 + (random() % 10);

	if ( (generated_number == 2) || (generated_number == 4)
			|| (generated_number == 6) || (generated_number == 8)
			|| (generated_number == 10) )
	{
		return 1;
	}

	return 2;
} /* who_start_first(void) */


void get_player_pname (char * str, size_t maxlen)
{
	char buffer[1024], *pek;
	size_t n = 0;

	str[0] ='\0';
	if ( maxlen <= 1 )
		return;

	if ( !fgets(buffer, sizeof(buffer), stdin) )
	  buffer[0] = '\0';

	pek = buffer;

	/* Skip initial white space. */
	while ( *pek == ' ' || *pek == '\t' || *pek == '\r' )
		++pek;

	while ( *pek && (n + 1 < maxlen) && (n + 1 < sizeof(buffer)) )
	{
		if ( *pek == '\n' )
			break;

		/* Promote LF and TAB to simple space. */
		if ( *pek == '\r' || *pek == '\t' )
			*pek = ' ';

		/* Avoid duplicate white space. */
		if ( (n > 0) && (str[n - 1] == ' ') && (*pek == ' ') )
		{
			++pek;
			continue;
		}

		str[n++] = *(pek++);
	}

	/* Skip trailing white space. */
	while ( (n > 0) && (str[n - 1] == ' ') )
		--n;

	/* Safe guard for empty name. */
	if ( n == 0 )
		strcpy (str, "Anon");
	else
		str[n] = '\0';
} /* get_player_pname(char *, size_t) */


int check_pname (const char *pname, size_t maxlen)
{
	if ( pname == NULL )
		return 1;

	if ( (strlen(pname)) > maxlen )
		return 1;

	return 0;
} /* check_pname(const char *, size_t) */


void print_infos_screen (void)
{
	nettoe_term_reset_color ();
	puts ("");
	printf (" Pokemon Duel is a fighting game for Linux and UNIX.      \n");
	printf (" It is possible to play against another player over       \n");
	printf (" a network (Internet, and everything using TCP/IP).       \n");
	printf (" To play it over a network you must first set up a server.\n");
	printf (" This is done in the network game options menu, selecting \n");
	printf (" \"Host the game\". Then the (remote) second player must  \n");
	printf (" connect to the server by typing its IP address.          \n\n");

	printf (" This game was created using Nettoe source code,          \n");
	nettoe_term_set_color (COLOR_GREEN, ATTRIB_BRIGHT);
	printf (" http://nettoe.sourceforge.net/                           \n\n");
	nettoe_term_reset_color ();
	printf (" Hope you enjoy playing Pokemon Duel! - Shelby Kelley     \n\n");

	nettoe_term_set_color (COLOR_MAGENTA, ATTRIB_BRIGHT);
	printf (" enter");
	nettoe_term_reset_color ();
	printf (" to go back to the main menu. ");

	fflush (stdin);
	getchar ();

	nettoe_term_set_default_color ();
} /* print_infos_screen(void) */

void parse_cmd_args (int argc, char *argv[])
{
	int i;

	/* Any address family will do. */
	addrfamily = AF_UNSPEC;

	if ( argc < 2 )
		return;

	for ( i = 1; i <= argc - 1; i++ )
	{
		if ( (!strcmp(argv[i], "-h")) || (!strcmp(argv[i], "--help")) )
		{ 
			fprintf (stdout, "\n");
			fprintf (stdout, "Usage:  nettoe [OPTIONS]\n");
			fprintf (stdout, "\n");
			fprintf (stdout, "-4,  --ipv4        only IPv4 networking\n");
			fprintf (stdout, "-6,  --ipv6        only IPv6 networking\n");
			fprintf (stdout, "-nb, --no-beep     disable beeps\n");
			fprintf (stdout, "-nc, --no-colors   disable colors\n");
			fprintf (stdout, "-h,  --help        display this help,"
						    " then exit\n");
			fprintf (stdout, "-v,  --version     output version information,"
							" then exit\n");
			fprintf (stdout, "\n");

			exit (EXIT_SUCCESS);
		}
		else if ( (!strcmp(argv[i], "-v"))
				|| (!strcmp(argv[i], "--version")) )
		{
#if USE_TERMINFO
			fprintf (stdout, " with terminfo support");
#elif USE_TERMCAP
			fprintf (stdout, " with termcap support");
#endif
			fprintf (stdout, ", at TCP port %d.", SERVER_PORT_NUMBER);
			fprintf (stdout, "\n\n");
			fprintf (stdout, "Copyright 2000,2001 Gabriele Giorgetti\n");
			fprintf (stdout, "          2009-2014 Mats Erik Andersson\n");
			fprintf (stdout, "\n");
			fprintf (stdout, "This software is released under GNU GPL 2.\n");

			exit (EXIT_SUCCESS);
		}
		else if ( (!strcmp(argv[i], "-4"))
				|| (!strcmp(argv[i], "--ipv4")) )
		{
			addrfamily = AF_INET;
			continue;
		}
		else if ( (!strcmp(argv[i], "-6"))
				|| (!strcmp(argv[i], "--ipv6")) )
		{
			addrfamily = AF_INET6;
			continue;
		}
		else if ( (!strcmp(argv[i], "-nb"))
				|| (!strcmp(argv[i], "--no-beep")) )
		{
			NO_BEEP = 1;
			continue;
		}
		else if ( (!strcmp(argv[i], "-nc"))
				|| (!strcmp(argv[i], "--no-colors")) )
		{
			NO_COLORS = 1;
			continue;
		} else {
			fprintf(stdout, "%s: unrecognized option `%s'\n",
					argv[0], argv[i]);
			fprintf(stdout, "Try `%s --help' for more information.\n",
					argv[0]);

			exit (EXIT_SUCCESS);
		}
	}

	return;
} /* parse_cmd_args(int, char *[]) */

/*
 * vim: sw=4 ts=4
 */
