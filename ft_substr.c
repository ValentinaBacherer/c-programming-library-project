/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:49:52 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:49:52 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calculate_len(size_t src_len, unsigned int start_index,
		size_t max_len)
{
	if (src_len - start_index < max_len)
		return (src_len - start_index);
	return (max_len);
}

char	*ft_substr(char const *src, unsigned int start_index, size_t len)
{
	char	*new_str;
	size_t	src_len;
	size_t	substr_len;

	if (src == NULL)
		return (NULL);
	src_len = ft_strlen(src);
	if (src_len == 0 || start_index > (src_len - 1) || len == 0)
		return (ft_strdup(""));
	substr_len = ft_calculate_len(src_len, start_index, len);
	new_str = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, src + start_index, substr_len + 1);
	return (new_str);
}

/**
 * Errors:
 * typing for helper function (type mismatch)
 * sizeof(new_str) as param, misuse of sizeof
 * When applied to an array, sizeof returns the
 * total size of the array in bytes. The size includes
 * all elements of the array, multiplied by the size of each element.
 * calculate_lenght works because start_index is inclusive.
 */