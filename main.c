/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:38:58 by amejia            #+#    #+#             */
/*   Updated: 2023/03/25 17:40:22 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bag_init(t_bag *bag)
{
	bag->center.re = 0;
	bag->center.im = 0;
	bag->zoom = 1;
	bag->zoomJulia = 1;
	bag->zoomCubic = 1;
	bag->parameterJulia = bag->center;
	bag->parameterCubic = bag->center;
	bag->centerJulia = bag->center;
	bag->centerCubic = bag->center;
	bag->mlx = mlx_init();
	bag->win = mlx_new_window(bag->mlx, 512, 512, "Mandelbrot");
	bag->win2 = mlx_new_window(bag->mlx, 512, 512, "Julia");
	bag->win3 = mlx_new_window(bag->mlx, 512, 512, "Cubic");
	bag->img.img = mlx_new_image(bag->mlx, 512, 512);
	bag->imgJulia.img = mlx_new_image(bag->mlx, 512, 512);
	bag->imgCubic.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img.addr = mlx_get_data_addr(bag->img.img, &(bag->img.bits_per_pixel), \
		&(bag->img.line_length), &(bag->img.endian));
	bag->imgJulia.addr = mlx_get_data_addr(bag->imgJulia.img, \
		&(bag->imgJulia.bits_per_pixel), &(bag->imgJulia.line_length), \
		&(bag->imgJulia.endian));
	bag->imgCubic.addr = mlx_get_data_addr(bag->imgCubic.img, \
		&(bag->imgCubic.bits_per_pixel), &(bag->imgCubic.line_length), \
		&(bag->imgCubic.endian));
}

void	windows_init(t_bag *bag)
{
	mandelbrot(bag->img, bag->zoom, bag->center);
	julia(bag->imgJulia, bag->zoomJulia, bag->centerJulia, bag->parameterJulia);
	cubic(bag->imgCubic, bag->zoomCubic, bag->centerCubic, bag->parameterCubic);
	mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
	mlx_put_image_to_window(bag->mlx, bag->win2, bag->imgJulia.img, 0, 0);
	mlx_put_image_to_window(bag->mlx, bag->win3, bag->imgCubic.img, 0, 0);
	mlx_hook(bag->win, 2, 0, wclose, bag);
	mlx_hook(bag->win2, 2, 0, juliakey, bag);
	mlx_hook(bag->win3, 2, 0, cubickey, bag);
	mlx_hook(bag->win, 4, 0, mouse, bag);
	mlx_hook(bag->win2, 4, 0, mousejulia, bag);
	mlx_hook(bag->win3, 4, 0, mousecubic, bag);
	mlx_hook(bag->win, 17, 0L, red_cross, bag);
	mlx_hook(bag->win2, 17, 0L, red_cross, bag);
	mlx_hook(bag->win3, 17, 0L, red_cross, bag);
	mlx_loop(bag->mlx);
}

void	leaks(void)
{
	system("leaks -q fractol");
}

int	main(void)
{
	t_bag	bag;

	if (DEBUG == 1)
		atexit(leaks);
	bag_init(&bag);
	windows_init(&bag);
	return (0);
}
