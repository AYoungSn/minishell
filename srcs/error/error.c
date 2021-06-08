#include "../../includes/error.h"

/*
** syntax error print
** return 0:failed 127:succeed(exit)
*/
int		print_syntax_error(int errno)
{
	if (errno == ERR_QUOTE)
		ft_putstr_fd("bash: syntax error quote not closed\n", STD_ERR);
	if (errno == ERR_SEMICOLONE)
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", STD_ERR);
	if (errno == ERR_SEMICOLONE2)
		ft_putstr_fd("bash: syntax error near unexpected token `;;'\n", STD_ERR);
	if (errno == ERR_PIPE)
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", STD_ERR);
	if (errno == ERR_PIPE2)
		ft_putstr_fd("bash: syntax error near unexpected token `||'\n", STD_ERR);
	else
		return (0);
	return (EXIT_CODE);
}

int		print_memory_error(int errno)
{
	if (errno == ERR_MALLOC)
		ft_putstr_fd("bash: failed to allocate memory.\n", STD_ERR);
	else
		return (0);
	return (EXIT_CODE);
}

int		print_exit_error(char *str, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("bash: exit: ", STD_ERR);
		ft_putstr_fd(str, STD_ERR);
		ft_putstr_fd(": numeric argument required\n", STD_ERR);
	}
	else
		ft_putstr_fd(str, STD_ERR);
	return (1);
}