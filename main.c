/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:38:58 by amejia            #+#    #+#             */
/*   Updated: 2023/03/20 00:08:19 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;		
	t_cplx nbs[4];
	t_list *poly;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	nbs[0].re = 0;
	nbs[0].im = 0;
	nbs[1].re = 1;
	nbs[1].im = 0;
	int x = 0;
	int y = 0;
	int n;
	while (++x<1920)
	{
		y=0;
		while (++y<1080)
		{
			nbs[2].re = (float)x/1080/75;
			nbs[2].im = (float)y/1080/75;
			poly = cplx_poly_create(2,nbs[2],nbs[1],nbs[0]);
			n=cplx_point_orbit_cvg(poly,nbs[0]);
			printf("%d\n",n);
			my_mlx_pixel_put(&img, x, y, n);
		}
	
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}