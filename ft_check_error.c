/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:36:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 17:20:25 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	ft_check_error(char *str)
{
	int		i;
	int		m;

	i = 0;
	while (str[i] != '\0')
	{
		m = 0;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != ' ')
				m = m + 1;
			if (str[i] != '-')
				m = m + 1;
			if (m == 2)
			{
				ft_putstr("Map error\n");
				free(str);
				exit(0);
			}
		}
		i++;
	}
}
