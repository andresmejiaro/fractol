/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:44:48 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 21:57:41 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_parameter_menu(void)
{
	printf("Usage: ./fractol fractal_type (parameter.re paramater.in)\n");
	printf("Non numeric parameters are mapped to zero\n");
	printf("Fractal Types:\n");
	printf("mandelbrot:	generates the maldelbrol set, requieres no");
	printf(" parameters (any parameters are ignored).\n");
	printf("julia: 		generates the julia set of the function z^2 + c, if ");
	printf("no parameter is given it is considered 0.\n");
	printf("cubic:		generates the julia set of z^3 + c * z + 1");
	printf(" if no parameter is given it is considered 0.\n");
	printf("newton:		generates the newton fractal of the function z^3 - 1");
	printf(" any parameters are ignored.\n");
	printf("party:		generates all of the above, when clicking in the");
	printf(" mandelbrot set with right or left click changes the parameter of");
	printf(" the julia and cubic fractals.\n");
	exit(EXIT_SUCCESS);
}

t_cplx	parameter_reader(int argc, char **argv)
{
	if (argc != 4)
		return (cplx_init(0, 0));
	return (cplx_init(ft_atof(argv[2]), ft_atof(argv[3])));
}

void	window_launcher(int argc, char **argv, t_bag *bag)
{
	t_cplx	parameter;

	if (argc == 1 || argc == 3 || argc >= 5)
		error_parameter_menu();
	parameter = parameter_reader(argc, argv);
	if (ft_strncmp(argv[1], "mandelbrot", -1) == 0)
		bag->mode = 0;
	else if (ft_strncmp(argv[1], "julia", -1) == 0)
	{
		bag->mode = 1;
		bag->parameter_julia = parameter;
	}
	else if (ft_strncmp(argv[1], "cubic", -1) == 0)
	{
		bag->mode = 2;
		bag->parameter_cubic = parameter;
	}
	else if (ft_strncmp(argv[1], "newton", -1) == 0)
		bag->mode = 3;
	else if (ft_strncmp(argv[1], "party", -1) == 0)
		bag->mode = 4;
	else
		error_parameter_menu();
	windows_init(bag);
}
