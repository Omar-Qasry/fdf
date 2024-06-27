/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 05:06:35 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/27 14:29:40 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
		temp[i++] = 0;
	s = temp;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (count * size));
	return (tab);
}

int	ft_count_words(const char *str, char d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != d)
			count++;
		if (str[i] == d && str[i + 1] != d && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
