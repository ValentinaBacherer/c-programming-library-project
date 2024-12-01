/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:48:47 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:50:40 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	last_writable_index;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	if (src_len == 0)
		return (dst_len);
	last_writable_index = size - 1;
	i = 0;
	while (src[i] && (dst_len + i) < last_writable_index)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/**
 * strlcpy: Copies a string from src to dst
 * with a size limit, ensuring null-termination
 * of the destination buffer.
 * strlcat: Concatenates a string (src) to the end of another
 * (dst), with a size limit,
	ensuring null-termination of the destination buffer.
 */