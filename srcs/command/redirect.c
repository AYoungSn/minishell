#include "../../includes/command.h"

void		renewal(t_program *cmd)
{
	int		i;
	int		cnt;
	char	**tmp;

	i = 0;
	cnt = 0;
	while (cmd->args[i])
	{
		if (cmd->args[i][0] == '<' || cmd->args[i][0] == '>')
			cnt++;
		i++;
	}
	if (cnt == 0)
		return ;
	cnt = cmd->argc - cnt;
	tmp = 0;
	tmp = new_args(cmd, tmp, cnt);
	i = 0;
	while (i < cmd->argc)
		free(cmd->args[i++]);
	free(cmd->args);
	cmd->args = tmp;
	cmd->argc = cnt;
}

int			check_redirection(t_dlist *info)
{
	t_program	*cmd;
	int			i;

	i = 0;
	cmd = info->content;
	cmd->fd[0] = 0;
	cmd->fd[1] = 1;
	while (cmd->args[i])
	{
		if (cmd->args[i][0] == '<' && cmd->args[i][1] == 0)
		{
			if (cmd->fd[0] != 0)
				close(cmd->fd[0]);
			cmd->fd[0] = open(cmd->args[i + 1], O_RDONLY);
		}
		else if (cmd->args[i][0] == '>')
		{
			if (cmd->fd[1] != 1)
				close(cmd->fd[1]);
			if (cmd->args[i][1] == 0)
				cmd->fd[1] = open(cmd->args[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
			else if (cmd->args[i][1] == '>')
				cmd->fd[1] = open(cmd->args[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		}
		if (cmd->fd[0] == -1 || cmd->fd[1] == -1)
		{
			execute_error(cmd->args[i + 1], 2);
			return (0);
		}
		i++;
	}
	renewal(cmd);
	return (1);
}

char		**new_args(t_program *cmd, char **tmp, int cnt)
{
	int		i;
	int		j;

	if (!(tmp = malloc(sizeof(char*) * (cnt + 1))))
		return (0);
	i = 0;
	j = 0;
	while (j < cnt)
	{
		if (cmd->args[i][0] != '<' && cmd->args[i][0] != '>')
			tmp[j++] = ft_strdup(cmd->args[i]);
		i++;
	}
	tmp[j] = 0;
	return (tmp);
}