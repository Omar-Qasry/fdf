/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 06:35:21 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/29 18:14:48 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd(str);
	exit(EXIT_FAILURE);
}
// void	ft_lstclear(t_stack **lst)
// {
// 	t_stack	*tmp;

// 	if (!lst)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		free (*lst);
// 		*lst = tmp;
// 	}
// 	free(*lst);
// 	*lst = NULL;
// }
