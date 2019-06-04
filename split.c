/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:09:14 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 23:06:03 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*split_helper1(char **str, t_node *list)
{
	char	**args;
	int		i;
	int		j;
	int		k;
	char	*space_divided;

	i = 0;
	k = 0;
	j = ft_quote_checker(*str);
	space_divided = ft_strnew(j);
	space_divided = ft_strncpy(space_divided, *str, j);
	while (space_divided[k])
	{
		if (ft_isspace(space_divided[k]))
			space_divided[k] = ' ';
		k++;
	}
	args = ft_strsplit(space_divided, ' ');
	while (args[i])
		list = add_to_list(list, "space", args[i++]);
	ft_strdel(&space_divided);
	delete_double_pointer(args);
	*str = *str + j;
	return (list);
}

void	split_error(void)
{
	ft_printf("Input error\n");
	exit(1);
}

t_node	*split_helper2(char **str, t_node *list, int j)
{
	char *quote_divided;

	quote_divided = ft_strnew(j - 1);
	quote_divided = ft_strncpy(quote_divided, *str + 1, j - 1);
	list = add_to_list(list, "special", quote_divided);
	ft_strdel(&quote_divided);
	*str = *str + j + 1;
	return (list);
}

char	**msh_split(char *str)
{
	t_node	*list;
	int		j;
	char	**new;

	list = NULL;
	while (*str)
	{
		if (*str && *str != '\"' && *str != '\'')
			list = split_helper1(&str, list);
		if (*str == '\"' || *str == '\'')
		{
			j = 1;
			while (str[j] && (str[j] != *str))
				j++;
			if (!str[j])
				split_error();
			if (*str == str[j])
				list = split_helper2(&str, list, j);
		}
	}
	new = list_to_arr(list);
	lstdel(&list);
	return (new);
}
