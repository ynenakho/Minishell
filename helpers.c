/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 22:24:17 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 23:06:09 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_double_pointer(char **obj)
{
	char **tmp;

	tmp = obj;
	while (*obj)
		ft_strdel(&(*obj++));
	ft_memdel((void**)&tmp);
}

int		ft_quote_checker(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			return (i);
		i++;
	}
	return (i);
}

void	lstdel(t_node **list)
{
	t_node	*temp;

	if ((*list))
	{
		temp = (*list)->next;
		(*list)->next = NULL;
		ft_strdel(&(*list)->data);
		ft_strdel(&(*list)->type);
		ft_memdel((void**)&(*list));
		lstdel(&(temp));
	}
}
