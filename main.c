/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/13 19:21:55 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <stdio.h>

/*
void coord_to_line(int xi,int yi,int xf,int yf) 
{
	void *mlx;
	void *win;
	int x;
	int y;
	float a;
	float b;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	a = (float) (yf-yi) / (xf-xi); 
	b = yi - a * xi; 

	x = xi;
	while (x <= xf) 
	{ 
		y = (int) (a * x + b); 
		mlx_pixel_put(mlx, win, x, y, 0x0000FF9A); 
		x++;
	}
	mlx_loop(mlx);
}
*/

void		print_cords(int		**grid)
{
	int		i;
	void *mlx;
	void *win;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	while (grid[i] != NULL) 
	{ 
		mlx_pixel_put(mlx, win, grid[i][0], grid[i][1], 0x0000FF9A); 
		i++;
	}
	mlx_loop(mlx);
}

int			main(int ac, char **av)
{
int		xlen;
char	*str;
char	**grid;
int		*vars;
int		**print;


	xlen = 0;
	if (ac != 2)
		return (0);
//	ft_putstr("ok");
	if(!(str = ft_file_to_str(av[1], &xlen)))
		return (0);
	grid = ft_strsplit(str, ' ');
	//ft_putnbr(xlen);
	vars = ft_set_vars();
	print = ft_str_to_grid(grid, vars, xlen);
	print_cords(print);

	//ft_putnbr(ft_strstrlen(grid));
	//ft_putstr("\n\n\n");
	//ft_putstr(str);
	//	coord_to_line(0, 0, 300, 300);
	return (0);
}

