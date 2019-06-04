/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:07:51 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 16:21:40 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	t_env *current_node;

	current_node = g_ptm;
	while (current_node != NULL)
	{
		ft_printf(L_CYAN "%s=" RESET, current_node->key);
		if (current_node->value)
			ft_printf(CYAN "%s" RESET, current_node->value);
		ft_printf("\n");
		current_node = current_node->next;
	}
}

void	create_env(void)
{
	extern char	**environ;
	int			i;
	char		**tmp;

	i = 0;
	while (environ[i])
	{
		tmp = ft_strsplit(environ[i], '=');
		add_to_env(tmp[0], tmp[1]);
		delete_double_pointer(tmp);
		++i;
	}
}

void	add_to_env(char *key, char *value)
{
	t_env	*begining;
	t_env	*node;

	if (!g_ptm)
	{
		g_ptm = (t_env *)malloc(sizeof(t_env));
		g_ptm->key = ft_strdup(key);
		if (value)
			g_ptm->value = ft_strdup(value);
		else
			g_ptm->value = ft_strdup("");
		g_ptm->next = NULL;
	}
	node = (t_env *)malloc(sizeof(t_env));
	begining = g_ptm;
	node->next = NULL;
	node->key = ft_strdup(key);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = ft_strdup("");
	while (begining->next)
		begining = begining->next;
	begining->next = node;
}
