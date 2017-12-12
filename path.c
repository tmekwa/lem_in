/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:09:30 by tntoampe          #+#    #+#             */
/*   Updated: 2017/11/30 13:56:31 by tntoampe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	save_path(t_paths *head, t_argues *args)
{
	t_paths *list;
	int		index;
	char	**path;

	list = head;
	index = 0;
	while (list && list->data)
	{
		index++;
		list = list->next;
	}
	path = (char **)ft_memalloc(sizeof(char *) * (index + 1));
	list = head;
	index = 0;
	while (list && list->data)
	{
		path[index] = ft_strdup(list->data);
		index++;
		list = list->next;
	}
	args->paths[args->iterate] = path;
	args->iterate += 1;
}

void	ft_path(t_rooms *roo, t_paths *head, t_paths *list, t_argues *args)
{
	int		count;
	t_paths	*next;

	count = 0;
	list->next = (t_paths *)ft_memalloc(sizeof(t_paths));
	roo->visited = 1;
	list->data = roo->name;
	next = list->next;
	if (roo->end == 1)
	{
		free(next);
		list->next = NULL;
		save_path(head, args);
	}
	while (roo->rooms[count] && roo->end == 0)
	{
		if (roo->rooms[count]->visited == 0)
		{
			ft_path(roo->rooms[count], head, next, args);
		}
		count++;
	}
	roo->visited = 0;
}

void	ft_paths(t_vars *vars, t_argues *args)
{
	t_paths	*list;

	list = (t_paths*)ft_memalloc(sizeof(t_paths));
	args->paths = (char ***)ft_memalloc(sizeof(char **) * 10000);
	ft_path(args->rooms[vars->start], list, list, args);
	ft_sortlist(args->paths);
	free(list);
}

void	ft_sortlist(char ***array)
{
	char	**pointer;
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (array[index])
	{
		count = index + 1;
		while (array[count])
		{
			if (ft_array_len(array[index]) > ft_array_len(array[count]))
			{
				pointer = array[index];
				array[index] = array[count];
				array[count] = pointer;
			}
			count++;
		}
		index++;
	}
}
