/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:30 by amejia            #+#    #+#             */
/*   Updated: 2023/03/19 23:44:59 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <stdarg.h>
# include <mlx.h>

typedef struct s_complex_number{
	float re;
	float im;
} t_cplx;

t_cplx cplx_mult(t_cplx a,t_cplx b);
t_cplx cplx_add(t_cplx a,t_cplx b);
float cplx_norm2(t_cplx a);
t_cplx cplx_conj(t_cplx a);
t_cplx cplx_inv(t_cplx a);
t_cplx cplx_pow(t_cplx a, int n);
t_list *cplx_poly_create(unsigned int grade, ...);
t_cplx cplx_poly_eval(t_list *poly, t_cplx nbr);
int cplx_point_orbit_cvg(t_list *poly, t_cplx nbr);


#endif