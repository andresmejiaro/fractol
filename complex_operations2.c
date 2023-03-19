/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:36 by amejia            #+#    #+#             */
/*   Updated: 2023/03/19 19:21:38 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx cplx_inv(t_cplx a)
{
	t_cplx result;
	
	
	if (cplx_norm2(a) == 0)
		return (a);
	
	result = cplx_conj(a);
	result.re = result.re /cplx_norm2(a);
	result.im = result.im /cplx_norm2(a);
	return(result);
}
