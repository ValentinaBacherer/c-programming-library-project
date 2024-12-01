/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:48:31 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:48:32 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	tot_len;

	tot_len = ft_strlen(s) + 1;
	new_str = (char *)malloc(tot_len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	return (ft_memcpy(new_str, s, tot_len));
}
