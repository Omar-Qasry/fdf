/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 05:06:35 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/29 17:36:39 by oel-qasr         ###   ########.fr       */
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

int	ft_count_words(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\n'))
			i++;
	}
	return (count);
}
long	ft_atoi(char *str)
{
	long	re;
	int		sg;

	sg = 1;
	re = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((re > INT_MAX && sg == 1) || (-re < INT_MIN && sg == -1))
			ft_error("map invalid");
		re = re * 10 + *str - '0';
		str++;
	}
	return (re * sg);
}
