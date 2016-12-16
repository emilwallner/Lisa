/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:40:51 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/16 15:42:19 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "mlx.h"

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
