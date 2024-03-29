/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:28:30 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 17:23:20 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

t_coord		**ft_xy_depth(t_coord **print, char **grid, t_vars *e)
{
	int		col;
	int		row;
	int		i;
	t_coord *point;

	i = -1;
	row = 0;
	col = -1;
	while (grid[++i] != '\0')
	{
		col++;
		if (!(point = (t_coord*)malloc(sizeof(t_coord))))
			exit(0);
		point->x = col;
		point->y = row;
		if ((i + 1) % e->xlen == 0)
		{
			row++;
			col = -1;
		}
		point->h = ft_atoi(grid[i]);
		print[i] = point;
	}
	print[i] = NULL;
	return (print);
}

t_coord		**ft_str_to_grid(t_vars *e, char **grid)
{
	t_coord		**print;
	int			totlen;

	totlen = 0;
	if (!(print = (t_coord**)malloc(sizeof(t_coord) * ft_strstrlen(grid) + 1)))
		exit(0);
	ft_xy_depth(print, grid, e);
	while (print[totlen] != NULL)
		totlen++;
	e->totlen = totlen;
	return (print);
}
