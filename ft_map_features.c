/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_features.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 22:29:54 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 16:09:52 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "unistd.h"

void	clean_and_launch(t_vars *e)
{
	mlx_clear_window(e->mlx, e->win);
	adjust_vars(e);
	print_cords(e);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "Disco Mode = RETURN");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "Move = <-, ->, up, down");
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF, "Depth = 1 & 3");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF, "Tilt = 4 & 6");
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF, "Stretch = 8 & 2");
	mlx_string_put(e->mlx, e->win, 10, 110, 0xFFFFFF, "Zoom = - & +");
}

void	increase_depth(int keycode, t_vars *e)
{
	if (keycode == 83)
		e->depth += 1;
	else
		e->depth -= 1;
	clean_and_launch(e);
}

void	create_trip(t_vars *e)
{
	int i;

	i = 0;
	if (e->coloron == 1)
		e->coloron = 0;
	else
		e->coloron = 1;
	clean_and_launch(e);
}

void	increase_const_one(int keycode, t_vars *e)
{
	if (keycode == 86)
		e->const1 += 0.1;
	else
		e->const1 -= 0.1;
	clean_and_launch(e);
}

void	increase_const_two(int keycode, t_vars *e)
{
	if (keycode == 91)
		e->const2 += 0.1;
	else
		e->const2 -= 0.1;
	clean_and_launch(e);
}
