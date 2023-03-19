/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_polinomials.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:18:35 by amejia            #+#    #+#             */
/*   Updated: 2023/03/20 00:01:34 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//the complex numbers should be passed as pointers
t_list *cplx_poly_create(unsigned int grade, ...)
{
	va_list va_ptr;
	unsigned int ct;
	t_list *poly;
	t_cplx *temp;
	t_cplx num;

	poly = NULL;	
	va_start(va_ptr, grade);
	ct = 0;
	while (ct < grade + 1)
	{
		num = va_arg(va_ptr,t_cplx);
		temp = (t_cplx *)ft_calloc(1,sizeof(t_cplx));
		temp->re = num.re;
		temp->im = num.im;
		ft_lstadd_back(&poly,ft_lstnew(temp));
		ct++;
	}
	return poly;
}


t_cplx cplx_poly_eval(t_list *poly, t_cplx nbr)
{
	int ct;
	t_cplx result;

	ct = 0;
	result.re = 0;
	result.im = 0;
	while(poly != NULL)
	{
		result = cplx_add(result,cplx_mult(*((t_cplx *)(poly->content)), \
			cplx_pow(nbr,ct)));
		ct++;
		poly = poly->next;
	}
	return (result);
}

int cplx_point_orbit_cvg(t_list *poly, t_cplx nbr)
{
	int ct;

	ct = 0;
	while (ct < 500)
	{
		nbr = cplx_poly_eval(poly, nbr);
		if (cplx_norm2(nbr) > 100)
			return (ct); 
		ct++;
	}
	return (0);
}

