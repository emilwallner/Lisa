/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/14 20:26:33 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <stdio.h>

void rotate_print(int	**print)
{
	float	const1;
	float	const2;
	int		i;

	const1 = 0.5;
	const2 = 1;

	i = 0;
	while(print[i] != NULL)
	{
		print[i][0] = (const1 * print[i][0]) - (const2 * print[i][1]);
		print[i][1] = print[i][2] + ((const1  / 2) * print[i][0]) + ((const2 / 2) * print[i][1]);
		i++;
	}
}

void print_line(void *mlx, void *win, int *first, int *last) 
{
		int dx, dy, i, e;
		int incx, incy, inc1, inc2;
		int x,y;

		dx = last[0] - first[0];
		dy = last[1] - first[1];

		if(dx < 0) dx = -dx;
		if(dy < 0) dy = -dy;
		incx = 1;
		if(last[0] < first[0]) incx = -1;
		incy = 1;
		if(last[1] < first[1]) incy = -1;
		x=first[0];
		y=first[1];

		if(dx > dy)
		{
			mlx_pixel_put(mlx, win, x, y, 0x0000FF9A); 
			e = 2*dy - dx;
			inc1 = 2*( dy -dx);
			inc2 = 2*dy;
			for(i = 0; i < dx; i++)
			{
				if(e >= 0)
				{
					y += incy;
					e += inc1;
				}
				else e += inc2;
				x += incx;
				mlx_pixel_put(mlx, win, x, y, 0x0000FF9A); 
			}
		}
		else
		{
			mlx_pixel_put(mlx, win, x, y, 0x0000FF9A); 
			e = 2*dx - dy;
			inc1 = 2*( dx - dy);
			inc2 = 2*dx;
			for(i = 0; i < dy; i++)
			{
				if(e >= 0)
				{
					x += incx;
					e += inc1;
				}
				else e += inc2;
				y += incy;
				mlx_pixel_put(mlx, win, x, y, 0x0000FF9A); 
			}
		}
}

int zoom_that_shit(void *win, int keycode, void *param)
{
	if (keycode == 78)
		mlx_clear_window(param, win);
	return (0);
}

void print_cords(int **print, int xlen)
{
	void *mlx;
	void *win;
	int i;
	int	k;
	int		totlen;

	totlen = 0;
	while (print[totlen] != NULL)
		totlen++;
	i = 0;
	mlx = mlx_init();
	rotate_print(print);
	win = mlx_new_window(mlx, 2000, 2000, "Merry Christmas");
	while(print[i] != NULL)
	{
		if(i < totlen - xlen)
		{
			k = i + xlen;
			print_line(mlx, win, print[i], print[k]);
		}
		if((i + 1) % xlen != 0)
		{
			k = i + 1;
			print_line(mlx, win, print[i], print[k]);
		}
		i++;
	}
	mlx_key_hook(win, zoom_that_shit, mlx);
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
	/*
	while (print[i] != NULL)
	{
		printf("This is X: %d\n", print[i][2]);
		i++;
	}*/
	//ft_putnbr(ft_strstrlen(grid));
	print_cords(print, xlen);
	//ft_putstr("\n\n\n");
	//ft_putstr(str);
	//	coord_to_line(0, 0, 300, 300);
	return (0);
}

