/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:28:30 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/15 17:41:30 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

t_coord **ft_xy_depth(t_coord **print, int *vars, int xlen, char **grid)
{
	int		col;
	int		row;
	int		i;
	t_coord *point;

	i = 0;
	row = 0;
	col = -1;
	while(grid[i] != '\0')
	{
		col++;
		point = (t_coord*)malloc(sizeof(t_coord));
		point->x = col * vars[3] + vars[0];
		point->y = row * vars[3] + vars[1];
		if ((i + 1) % xlen == 0)
		{
			row++;
			col = -1;
		}
		point->h = vars[2] * ft_atoi(grid[i]);
		print[i] = point;
		i++;
	}
	print[i] = NULL;
	return (print);
}

t_coord		**ft_str_to_grid(char **grid, int *vars, int xlen)
{
	t_coord		**print;

	print = (t_coord**)malloc(sizeof(t_coord) * ft_strstrlen(grid) + 1);
	ft_xy_depth(print, vars, xlen, grid);
	return (print);
}
