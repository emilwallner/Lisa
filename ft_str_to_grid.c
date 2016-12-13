/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:28:30 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/13 19:13:32 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int **ft_xy_depth(int **grid, int *vars, int xlen, char **str)
{
	int		col;
	int		row;
	int		i;

	i = 0;
	row = 0;
	col = -1;
	while(str[i] != '\0')
	{
		col++;
		grid[i][0] = col * vars[3] + vars[0];
		grid[i][1] = row * vars[3] + vars[1];
		if (i % xlen - 1 == 0)
		{
			row++;
			col = -1;
		}
		grid[i][2] = vars[2] * ft_atoi(str[i]);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

int		**ft_str_to_grid(char **str, int *vars, int xlen)
{
	int		**grid;

	grid = (int**)malloc(sizeof(grid) * (ft_strstrlen(str) / xlen) + 1);
	ft_xy_depth(grid, vars, xlen, str);

	return (grid);
}
