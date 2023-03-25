/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:48:23 by amejia            #+#    #+#             */
/*   Updated: 2023/03/25 12:02:00 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	wclose(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win);
		exit(0);
	}
	else if (keycode == 126)
		bag->center.im += 1 / bag->zoom;	
	else if (keycode == 125)
		bag->center.im -= 1 / bag->zoom;	
	else if (keycode == 123)
		bag->center.re += 1 / bag->zoom;	
	else if (keycode == 124)
		bag->center.re -= 1 / bag->zoom;
	else if (keycode == 36)
	{
		bag->center.re = 0;
		bag->center.im = 0;
		bag->zoom = 1;		
	}	
	else
		printf("%d\n",keycode);
	if ((keycode >=123 && keycode <=126) || keycode == 36)
		mandelbrot(bag->img,bag->zoom,bag->center);
	mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
	return (0);
}

int	mouse(int keycode,int x,int y, t_bag *bag)
{
	t_cplx coords;

	if(keycode ==1)
	{
		coords.re = (4*(x-256))/(bag->zoom*512) -  bag->center.re;
		coords.im = (4*(y-256))/(bag->zoom*512) -  bag->center.im;
		printf("window coords:%d,%d\n",x,y);
		printf("complex coords:%f,%f\n",coords.re,coords.im);
		printf("zomm: %f,center:%f,%f\n",bag->zoom,bag->center.re,bag->center.im);
		bag->parameterJulia = coords;
		julia(bag->imgJulia,bag->zoomJulia,bag->centerJulia,bag->parameterJulia);
		mlx_put_image_to_window(bag->mlx, bag->win2, bag->imgJulia.img, 0, 0);

	}
	if(keycode ==2)
	{
		coords.re = (4*(x-256))/(bag->zoom*512) -  bag->center.re;
		coords.im = (4*(y-256))/(bag->zoom*512) -  bag->center.im;
		printf("window coords:%d,%d\n",x,y);
		printf("complex coords:%f,%f\n",coords.re,coords.im);
		printf("zomm: %f,center:%f,%f\n",bag->zoom,bag->center.re,bag->center.im);
		bag->parameterCubic = coords;
		cubic(bag->imgCubic,bag->zoomCubic,bag->centerCubic,bag->parameterCubic);
		mlx_put_image_to_window(bag->mlx, bag->win3, bag->imgCubic.img, 0, 0);

	}
	else if (keycode == 5)
	{
		float scale_factor = 1.5 / bag->zoom / (512/4);
		float delta_re = (x - 256) * scale_factor;
		float delta_im = (y - 256) * scale_factor;
		bag->center.re -= delta_re;
		bag->center.im -= delta_im;
		bag->zoom *= 1.5;
	}
	else if (keycode == 4)
	{
		bag->center.re = bag->center.re - ((x-256)/bag->zoom)/(512/4);
		bag->center.im = bag->center.im - ((y-256)/bag->zoom)/(512/4);
		bag->zoom /= 1.5;
	}
	if (keycode == 4 || keycode ==5)
	{
		mandelbrot(bag->img,bag->zoom,bag->center);
		mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
	}
	return (0 * bag->center.im * keycode *x * y);
}


int	mousecubic(int keycode,int x,int y, t_bag *bag)
{
	t_cplx coords;

	if(keycode ==1)
	{
		coords.re = (4*(x-256))/(bag->zoom*512) -  bag->center.re;
		coords.im = (4*(y-256))/(bag->zoom*512) -  bag->center.im;
		printf("window coords:%d,%d\n",x,y);
		printf("complex coords:%f,%f\n",coords.re,coords.im);
		printf("zomm: %f,center:%f,%f\n",bag->zoomCubic,bag->centerCubic.re,bag->centerCubic.im);
	}
	if (keycode == 5)
	{
		float scale_factor = 1.5 / bag->zoomCubic / (512/4);
		float delta_re = (x - 256) * scale_factor;
		float delta_im = (y - 256) * scale_factor;
		bag->centerCubic.re -= delta_re;
		bag->centerCubic.im -= delta_im;
		bag->zoomCubic *= 1.5;
	}
	else if (keycode == 4)
	{
		bag->centerCubic.re = bag->centerCubic.re - ((x-256)/bag->zoom)/(512/4);
		bag->centerCubic.im = bag->centerCubic.im - ((y-256)/bag->zoom)/(512/4);
		bag->zoomCubic /= 1.5;
	}
	if (keycode == 4 || keycode ==5)
	{
		cubic(bag->imgCubic,bag->zoomCubic,bag->centerCubic,bag->parameterCubic);
		mlx_put_image_to_window(bag->mlx, bag->win3, bag->imgCubic.img, 0, 0);
	}
	return (0);
}

int	mousejulia(int keycode,int x,int y, t_bag *bag)
{
	t_cplx coords;

	if(keycode ==1)
	{
		coords.re = (4*(x-256))/(bag->zoom*512) -  bag->center.re;
		coords.im = (4*(y-256))/(bag->zoom*512) -  bag->center.im;
		printf("window coords:%d,%d\n",x,y);
		printf("complex coords:%f,%f\n",coords.re,coords.im);
		printf("zomm: %f,center:%f,%f\n",bag->zoom,bag->center.re,bag->center.im);
	}
	if (keycode == 5)
	{
		float scale_factor = 1.5 / bag->zoomJulia / (512/4);
		float delta_re = (x - 256) * scale_factor;
		float delta_im = (y - 256) * scale_factor;
		bag->centerJulia.re -= delta_re;
		bag->centerJulia.im -= delta_im;
		bag->zoomJulia *= 1.5;
	}
	else if (keycode == 4)
	{
		bag->centerJulia.re = bag->centerJulia.re - ((x-256)/bag->zoom)/(512/4);
		bag->centerJulia.im = bag->centerJulia.im - ((y-256)/bag->zoom)/(512/4);
		bag->zoomJulia /= 1.5;
	}
	if (keycode == 4 || keycode ==5)
	{
		julia(bag->imgJulia,bag->zoomJulia,bag->centerJulia,bag->parameterJulia);
		mlx_put_image_to_window(bag->mlx, bag->win2, bag->imgJulia.img, 0, 0);
	}
	return (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

int		red_cross(void)
{
	exit(0);
	return (0);
} 

int	juliakey(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win2);
		exit(0);
	}
	else if (keycode == 126)
		bag->centerJulia.im += 1/bag->zoomJulia;	
	else if (keycode == 125)
		bag->centerJulia.im -= 1/bag->zoomJulia;	
	else if (keycode == 123)
		bag->centerJulia.re += 1/bag->zoomJulia;	
	else if (keycode == 124)
		bag->centerJulia.re -= 1/bag->zoomJulia;
	else if (keycode == 36)
	{
		bag->centerJulia.re = 0;
		bag->centerJulia.im = 0;
		bag->zoomJulia = 1;		
	}	
	else
		printf("%d\n",keycode);
	if ((keycode >=123 && keycode <=126) || keycode == 36)
		julia(bag->imgJulia,bag->zoomJulia,bag->centerJulia,bag->parameterJulia);
	mlx_put_image_to_window(bag->mlx, bag->win2, bag->imgJulia.img, 0, 0);
	return (0);
}

int	cubickey(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win2);
		exit(0);
	}
	else if (keycode == 126)
		bag->centerCubic.im += 1/bag->zoomCubic;	
	else if (keycode == 125)
		bag->centerCubic.im -= 1/bag->zoomCubic;	
	else if (keycode == 123)
		bag->centerCubic.re += 1/bag->zoomCubic;	
	else if (keycode == 124)
		bag->centerCubic.re -= 1/bag->zoomCubic;
	else if (keycode == 36)
	{
		bag->centerCubic.re = 0;
		bag->centerCubic.im = 0;
		bag->zoomCubic = 1;		
	}	
	else
		printf("%d\n",keycode);
	if ((keycode >=123 && keycode <=126) || keycode == 36)
		cubic(bag->imgCubic,bag->zoomCubic,bag->centerCubic,bag->parameterCubic);
	mlx_put_image_to_window(bag->mlx, bag->win3, bag->imgCubic.img, 0, 0);
	return (0);
}