/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:59:46 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/13 19:28:00 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>

char	*ft_file_to_str(char *file, int *xlen);
int		*ft_set_vars();
int		**ft_str_to_grid(char **str, int *vars, int xlen);
#endif