#include "../includes/minishell.h"

extern t_state	g_state;

void	init_term(void)
{
	tcgetattr(STDIN_FILENO, &g_state.term);
	g_state.term.c_lflag &= ~ICANON;
	g_state.term.c_lflag &= ~ECHO;
	g_state.term.c_cc[VMIN] = 1;
	g_state.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_state.term);
	tgetent(NULL, "xterm");
}
