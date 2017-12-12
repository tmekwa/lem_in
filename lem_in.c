/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:29:48 by tntoampe          #+#    #+#             */
/*   Updated: 2017/11/30 13:26:59 by tntoampe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	frees(t_argues *args)
{
	if (args->line != NULL)
	{
		free(args->line);
		args->line = NULL;
	}
	if (args->links != NULL)
	{
		free_2d_array(args->links);
		args->links = NULL;
	}
	if (args->room_split != NULL)
	{
		free_2d_array(args->room_split);
		args->room_split = NULL;
	}
}

void	ft_links(t_vars *vars, t_argues *args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	vars->start_link = 0;
	vars->end_link = 0;
	args->links = ft_strsplit(args->room_split[0], '-');
	if (ft_array_len(args->links) > 2 || args->rooms[vars->start_link] == NULL)
		exit_prog();
	while (ft_strcmp(args->rooms[vars->start_link]->name, args->links[0]) != 0)
		if (args->rooms[++vars->start_link] == NULL)
			exit_prog();
	while (ft_strcmp(args->rooms[vars->end_link]->name, args->links[1]) != 0)
		if (args->rooms[++vars->end_link] == NULL)
			exit_prog();
	while (args->rooms[vars->start_link]->rooms[i])
		i++;
	while (args->rooms[vars->end_link]->rooms[j])
		j++;
	args->rooms[vars->start_link]->rooms[i] = args->rooms[vars->end_link];
	args->rooms[vars->end_link]->rooms[j] = args->rooms[vars->start_link];
}

void	ft_rooms(t_vars *vars, t_argues *args)
{
	if (ft_array_len(args->room_split) > 3)
		exit_prog();
	args->rooms[vars->room_count] = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	args->rooms[vars->room_count]->name = ft_strdup(args->room_split[0]);
	if (vars->start == 1)
	{
		args->rooms[vars->room_count]->start = 1;
		vars->start = 0;
		ft_putendl("##start");
	}
	if (vars->end == 1)
	{
		args->rooms[vars->room_count]->end = 1;
		vars->end = 0;
		ft_putendl("##end");
	}
	vars->room_count++;
}

void	startend(t_vars *vars, t_argues *args)
{
	if (args->line[1] == '#' && args->line[0] != '\0')
	{
		if (ft_strstr(args->line, "start") != NULL)
			vars->start = 1;
		else if (ft_strstr(args->line, "end") != NULL)
			vars->end = 1;
	}
}

void	read_file(t_vars *vars, t_argues *args)
{
	while ((get_next_line(0, &args->line)) != 0)
	{
		if (vars->count < 1 && ft_isdigit(args->line[0]))
		{
			vars->num_ants = ft_atoi(args->line);
			printing(vars);
			vars->count++;
		}
		else if (vars->count > 0)
		{
			if (args->line[0] == '#')
				startend(vars, args);
			else
			{
				args->room_split = ft_strsplit(args->line, ' ');
				ft_putendl(args->line);
				if (args->room_split[0] == '\0')
					exit_prog();
				else if (args->room_split[1] == NULL)
					ft_links(vars, args);
				else
					ft_rooms(vars, args);
			}
		}
	}
}
