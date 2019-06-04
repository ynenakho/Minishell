/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:07:27 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 22:39:40 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_arr_env(t_env *list)
{
	int		i;
	int		length;
	char	**new;

	length = ft_list_size_env(list);
	new = (char **)malloc(sizeof(char *) * (length + 1));
	i = 0;
	while (i < length)
	{
		new[i] = ft_strjoin(list->key, "=");
		new[i] = ft_update(new[i], ft_strjoin(new[i], list->value));
		list = list->next;
		i++;
	}
	new[i] = NULL;
	return (new);
}

int		ft_list_size_env(t_env *root)
{
	int		i;
	t_env	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}

char	*ft_update(char *str, char *update)
{
	char *tmp;

	tmp = update;
	if (str != NULL)
		free(str);
	str = update;
	return (str);
}

void	action_setenv(char *key, char *value)
{
	if (ft_strcmp("EMPTY", search_by_key(key)) == 0)
		add_to_env(key, value);
	else
		replace_value(key, value);
}
