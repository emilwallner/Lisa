/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 15:59:32 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <stdio.h>



void print_cords(t_vars *e)
{
	int i;
	int	k;

	i = 0;
	while(e->print[i] != NULL)
	{
		if(i < e->totlen - e->xlen)
		{
			k = i + e->xlen;
			print_line(e, e->print[i], e->print[k]);
		}
		if((i + 1) % e->xlen != 0)
		{
			k = i + 1;
			print_line(e, e->print[i], e->print[k]);
		}
		i++;
	}
}

void	adjust_vars(t_vars *e)
{
	int		i;

	i = 0;
	while(e->print[i] != NULL)
	{
		e->print[i]->xp = e->print[i]->x;
		e->print[i]->yp = e->print[i]->y;
		e->print[i]->xp = e->print[i]->xp + (e->print[i]->xp * e->zoom);
		e->print[i]->yp = e->print[i]->yp + (e->print[i]->yp * e->zoom);
		e->print[i]->hp = e->print[i]->h * e->depth;
		e->print[i]->xp = (e->const1 * e->print[i]->xp) - (e->const2 * e->print[i]->yp);
		e->print[i]->yp = (e->print[i]->h * e->depth) + ((e->const1  / 2) * e->print[i]->xp) + ((e->const2 / 2) * e->print[i]->yp);
		e->print[i]->xp = e->print[i]->xp + e->xc;
		e->print[i]->yp = e->print[i]->yp + e->yc;
		i++;
	}
}

int zoom_that_shit(int keycode, t_vars *e)
{
	printf("This is keycode: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e->print);
		free(e);
		exit(0);
	}
	if(keycode == 125 || keycode == 126)
		move_me_upndown(keycode, e);
	if(keycode == 123 || keycode == 124)
		move_me_leftnright(keycode, e);
	if (keycode == 78 || keycode == 69)
		move_me_in(keycode, e);
	if (keycode == 86 || keycode == 88)
		increase_const_one(keycode, e);
	if (keycode == 91 || keycode == 84)
		increase_const_two(keycode, e);
	if (keycode == 83 || keycode == 85)
		increase_depth(keycode, e);
	if (keycode == 36)
		create_trip(e);
	return (0);
}

void	run_screen(t_vars *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, SCREEN, SCREEN - 500, "Merry Christmas");
	ft_set_vars(e);
	adjust_vars(e);
	print_cords(e);	
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "Disco Mode = RETURN");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "Move = <-, ->, up, down");
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF, "Depth = 1 & 3");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF, "Tilt = 4 & 6");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF, "Stretch = 8 & 2");
	mlx_string_put(e->mlx, e->win, 10, 110, 0xFFFFFF, "Zoom = - & +");
	mlx_key_hook(e->win, zoom_that_shit, e);
	mlx_loop(e->mlx);
}

int			main(int ac, char **av)
{
	int		xlen;
	char	*str;
	t_vars	*e;
	char	**grid;
//	int		*vars;

	xlen = 0;
	if (ac != 2)
		return (0);
	if(!(str = ft_file_to_str(av[1], &xlen)))
		return (0);
	e = (t_vars*)malloc(sizeof(t_vars));
	e->xlen = xlen;
	grid = ft_strsplit(str, ' ');
	e->print = ft_str_to_grid(e, grid);
	e->xlen = xlen;
	printf("This is it: %d\n", e->totlen);
	printf("This x it: %d\n", e->xlen);
	run_screen(e);
	return (0);
}

