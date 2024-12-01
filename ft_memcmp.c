/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:47:36 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:47:37 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (n == 0 || s1 == s2)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*
When performing arithmetic between two unsigned char,
the result is promoted to int during the calculation
which matches the return type of the function.
Pointer aritmetic vs array indexing.
Edge cases:
s1 or s2 == NULL, it should fail with segmentation fault.
n = 0, it returns 0, both are equal if you compare 0 bytes
*/