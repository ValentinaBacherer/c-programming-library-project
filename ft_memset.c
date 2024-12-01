/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:47:50 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:47:51 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

/*
len is the number or bytes to set in memory block.
char is 1 byte, allows us to set memory byte-by-byte
it goes backguards in memory addresses
In C arguments smaller than int (like char)
are promoted to int when passed to a function
Only the least significant byte LSB of c is used
because each memory location holds one byte.
This is equivalent to p[len - 1] = (unsigned char)c,
where the higher-order bytes of c are discarded.
In C, both 0 and '\0' have the same numeric value,
so they are treated identically when passed as arguments to memset.
*/