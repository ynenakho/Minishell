/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:07:01 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 23:05:45 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*create_first_node(t_node *list, char *type, char *newdata)
{
	list = (t_node *)malloc(sizeof(t_node));
	list->type = ft_strdup(type);
	list->data = ft_strdup(newdata);
	list->next = NULL;
	return (list);
}

t_node	*add_to_list(t_node *list, char *type, char *data)
{
	t_node	*begining;
	t_node	*node;
	char	*newdata;
	char	*tmp_data;

	tmp_data = valid_tilda(type, data);
	newdata = manage_dollar(type, tmp_data);
	ft_strdel(&tmp_data);
	if (!list)
	{
		list = create_first_node(list, type, newdata);
		ft_strdel(&newdata);
		return (list);
	}
	node = (t_node *)malloc(sizeof(t_list));
	begining = list;
	node->next = NULL;
	node->type = ft_strdup(type);
	node->data = ft_strdup(newdata);
	ft_strdel(&newdata);
	while (begining->next)
		begining = begining->next;
	begining->next = node;
	return (list);
}

int		ft_list_size(t_node *root)
{
	int		i;
	t_node	*entity;

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

char	**list_to_arr(t_node *list)
{
	int		i;
	int		length;
	char	**new;
	t_node	*tmp;

	tmp = list;
	length = ft_list_size(list);
	new = (char **)malloc(sizeof(char *) * (length + 1));
	i = 0;
	while (i < length)
	{
		new[i] = ft_strdup(list->data);
		list = list->next;
		++i;
	}
	new[i] = NULL;
	return (new);
}
