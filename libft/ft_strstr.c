/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:04:17 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:08 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*begin;
	const char	*pattern;

	if (*big == *little && *big == '\0')
		return ((char *)big);
	while (*big)
	{
		begin = big;
		pattern = little;
		while (*pattern && *big && *pattern == *big)
		{
			pattern++;
			big++;
		}
		if (!*pattern)
			return ((char *)begin);
		big = begin + 1;
	}
	return (NULL);
}
