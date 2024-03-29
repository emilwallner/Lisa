/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:57:26 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 16:25:09 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

void	ft_set_vars(t_vars *e)
{
	e->zoom = 50;
	e->xc = 300;
	e->yc = 300;
	e->const1 = 0.5;
	e->const2 = 1;
	e->depth = 0;
	e->r = 1;
	e->g = 100;
	e->b = 200;
	e->coloron = 0;
	e->color = 0x00FFFFFF;
}
