/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:48:53 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:48:53 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	last_writable_index;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	last_writable_index = size - 1;
	while (src[i] && i < last_writable_index)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/**
 * strlcpy: Copies a string from src to dst
 * with a size limit, ensuring null-termination
 * of the destination buffer.
 * strlcat: Concatenates a string (src) to the end of another
 * (dst), with a size limit,
	ensuring null-termination of the destination buffer.
 */