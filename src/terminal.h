/* 
*/


#ifndef _TERMINAL_H
# define _TERMINAL_H 1

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#ifndef COLOR_BLACK
enum {
	COLOR_BLACK, COLOR_RED, COLOR_GREEN,
	COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA,
	COLOR_CYAN, COLOR_WHITE, COLOR_DEFAULT = 9
};
#endif /* ECMA-48 colour definitions. */

#ifndef COLOR_DEFAULT
#  define COLOR_DEFAULT 9
#endif

enum {
	ATTRIB_RESET = 0, ATTRIB_BRIGHT, ATTRIB_DIM, ATTRIB_UNDERLINE = 4,
	ATTRIB_BLINK, ATTRIB_REVERSE = 7, ATTRIB_HIDDEN
};

#if defined USE_TERMINFO || defined USE_TERMCAP
void setup_terminfo(void);
#endif

void nettoe_term_clear (void);
void nettoe_term_set_color (int fg, int attrib);
void nettoe_term_set_default_color (void);
void nettoe_term_reset_color (void);

void nettoe_beep(void);

#endif /* !_TERMINAL_H */
