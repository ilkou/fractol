/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:49:40 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 19:16:12 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static	t_complex	ft_specific_julia(int choix, t_ptr *p)
{
	if (choix == 1)
		return (ft_create_complex(0.3, 0.5));
	else if (choix == 2)
		return (ft_create_complex(0.285, 0.01));
	else if (choix == 3)
		return (ft_create_complex(-1.417022285618, 0.0099534));
	else if (choix == 4)
		return (ft_create_complex(-0.038088, 0.9754633));
	else if (choix == 5)
		return (ft_create_complex(-0.4, 0.6));
	else if (choix == 6)
		return (ft_create_complex(-1.476, 0.0));
	else if (choix == 7)
		return (ft_create_complex(-0.8, 0.156));
	else if (choix == 8)
		return (ft_create_complex(-0.75, 0.145));
	else
		return (ft_create_complex(p->seed.x, p->seed.y));
}

double				ft_julia(t_ptr *p, double col, double row)
{
	double		iteration;
	t_complex	z;
	t_complex	c;

	iteration = 0.0;
	set_coordinate(&z, p, col, row);
	c = ft_specific_julia(p->julia_type, p);
	while (z.re * z.re + z.im * z.im <= 4 && iteration < p->max_iter)
	{
		ft_power_complex(&z, &c, 2);
		iteration += 1;
	}
	return (iteration);
}
