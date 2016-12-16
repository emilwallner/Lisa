/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/16 17:04:59 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <stdio.h>

void rotate_print(t_vars	*e)
{
	int		i;
	i = 0;
	while(e->print[i] != NULL)
	{
		e->print[i]->x = (e->const1 * e->print[i]->x) - (e->const2 * e->print[i]->y);
		e->print[i]->y = e->print[i]->h + ((e->const1  / 2) * e->print[i]->x) + ((e->const2 / 2) * e->print[i]->y);
		i++;
	}
}


int zoom_that_shit(int keycode, t_vars *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 78)
		mlx_clear_window(e->mlx, e->win);
	return (0);
}



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

void	run_screen(t_vars *e)
{
	e->mlx = mlx_init();
	e->const1 = 0.5;
	e->const2 = 1;
	e->win = mlx_new_window(e->mlx, SCREEN_W, SCREEN_H, "Merry Christmas");
	print_cords(e);
	rotate_print(e);
	mlx_key_hook(e->win, zoom_that_shit, e);
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
	e->xlen = xlen;
	grid = ft_strsplit(str, ' ');
	vars = ft_set_vars(e);
	e->print = ft_str_to_grid(e, grid);
	e->xlen = xlen;
	printf("This is it: %d\n", e->totlen);
	printf("This x it: %d\n", e->xlen);
	run_screen(e);
	return (0);
}

