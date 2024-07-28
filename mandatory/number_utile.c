/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:47:17 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/25 12:38:57 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
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

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	get_digit(char c, int digits_in_base)
{
	int	max_digit;

	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	digit = get_digit(to_lower(*str), 16);
	while (digit >= 0)
	{
		result = result * 16;
		result = result + (digit * sign);
		++str;
		digit = get_digit(to_lower(*str), 16);
	}
	return (result);
}
