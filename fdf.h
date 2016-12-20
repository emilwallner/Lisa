/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:59:46 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/20 16:05:12 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
#include "mlx.h"

#define SCREEN 1700

typedef struct	s_coord {
	int			x;
	int			xp;
	int			y;
	int			yp;
	int			h;
	int			hp;
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_coord;

typedef struct s_line {
	int dx;
	int dy;
	int i;
	int	f;
	int	incx;
	int	incy;
	int	inc1;
	int	inc2;
	int x;
	int y;
}				t_line;

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
	int			coloron;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned int color;
}				t_vars;

void	clean_and_launch(t_vars *e);
int		zoom_that_shit(int keycode, t_vars *e);
void	create_trip(t_vars *e);
void	adjust_vars(t_vars *e);
void	increase_const_one(int keycode, t_vars *e);
void	increase_depth(int keycode, t_vars *e);
void	increase_const_two(int keycode, t_vars *e);
void	move_me_in(int keycode, t_vars *e);
void	print_cords(t_vars *e);
void	move_me_upndown(int keycode, t_vars	*e);
void	move_me_leftnright(int keycode, t_vars *e);
char	*ft_file_to_str(char *file, int *xlen);
void	ft_set_vars(t_vars *e);
t_coord		**ft_str_to_grid(t_vars *e, char **grid);
void print_line(t_vars *e, t_coord *first, t_coord *last);

#endif
