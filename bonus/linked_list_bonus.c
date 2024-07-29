/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:15:14 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/07/28 13:34:28 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	*ft_lstnew(t_var *var)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = var->x;
	point->y = var->y;
	point->z = var->z;
	point->color = var->color;
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

void	ft_lstclear(t_fdf *lst)
{
	t_point	*tmp;

	if (!lst)
		return ;
	while (lst->point)
	{
		tmp = lst->point->next;
		free(lst);
		lst->point = tmp;
	}
	free(lst->point);
	lst->point = NULL;
}
t_point	*ft_point_copy(t_point *lst)
{
	t_var	var;
	t_point	*head;
	t_point	*node;

	head = NULL;
	node  = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		var.x = lst->x;
		var.y = lst->y;
		var.color = lst->color;
		var.z = lst->z;
		node = ft_lstnew(&var);
		if (!node)
		{
			while (head)
			{
				t_point *next = head->next;
				free(head);
				head = next;
			}
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
