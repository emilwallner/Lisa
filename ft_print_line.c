/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:40:51 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/17 15:16:34 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

unsigned int createRGB(unsigned char r, unsigned char g, unsigned char b)
{   
	    return (r << 16) + (g << 8) + (b);
}

unsigned int createRND(t_vars *e)
{
	e->r += 13;
	e->g += 17;
	e->b += 23;
	if (e->r > 255)
		e->r = e->r % 255;
	if (e->g > 255)
		e->g = e->g % 255;
	if (e->b > 255)
		e->b = e->b % 255;
	return (e->r << 16) + (e->g << 8) + (e->b);
}

void print_line(t_vars *e, t_coord *first, t_coord *last) 
{
		t_line		*l;
		if(e->coloron == 1)
			e->color = createRND(e);
		else
			e->color = 0x00FFFFFF;
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
			mlx_pixel_put(e->mlx, e->win, l->x, l->y, e->color); 
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
				mlx_pixel_put(e->mlx, e->win, l->x, l->y, e->color); 
			l->i++;
			}
		}
		else
		{
			mlx_pixel_put(e->mlx, e->win, l->x, l->y, e->color); 
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
				mlx_pixel_put(e->mlx, e->win, l->x, l->y, e->color); 
			l->i++;
			}
		}
}


