/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:23:21 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/25 10:29:28 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static	int	ft_words(const char *str, char d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == d || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != d && str[i] != '\n'))
			i++;
	}
	return (count);
}

static	int	split_strlen(const char *str, char d)
{
	int	i;

	i = 0;
	while (str[i] != d && str[i])
		i++;
	return (i);
}

void	*is_free(char **return_arr)
{
	size_t	i;

	i = 0;
	while (return_arr[i])
	{
		free(return_arr[i]);
		i++;
	}
	free(return_arr);
	return (NULL);
}

static	void	alloc_str(const char **s, char **ret, char c)
{
	int	i;
	int	len;

	i = 0;
	len = split_strlen(*s, c);
	*ret = (char *)malloc(len + 1);
	if (!*ret)
		return ;
	while (i < len)
	{
		(*ret)[i] = **s;
		i++;
		(*s)++;
	}
	(*ret)[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**return_arr;
	int		words_to_split;
	int		i;

	if (!s)
		return (NULL);
	words_to_split = ft_words(s, c);
	i = 0;
	return_arr = (char **)malloc((words_to_split + 1) * sizeof(char *));
	if (!return_arr)
		return (NULL);
	while (i < words_to_split)
	{
		while (*s == c)
			s++;
		alloc_str(&s, &return_arr[i], c);
		if (!return_arr[i])
			return (is_free(return_arr));
		i++;
	}
	return_arr[i] = 0;
	return (return_arr);
}
