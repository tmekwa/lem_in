/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:47:36 by tntoampe          #+#    #+#             */
/*   Updated: 2017/11/30 11:11:28 by tntoampe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_prog(void)
{
	ft_putendl("ERROR");
	exit(0);
}

size_t	ft_array_len(char **array)
{
	size_t index;

	index = 0;
	while (array[index])
		index++;
	return (index);
}

void	start_end(t_vars *vars, t_argues *args)
{
	vars->start = 0;
	vars->end = 0;
	while (args->rooms[vars->start]->start == 0)
		if (args->rooms[++vars->start] == NULL)
			exit_prog();
	while (args->rooms[vars->end]->end == 0)
		if (args->rooms[++vars->end] == NULL)
			exit_prog();
	args->rooms[vars->start]->full = vars->num_ants;
}

void	ant_names(t_vars *vars, t_argues *args)
{
	int count;

	count = 0;
	args->ants = (t_ants**)ft_memalloc(sizeof(t_ants*) * (vars->num_ants + 1));
	while (count < vars->num_ants)
	{
		args->ants[count] = (t_ants*)ft_memalloc(sizeof(t_ants));
		args->ants[count]->name = ft_itoa(count + 1);
		args->ants[count]->ant_index = 1;
		args->ants[count]->room = args->rooms[vars->start]->name;
		args->ants[count]->at_end = 0;
		count++;
	}
	count = 0;
	while (args->rooms[count])
	{
		args->rooms[count]->visited = 0;
		count++;
	}
}

int		main(void)
{
	t_vars		vars;
	t_argues	args;

	ft_bzero(&vars, sizeof(t_vars));
	ft_bzero(&args, sizeof(t_argues));
	read_file(&vars, &args);
	if (vars.count == 0)
		exit_prog();
	start_end(&vars, &args);
	ant_names(&vars, &args);
	ft_paths(&vars, &args);
	if (!args.paths[0])
		exit_prog();
	ft_putchar('\n');
	while (args.rooms[vars.end]->full < vars.num_ants)
	{
		vars.j = 0;
		antlooping(&vars, &args);
		ft_putstr("\n");
	}
	freeing_rooms(&args);
	free_paths(&args);
	freeing_ants(&args);
	return (0);
}
