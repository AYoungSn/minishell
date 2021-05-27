#include "../includes/minishell.h"

int		prompt()
{
	write(1, "minishell$ ", 11);
	return (1);
}

int		minishell(t_parse *cmd_lst, t_history *history)
{
	char	*line;
	char	*processed_line;
	int		nread;

	(void)cmd_lst;
	(void)history;

	while (1)
	{
		// prompt
		prompt();
		// gnl
		processed_line = ft_strnew(0);
		while ((nread = get_next_line(0, &line)) > 0)
		{
			process_quote(line, &processed_line);
			if (line[ft_strlen(line) - 1] == '\\')
				line[ft_strlen(*line) - 1] = 0;
			else
				break;
		}
		printf(">> %s\n", processed_line);
		// if (nread < 0)
			// error
		// 넘어가도 되는 경우
		// history save
		// save_history(processed_line, history);
		// parsing
		// parse(processed_line, cmd_lst);
		// excute
		free(processed_line);
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	t_parse cmd_lst;
	t_history history;

	(void)argc;
	(void)argv;
	(void)envp;

	// signal
	// minishell
	minishell(&cmd_lst, &history);
	return (0);
}