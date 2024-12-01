/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:47:30 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:47:31 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	l;

	l = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == l)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

/*
 * Function: ft_memchr
 * --------------------
 * Scans the first `n` bytes of the memory area
 * pointed to by `s` for the first occurrence
 * of the byte value `c`. If the byte is found,
 * a pointer to it is returned. If the byte
 * is not found within the specified range,
 * the function returns `NULL`.
 *
 * Parameters:
 *  - s: A pointer to the memory area to search.
 *  - c: The byte value to find (passed as an `int`
 * but interpreted as an unsigned char).
 *  - n: The number of bytes to search in the memory area.
 *
 * Returns:
 *   - A pointer to the first occurrence of `c` in the
 *     memory area `s`, or
 *   - `NULL` if `c` is not found within the first `n` bytes.
 */