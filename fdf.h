/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:59:46 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/15 17:31:39 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>

typedef struct	s_coord {
	int			x;
	int			y;
	int			h;
}				t_coord;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_coord		**print;
	int			depth;
	int			zoom;
	int			xc;
	int			yc;
}				t_vars;

char	*ft_file_to_str(char *file, int *xlen);
int		*ft_set_vars();
t_coord		**ft_str_to_grid(char **str, int *vars, int xlen);

#endif
