/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:57:26 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/16 22:52:21 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

void	ft_set_vars(t_vars *e)
{
	e->zoom = 50;
	e->xc = (SCREEN / e->xlen) * 10;
	e->yc = (SCREEN / (e->totlen / e->xlen) * 3);
	e->const1 = 0.5;
	e->const2 = 1;
	e->depth = 0;
}

