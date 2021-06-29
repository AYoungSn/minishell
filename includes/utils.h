#ifndef UTILS_H
# define UTILS_H

# include "data.h"
# include "error.h"
# include "../libft/libft.h"
# include <fcntl.h>

/*
** utils.c
*/

int						custom_putchar(int c);
int						skip_whitespace(const char *str, int *i);
void					free_info(t_dlist **programs);
char					*ft_strjoin_null(char const *s1, char const *s2);
char					*split_and_join(char *str, int i, int j);

/*
** utils2.c
*/

t_history				*ft_historynew(char *save);
void					ft_historyadd_front(t_history **lst, t_history *new);
void					ft_historydelone(t_history *lst, void (*del)(void *));
void					ft_historyclear(t_history **lst, void (*del)(void *));
void					ft_strdel2(char **str);

#endif