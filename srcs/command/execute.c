#include "../../includes/command.h"

extern t_state	g_state;

static int	arg_cnt(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

/*
** executable -> excute
*/

void		execute(t_dlist *cmd, char *envp[])
{
	t_dlist		*tmp;
	t_program	*com;
	int			in;
	int			out;

	tmp = cmd;
	if (!cmd)
		return ;
	else
	{
		com = ((t_program *)(cmd->content));
		while (tmp &&
		!(tmp->prev && ((t_program*)tmp->content)->flag > 0))
		{
			printf("> com->command: %s\n", com->command);
			pipe(com->pip);
			printf("> %d\n", com->flag);
			com->argc = arg_cnt(com->args);
			in = dup(0);
			out = dup(1);
			execute_cmd(tmp, envp);
			close_fd(tmp, in, out);
			tmp = tmp->next;
			if (tmp)
				com = tmp->content;
		}
	}
	printf("execute_cmd success\n");
}

void		execute_cmd(t_dlist *info, char *envp[])
{
	t_program	*cmd;

	cmd = info->content;
	printf("execute_cmd\n");
	if (cmd->command == 0)
		return ;
	else if (builtin(info))
		return ;
	else if (find_command(cmd))
		path_execute(info, envp);
	else
		execute_error(cmd->command, 2);
}

static char	**make_argv(char **argv, char *arg)
{
	char	**result;
	int		len;
	int		i;

	len = 0;
	while (argv[len])
		len++;
	if (!(result = malloc(sizeof(char*) * (len + 2))))
		return (0);
	i = 1;
	result[0] = arg;
	printf("%s\n", result[0]);
	while (i < len + 1)
	{
		result[i] = argv[i - 1];
		i++;
		printf("i:%d, %s\n", i, result[i]);
	}
	result[i] = 0;
	printf("%s\n", result[i]);
	return (result);
}

void		path_execute(t_dlist *info, char *envp[])
{
	t_program	*pro;
	pid_t		pid;
	int			status;
	char		**argv;

	pro = info->content;
	argv = 0;
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		set_pipe(info);
		argv = make_argv(pro->args, pro->command);
		if (execve(argv[0], argv, envp) < 0)
		{
			free(argv);
			execute_error(pro->command, 1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		g_state.ret = status;
	}
}
