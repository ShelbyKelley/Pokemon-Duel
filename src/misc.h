/* 
*/


#ifndef _MISC_H
# define _MISC_H 1

void parse_cmd_args (int argc, char *argv[]);

void get_player_pname (char * str, size_t maxlen);
int check_pname (const char *pname, size_t maxlen);

int who_start_first (void);
void print_infos_screen (void);

#endif /* !_MISC_H */
