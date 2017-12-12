/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:13 by tntoampe          #+#    #+#             */
/*   Updated: 2017/11/29 10:45:39 by tntoampe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_argues *args)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (args->paths[index])
	{
		count = 0;
		while (args->paths[index][count])
		{
			free(args->paths[index][count]);
			count++;
		}
		free(args->paths[index]);
		index++;
	}
	free(args->paths);
}

void	freeing_rooms(t_argues *args)
{
	int count;

	count = 0;
	while (args->rooms[count])
	{
		free(args->rooms[count]->name);
		free(args->rooms[count]);
		count++;
	}
}

void	freeing_ants(t_argues *args)
{
	int count;

	count = 0;
	while (args->ants[count])
	{
		free(args->ants[count]->name);
		free(args->ants[count]);
		count++;
	}
	free(args->ants);
}

void	free_2d_array(char **array)
{
	int count;

	count = 0;
	while (array[count])
	{
		free(array[count]);
		count++;
	}
	free(array);
}
