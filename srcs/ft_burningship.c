/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:02:46 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 19:08:43 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	ft_burningship(t_ptr *p, double col, double row)
{
	double		iteration;
	t_complex	c;
	t_complex	z;

	iteration = 0.0;
	z = ft_create_complex(0, 0);
	set_coordinate(&c, p, col, row);
	while (z.re * z.re + z.im * z.im <= 4 && iteration < p->max_iter)
	{
		B_ABS(z.re);
		B_ABS(z.im);
		ft_power_complex(&z, &c, 2);
		iteration += 1;
	}
	return (iteration);
}
