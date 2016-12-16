/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:40:51 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/16 23:44:58 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>


void print_line(t_vars *e, t_coord *first, t_coord *last) 
{
		t_line		*l;

		l = (t_line*)malloc(sizeof(t_line));
		l->dx = last->xp - first->xp;
		l->dy = last->yp - first->yp;
		if(l->dx < 0) l->dx = -(l->dx);
		if(l->dy < 0) l->dy = -(l->dy);
		l->incx = 1;
		if(last->xp < first->xp) l->incx = -1;
		l->incy = 1;
		if(last->yp < first->yp) l->incy = -1;
		l->x=first->xp;
		l->y=first->yp;

		if(l->dx > l->dy)
		{
			mlx_pixel_put(e->mlx, e->win, l->x, l->y, 0x0000FF9A); 
			l->f = 2*l->dy - l->dx;
			l->inc1 = 2*( l->dy - l->dx);
			l->inc2 = 2*l->dy;
			l->i = 0;
			while(l->i < l->dx)
			{
				if(l->f >= 0)
				{
					l->y += l->incy;
					l->f += l->inc1;
				}
				else l->f += l->inc2;
				l->x += l->incx;
				mlx_pixel_put(e->mlx, e->win, l->x, l->y, 0x0000FF9A); 
			l->i++;
			}
		}
		else
		{
			mlx_pixel_put(e->mlx, e->win, l->x, l->y, 0x0000FF9A); 
			l->f = 2*l->dx - l->dy;
			l->inc1 = 2*( l->dx - l->dy);
			l->inc2 = 2*l->dx;
			l->i = 0;
			while(l->i < l->dy)
			{
				if(l->f >= 0)
				{
					l->x += l->incx;
					l->f += l->inc1;
				}
				else l->f += l->inc2;
				l->y += l->incy;
				mlx_pixel_put(e->mlx, e->win, l->x, l->y, 0x0000FF9A); 
			l->i++;
			}
		}
}


