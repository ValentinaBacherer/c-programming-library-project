/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:50:03 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:50:04 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 97 && i <= 122)
		return (i - 32);
	return (i);
}

/*
It does not handle exceptions when it is passed a non alphanumeric character,
	just returns same
*/