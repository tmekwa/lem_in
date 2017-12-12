/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:52:13 by tntoampe          #+#    #+#             */
/*   Updated: 2017/11/30 14:23:15 by tntoampe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# define BUFF_SIZE 1
# define BUFF 1024

typedef struct s_vars	t_vars;
typedef struct s_rooms	t_rooms;
typedef struct s_ants	t_ants;
typedef struct s_paths	t_paths;
typedef struct s_argues	t_argues;

struct	s_vars
{
	char	*file;
	int		count;
	int		num_ants;
	int		start;
	int		end;
	int		start_link;
	int		end_link;
	char	**rooms_argues;
	char	**room_split;
	char	**links;
	t_ants	**ants;
	int		room_count;
	char	***paths;
	int		index;
	int		j;
	int		ind;
	int		i;
	int		k;
	int		move;
	int		l;
};

struct	s_rooms
{
	char	*name;
	int		start;
	int		end;
	int		visited;
	int		full;
	t_rooms	*rooms[10000];
};

struct	s_ants
{
	char			*name;
	char			*room;
	int				at_end;
	unsigned int	ant_index;
};

struct	s_argues
{
	t_rooms	*rooms[10000];
	char	*line;
	char	**room_split;
	char	**links;
	t_ants	**ants;
	char	***paths;
	int		iterate;

};

struct	s_paths
{
	char			*data;
	struct s_paths	*next;
};

void	roomlooping(t_vars *vars, t_argues *args);
void	pathlooping(t_vars *vars, t_argues *args);
void	antlooping(t_vars *vars, t_argues *args);
int		ft_digit(t_argues *args);
void	free_paths(t_argues *args);
void	freeing_rooms(t_argues *args);
void	freeing_ants(t_argues *args);
void	free_2d_array(char **array);
void	frees(t_argues *args);
void	ft_links(t_vars *vars, t_argues *args);
void	ft_rooms(t_vars *vars, t_argues *args);
void	startend(t_vars *vars, t_argues *args);
void	read_file(t_vars *vars, t_argues *args);
void	exit_prog(void);
size_t	ft_array_len(char **array);
void	start_end(t_vars *vars, t_argues *args);
void	ant_names(t_vars *vars, t_argues *args);
void	ft_moveto(t_vars *vars, t_argues *args, int *loops);
int		ft_movefrom(t_vars *vars, t_argues *args);
void	validpath(t_vars *vars, t_argues *args, int *loops);
void	save_path(t_paths *head, t_argues *args);
void	ft_path(t_rooms *roo, t_paths *head, t_paths *list, t_argues *args);
void	ft_paths(t_vars *vars, t_argues *args);
void	ft_sortlist(char ***array);
void	printing(t_vars *vars);

#endif
