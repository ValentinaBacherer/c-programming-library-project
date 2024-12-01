/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:45:23 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:45:26 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	skip_whitespace_char(const char *str, size_t *j)
{
	while (str[*j] == 32 || (str[*j] > 8 && str[*j] < 14))
		(*j)++;
	return ;
}

void static	parse_sign(const char *str, size_t *j, int *sign)
{
	if (str[*j] == '-' || str[*j] == '+')
	{
		if (str[*j] == '-')
			(*sign) *= -1;
		(*j)++;
	}
	return ;
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		neg_flag;
	long	res;

	i = 0;
	neg_flag = 1;
	res = 0;
	skip_whitespace_char(str, &i);
	parse_sign(str, &i, &neg_flag);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		if (res * neg_flag > INT_MAX)
			return (INT_MAX);
		if (res * neg_flag < INT_MIN)
			return (INT_MIN);
		i++;
	}
	return (res * neg_flag);
}

/**
 * This function receives a null terminated string representing
 * the number to be converted.
 * and returns:
 * - if the string contains valid numeric characters,
 *   the integer representation of the input string.
 * Edge cases:
 * - str is null -> seg fault error
 * - int overflow -> INT_MIN or INT_MAX
 * - str with no digits -> return 0
 */