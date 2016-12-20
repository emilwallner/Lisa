/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_features_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:03:15 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 16:05:15 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
