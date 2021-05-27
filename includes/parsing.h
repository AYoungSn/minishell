#ifndef PARSING_H
# define PARSING_H

# define CMD_ECHO 1
# define CMD_CD 2;
# define CMD_PWD 3;
# define CMD_EXPORT 4;
# define CMD_UNSET 5;
# define CMD_ENV 6;
# define CMD_EXIT 7;

#include "../libft/libft.h"

typedef struct			s_command
{
	int					command;
	int					flag;
	char				*option;
	char				**args;
}						t_command;

typedef struct			s_history
{
	struct s_history	*next;
	char				*content;
}						t_history;

typedef struct			s_parse
{
	struct s_parse		*next;
	t_command			cmd;
}						t_parse;


/*
**
*/

int						parse(char *line, t_command *info);

#endif