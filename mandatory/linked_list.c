/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:15:14 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/06/29 18:03:06 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_lstnew(int x, int y, int z)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->next = NULL;
	return (point);
}

t_point	*ft_lstlast(t_point *lst)
{
	t_point	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_point **lst, t_point *newx)
{
	t_point	*last;

	if (!lst)
		return ;
	if (!*lst)
		*lst = newx;
	else
	{
		last = ft_lstlast(*lst);
		last->next = newx;
	}
}

int	ft_lstsize(t_point *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
