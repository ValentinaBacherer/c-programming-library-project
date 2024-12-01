/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:49:45 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:49:46 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start_i;
	size_t	end_i;
	size_t	new_str_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0' || *set == '\0')
		return (ft_strdup(s1));
	start_i = 0;
	while (s1[start_i] && ft_strchr(set, s1[start_i]))
		start_i++;
	if (s1[start_i] == '\0')
		return (ft_strdup(""));
	end_i = ft_strlen(s1) - 1;
	while (end_i > start_i && ft_strchr(set, s1[end_i]))
		end_i--;
	new_str_len = end_i - start_i + 1;
	new_str = (char *)malloc(sizeof(char) * (new_str_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1 + start_i, new_str_len + 1);
	return (new_str);
}
