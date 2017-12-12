/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:07:09 by tntoampe          #+#    #+#             */
/*   Updated: 2017/12/08 21:35:39 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	roomlooping(t_vars *vars, t_argues *args)
{
	int loop;

	loop = 0;
	while (args->rooms[vars->k])
	{
		if ((ft_strcmp(args->paths[vars->i][args->ants[vars->j]->ant_index],
						args->rooms
						vars->k]->name) == 0) &&
		(ft_strcmp(args->paths[vars->i][args->ants[vars->j]->ant_index - 1],
					args->ants[vars->j]->room) == 0))
		{
			validpath(vars, args, &loop);
			if (loop == 1)
				break ;
		}
		vars->k++;
	}
}

void	pathlooping(t_vars *vars, t_argues *args)
{
	while (args->paths[vars->i])
	{
		vars->k = 0;
		if (args->ants[vars->j]->ant_index < ft_array_len(args->paths[vars->i]))
		{
			roomlooping(vars, args);
		}
		if (vars->move == 1)
		{
			vars->move = 0;
			break ;
		}
		vars->i++;
	}
}

void	antlooping(t_vars *vars, t_argues *args)
{
	while (args->ants[vars->j])
	{
		vars->i = 0;
		if (args->ants[vars->j]->at_end != 1)
		{
			pathlooping(vars, args);
		}
		vars->j++;
	}
}

int		ft_digit(t_argues *args)
{
	int	i;

	i = 0;
	args = NULL;
	while (args->line[i])
	{
		if (ft_isdigit(args->line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
