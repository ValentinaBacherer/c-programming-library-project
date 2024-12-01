/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:48:36 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:48:37 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*func)(unsigned int, char *))
{
	unsigned int	i;

	if (str == NULL || func == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		func(i, &str[i]);
		i++;
	}
}

/*
Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
In C, function pointers can be called directly without explicit dereferencing,
	so f(&s[i]); and (*f)(&s[i]); are equivalent.
*/