/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:38:58 by amejia            #+#    #+#             */
/*   Updated: 2023/03/28 17:37:26 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bag_init(t_bag *bag)
{
	bag->center.re = 0;
	bag->center.im = 0;
	bag->zoom = 1;
	bag->zoom_julia = 1;
	bag->zoom_cubic = 1;
	bag->parameter_julia = bag->center;
	bag->parameter_cubic = bag->center;
	bag->center_julia = bag->center;
	bag->center_cubic = bag->center;
	bag->mlx = mlx_init();
	bag->win = mlx_new_window(bag->mlx, 512, 512, "Mandelbrot");
	bag->win2 = mlx_new_window(bag->mlx, 512, 512, "Julia");
	bag->win3 = mlx_new_window(bag->mlx, 512, 512, "Cubic");
	bag->img.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img_julia.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img_cubic.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img.addr = mlx_get_data_addr(bag->img.img, &(bag->img.bits_per_pixel), \
		&(bag->img.line_length), &(bag->img.endian));
	bag->img_julia.addr = mlx_get_data_addr(bag->img_julia.img, \
		&(bag->img_julia.bits_per_pixel), &(bag->img_julia.line_length), \
		&(bag->img_julia.endian));
	bag->img_cubic.addr = mlx_get_data_addr(bag->img_cubic.img, \
		&(bag->img_cubic.bits_per_pixel), &(bag->img_cubic.line_length), \
		&(bag->img_cubic.endian));
}

void	windows_init(t_bag *bag)
{
	mandelbrot(bag->img, bag->zoom, bag->center);
	julia(bag->img_julia, bag->zoom_julia, bag->center_julia, \
		bag->parameter_julia);
	cubic(bag->img_cubic, bag->zoom_cubic, bag->center_cubic, \
		bag->parameter_cubic);
	mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
	mlx_put_image_to_window(bag->mlx, bag->win2, bag->img_julia.img, 0, 0);
	mlx_put_image_to_window(bag->mlx, bag->win3, bag->img_cubic.img, 0, 0);
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
