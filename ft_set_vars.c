/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:57:26 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/13 19:13:53 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		*ft_set_vars()
{
	int		i;
	int		*vars;

	i = 0;
	vars = (int*)malloc(sizeof(int) * 6);
	vars[5] = '\0';
	vars[0] = 100;
	vars[1] = 100;
	vars[2] = 1;
	vars[3] = 10;
	vars[4] = 1;
	return (vars);
}
