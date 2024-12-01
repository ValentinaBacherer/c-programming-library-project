/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:49:03 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:49:04 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	char			*new_str;
	size_t			len;
	unsigned int	i;

	if (str == NULL || func == NULL)
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = func(i, str[i]);
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
