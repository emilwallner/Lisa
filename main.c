/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/14 14:36:18 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <stdio.h>


void print_line(void *mlx, void *win, int *first, int *last) 
{
	int x;
	int y;
	float a;
	float b;

	printf("This is first X: %d\n", first[0]);
	printf("This is first Y: %d\n", first[1]);
	printf("This is last X: %d\n", last[0]);
	printf("This is last Y: %d\n", last[1]);

	a = (float) (last[1] - first[1]) / (last[0] - first[0]); 
	b = first[1] - a * first[0]; 

	x = first[0];
	while (x <= last[0]) 
	{ 
		y = (int) (a * x + b); 
		mlx_pixel_put(mlx, win, x, y, 0x0000FF9A); 
		x++;
	}
}

void print_cords(int **grid, int xlen)
{
	void *mlx;
	void *win;
	int i;
	int	k;
	
	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 700, 700, "Merry Christmas");
	while(i < 10)
	{
		k = i + 1;
		print_line(mlx, win, grid[i], grid[k]);
		i++;
	}
	mlx_loop(mlx);
}
/*
void		print_cords(int		**grid)
{
	int		i;
	void *mlx;
	void *win;
	int x;
	int y;

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	while (grid[i] != NULL) 
	{ 
		mlx_pixel_put(mlx, win, grid[i][0], grid[i][1], 0x0000FF9A); 
		i++;
	}
	mlx_loop(mlx);
}
*/
int			main(int ac, char **av)
{
int		xlen;
char	*str;
char	**grid;
int		*vars;
int		**print;
int		i;


	xlen = 0;
	if (ac != 2)
		return (0);
//	ft_putstr("ok");
	if(!(str = ft_file_to_str(av[1], &xlen)))
		return (0);
	//ft_putstr(str);
	//ft_putnbr(ft_strlen(str));
	grid = ft_strsplit(str, ' ');
	//ft_putnbr(xlen);
	//ft_putstr("\n\n\n");
	//ft_putnbr(ft_strstrlen(grid));
	vars = ft_set_vars();
	print = ft_str_to_grid(grid, vars, xlen);
	i = 0;
	while (print[i] != NULL)
	{
		printf("This is X: %d\n", print[i][0]);
		printf("This is Y: %d\n", print[i][1]);
		i++;
	}
	//ft_putnbr(ft_strstrlen(grid));
	print_cords(print, xlen);
	//ft_putstr("\n\n\n");
	//ft_putstr(str);
	//	coord_to_line(0, 0, 300, 300);
	return (0);
}

