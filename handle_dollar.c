/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:07:09 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 16:26:43 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*manage_dollar(char *type, char *data)
{
	char	*newdata;
	int		i;

	i = 0;
	if (*data && ft_strcmp(type, "space") == 0 && data[0] == '$')
	{
		data++;
		if (*data)
		{
			if (ft_strcmp(search_by_key(data), "EMPTY"))
			{
				newdata = ft_strdup(search_by_key(data));
				return (newdata);
			}
			else
				return ("there is no env like this");
		}
		else
			return ("$");
	}
	return (ft_strdup(data));
}
