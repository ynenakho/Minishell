/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tilda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <ynenakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:07:18 by ynenakho          #+#    #+#             */
/*   Updated: 2019/03/22 16:26:55 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*valid_tilda(char *type, char *data)
{
	char	*newdata;
	char	*tmp;

	if (*data && ft_strcmp(type, "space") == 0 && data[0] == '~')
	{
		data++;
		tmp = ft_strdup(search_by_key("HOME"));
		if (*data)
			newdata = ft_strjoin(tmp, data);
		else
			newdata = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		return (newdata);
	}
	return (ft_strdup(data));
}
