/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:11:59 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/12 23:03:28 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"


void coord_to_line(int xi,int yi,int xf,int yf) 
{
	void *mlx;
	void *win;
	int x;
	int y;
	float a;
	float b;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");

	a =(float) (yf-yi)/(xf-xi) ;
	b = yi - a * xi;
	x = xi;
	while(x <= xf)
	{
		y =(int) (a * x + b);
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
}

int			main()
{
	void *mlx;
	void *win;
	int x;
	int y;

//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 400, 400, "mlx 42");

	coord_to_line(0, -100, 0, 100);
	/*
	void ligne(int xi,int yi,int xf,int yf) {
		int x,y ;
		float a,b ;
		a =(float) (yf-yi)/(xf-xi) ;
		b = yi - a * xi ;
		for ( x = xi ; x <= xf ; x++ ) {
			y =(int) (a * x + b) ;
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		}
	}

	y = 50;
			while (y < 150)
			{
			x = 50;
			while (x < 150)
			{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
			}
			y++;
			}
			*/
	mlx_loop(mlx);
	return (0);
}

