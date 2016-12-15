/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/15 17:58:12 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <stdio.h>

void rotate_print(t_coord	**print)
{
	float	const1;
	float	const2;
	int		i;

	const1 = 0.5;
	const2 = 1;

	i = 0;
	while(print[i] != NULL)
	{
		print[i]->x = (const1 * print[i]->x) - (const2 * print[i]->y);
		print[i]->y = print[i]->h + ((const1  / 2) * print[i]->x) + ((const2 / 2) * print[i]->y);
		i++;
	}
}

void print_line(t_vars *e, t_coord *first, t_coord *last) 
{
		int dx, dy, i, f;
		int incx, incy, inc1, inc2;
		int x,y;

		dx = last->x - first->x;
		dy = last->y - first->y;

		if(dx < 0) dx = -dx;
		if(dy < 0) dy = -dy;
		incx = 1;
		if(last->x < first->x) incx = -1;
		incy = 1;
		if(last->y < first->y) incy = -1;
		x=first->x;
		y=first->y;

		if(dx > dy)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0x0000FF9A); 
			f = 2*dy - dx;
			inc1 = 2*( dy -dx);
			inc2 = 2*dy;
			for(i = 0; i < dx; i++)
			{
				if(f >= 0)
				{
					y += incy;
					f += inc1;
				}
				else f += inc2;
				x += incx;
				mlx_pixel_put(e->mlx, e->win, x, y, 0x0000FF9A); 
			}
		}
		else
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0x0000FF9A); 
			f = 2*dx - dy;
			inc1 = 2*( dx - dy);
			inc2 = 2*dx;
			for(i = 0; i < dy; i++)
			{
				if(f >= 0)
				{
					x += incx;
					f += inc1;
				}
				else f += inc2;
				y += incy;
				mlx_pixel_put(e->mlx, e->win, x, y, 0x0000FF9A); 
			}
		}
}

int zoom_that_shit(void *win, int keycode, void *param)
{
	if (keycode == 78)
		mlx_clear_window(param, win);
	return (0);
}

void print_cords(t_vars *e, int xlen)
{
	void *mlx;
	void *win;
	int i;
	int	k;
	int		totlen;

	totlen = 0;
	while (e->print[totlen] != NULL)
		totlen++;
	i = 0;
	e->mlx = mlx_init();
	rotate_print(e->print);
	e->win = mlx_new_window(e->mlx, 2000, 2000, "Merry Christmas");
	while(e->print[i] != NULL)
	{
		if(i < totlen - xlen)
		{
			k = i + xlen;
			print_line(e, e->print[i], e->print[k]);
		}
		if((i + 1) % xlen != 0)
		{
			k = i + 1;
			print_line(e, e->print[i], e->print[k]);
		}
		i++;
	}
	mlx_key_hook(e->win, zoom_that_shit, e->mlx);
	mlx_loop(e->mlx);
}

int			main(int ac, char **av)
{
	int		xlen;
	char	*str;
	t_vars	*e;
	char	**grid;
	int		*vars;

	xlen = 0;
	if (ac != 2)
		return (0);
	if(!(str = ft_file_to_str(av[1], &xlen)))
		return (0);
	e = (t_vars*)malloc(sizeof(t_vars));
	grid = ft_strsplit(str, ' ');
	vars = ft_set_vars();
	e->print = ft_str_to_grid(grid, vars, xlen);
	print_cords(e, xlen);
	return (0);
}

