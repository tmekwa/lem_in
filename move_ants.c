/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:05:16 by tntoampe          #+#    #+#             */
/*   Updated: 2017/11/30 10:57:30 by tntoampe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_moveto(t_vars *vars, t_argues *args, int *loops)
{
	args->rooms[vars->k]->full += 1;
	args->ants[vars->j]->room = args->rooms[vars->k]->name;
	ft_putstr("L");
	ft_putstr(args->ants[vars->j]->name);
	ft_putstr("-");
	ft_putstr(args->rooms[vars->k]->name);
	ft_putstr(" ");
	vars->move = 1;
	vars->l = 0;
	*loops = 1;
}

int		ft_movefrom(t_vars *vars, t_argues *args)
{
	if (ft_strcmp(args->paths[vars->i][args->ants[vars->j]->ant_index - 1],
		args->rooms[vars->l]->name) == 0)
	{
		args->rooms[vars->l]->full -= 1;
		return (1);
	}
	return (0);
}

void	validpath(t_vars *vars, t_argues *args, int *loops)
{
	if (args->rooms[vars->k]->full == 0 && args->rooms[vars->k]->end == 0)
	{
		ft_moveto(vars, args, loops);
		while (args->rooms[vars->l])
		{
			if (ft_movefrom(vars, args) == 1)
				break ;
			vars->l++;
		}
		args->ants[vars->j]->ant_index += 1;
	}
	else if (args->rooms[vars->k]->end == 1)
	{
		args->ants[vars->j]->at_end = 1;
		ft_moveto(vars, args, loops);
		while (args->rooms[vars->l])
		{
			if (ft_movefrom(vars, args) == 1)
				break ;
			vars->l++;
		}
		args->ants[vars->j]->ant_index += 1;
	}
}
