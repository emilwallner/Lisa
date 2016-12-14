/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:28:30 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/14 10:59:52 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int **ft_xy_depth(int **print, int *vars, int xlen, char **grid)
{
	int		col;
	int		row;
	int		i;

	i = 0;
	row = 0;
	col = -1;
	while(grid[i] != '\0')
	{
		col++;
		print[i] = (int*)malloc(sizeof(int) * 6);
		print[i][0] = col * vars[3] + vars[0];
		print[i][1] = row * vars[3] + vars[1];
		if ((i + 1) % xlen == 0)
		{
			row++;
			col = -1;
		}
		print[i][2] = vars[2] * ft_atoi(grid[i]);
		print[i][5] = '\0';
		i++;
	}
	print[i] = NULL;
	return (print);
}

int		**ft_str_to_grid(char **grid, int *vars, int xlen)
{
	int		**print;

	print = (int**)malloc(sizeof(int*) * ft_strstrlen(grid) + 1);
	ft_xy_depth(print, vars, xlen, grid);

	return (print);
}
