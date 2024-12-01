/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:49:31 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:49:34 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_nul_terminator(const char c);

static int	matches_needle(const char *haystack, const char *needle,
				size_t haystack_idx, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	haystack_idx;

	if (is_nul_terminator(*needle))
		return ((char *)haystack);
	if (is_nul_terminator(*haystack) || n == 0)
		return (NULL);
	haystack_idx = 0;
	while (!is_nul_terminator(haystack[haystack_idx]) && haystack_idx < n)
	{
		if (matches_needle(haystack, needle, haystack_idx, n))
			return ((char *)haystack + haystack_idx);
		haystack_idx++;
	}
	return (NULL);
}

static int	is_nul_terminator(const char c)
{
	return (c == '\0');
}

static int	matches_needle(const char *haystack, const char *needle,
		size_t haystack_idx, size_t n)
{
	size_t	needle_idx;

	needle_idx = 0;
	while (haystack[haystack_idx + needle_idx] == needle[needle_idx]
		&& (haystack_idx + needle_idx) < n)
	{
		if (is_nul_terminator(needle[needle_idx + 1]))
			return (1);
		needle_idx++;
	}
	return (0);
}
