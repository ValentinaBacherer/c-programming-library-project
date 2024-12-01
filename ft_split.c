/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:48:19 by vabacher          #+#    #+#             */
/*   Updated: 2024/12/01 11:48:20 by vabacher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);

static void		free_arr(char **arr, int i);

static char		**fill_arr(char **arr, size_t len_arr, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	len_arr;

	if (!s)
		return (NULL);
	len_arr = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (len_arr + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(arr, len_arr, s, c);
	return (arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	new_word_found;

	count = 0;
	new_word_found = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (new_word_found == 0)
			{
				new_word_found = 1;
				count++;
			}
		}
		else
		{
			new_word_found = 0;
		}
		s++;
	}
	return (count);
}

static void	free_arr(char **arr, int current_i)
{
	while (current_i > 0)
		free(arr[--current_i]);
	free(arr);
}

static char	**fill_arr(char **arr, size_t len_arr, char const *s, char c)
{
	size_t	word_i;
	size_t	j;
	size_t	start_i;

	word_i = 0;
	j = 0;
	while (word_i < len_arr)
	{
		while (s[j] && s[j] == c)
			j++;
		start_i = j;
		while (s[j] && s[j] != c)
			j++;
		arr[word_i] = ft_substr(s, start_i, j - start_i);
		if (arr[word_i] == NULL)
		{
			free_arr(arr, word_i);
			return (NULL);
		}
		word_i++;
	}
	arr[word_i] = NULL;
	return (arr);
}
