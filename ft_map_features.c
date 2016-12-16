/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_features.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 22:29:54 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/16 23:48:38 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	clean_and_launch(t_vars *e)
{
	mlx_clear_window(e->mlx, e->win);
	adjust_vars(e);
	print_cords(e);
}

void	move_me_in(int keycode, t_vars *e)
{
	if (keycode == 69)
		e->zoom += 10;
	else
		e->zoom -= 10;
	clean_and_launch(e);
}

void	move_me_upndown(int keycode, t_vars *e)
{
	if (keycode == 125)
		e->yc = e->yc + 50;
	else
		e->yc = e->yc - 50;
	clean_and_launch(e);
}
void	move_me_leftnright(int keycode, t_vars *e)
{
	if (keycode == 124)
		e->xc = e->xc + 50;
	else
		e->xc = e->xc - 50;
	clean_and_launch(e);
}
