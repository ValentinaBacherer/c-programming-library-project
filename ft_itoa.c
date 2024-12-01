/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:47:22 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:47:23 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_digits(int number);

char	*ft_itoa(int n)
{
	char			*new_str;
	unsigned int	number;
	size_t			length;

	length = ft_number_digits(n);
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	if (n < 0)
	{
		new_str[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		new_str[0] = '0';
	new_str[length] = '\0';
	while (number != 0)
	{
		new_str[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (new_str);
}

static size_t	ft_number_digits(int number)
{
	size_t	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length++;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

/**
 * writes the number in reverse,
 * from units to 10ns
 */