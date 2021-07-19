/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <yoahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:11:26 by ahnys             #+#    #+#             */
/*   Updated: 2021/01/15 23:04:19 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_findchar(char *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i] || s[i] == '\n')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
