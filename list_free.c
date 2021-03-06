/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:26:43 by mleclair          #+#    #+#             */
/*   Updated: 2017/01/02 19:49:32 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	list_free_inner(t_file *lst)
{
	if (lst->acces)
		free(lst->acces);
	if (lst->nbfconv)
		free(lst->nbfconv);
	if (lst->owner)
		free(lst->owner);
	if (lst->sizeconv)
		free(lst->sizeconv);
	if (lst->name)
		free(lst->name);
	if (lst->path)
		free(lst->path);
	if (lst->group)
		free(lst->group);
}

void	list_free_down(t_file *lst)
{
	t_file *tmp;

	while (lst != NULL)
	{
		list_free_inner(lst);
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

void	list_free_up(t_file *lst)
{
	t_file *tmp;

	while (lst != NULL)
	{
		list_free_inner(lst);
		tmp = lst;
		lst = lst->prev;
		free(tmp);
		tmp = NULL;
	}
}

void	list_free(t_file *lst)
{
	if (lst->next)
		list_free_down(lst);
	else if (lst->prev)
		list_free_up(lst);
}
