/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:59:46 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/16 17:04:37 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>

#define SCREEN_W 2000
#define SCREEN_H 1200

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
	float		const1;
	float		const2;
	int			totlen;
	int			xlen;
	int			xc;
	int			yc;
}				t_vars;

char	*ft_file_to_str(char *file, int *xlen);
int		*ft_set_vars();
t_coord		**ft_str_to_grid(t_vars *e, char **grid);
void print_line(t_vars *e, t_coord *first, t_coord *last);

#endif
