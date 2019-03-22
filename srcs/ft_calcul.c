/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:07:37 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 21:24:46 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

t_complex	ft_create_complex(double a, double b)
{
	t_complex	z;

	z.re = a;
	z.im = b;
	return (z);
}

void		ft_power_complex(t_complex *z, t_complex *c, int power)
{
	double		temp;

	if (power == POWER2)
	{
		temp = z->re * z->re - z->im * z->im + c->re;
		z->im = 2 * z->re * z->im + c->im;
		z->re = temp;
	}
	else if (power == POWER_2)
	{
		temp = z->re * z->re - z->im * z->im + c->re;
		z->im = -2 * z->re * z->im + c->im;
		z->re = temp;
	}
	temp = z->re * z->re * z->re - 3 * z->re * z->im * z->im + c->re;
	if (power == POWER3)
	{
		z->im = 3 * z->re * z->re * z->im - z->im * z->im * z->im + c->im;
		z->re = temp;
	}
	else if (power == POWER_3)
	{
		z->im = -3 * z->re * z->re * z->im + z->im * z->im * z->im + c->im;
		z->re = temp;
	}
}

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		zoom(t_ptr *p, double x, double y, double k)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = x / (WIN / (p->x1_max - p->x1_min)) + p->x1_min;
	mouse_im = y / (WIN / (p->x2_max - p->x2_min)) + p->x2_min;
	p->x1_min = interpolate(mouse_re, p->x1_min, k);
	p->x2_min = interpolate(mouse_im, p->x2_min, k);
	p->x1_max = interpolate(mouse_re, p->x1_max, k);
	p->x2_max = interpolate(mouse_im, p->x2_max, k);
}

void		set_coordinate(t_complex *z, t_ptr *p, double col, double row)
{
	z->re = p->x1_min + ((p->x1_max - p->x1_min) / WIN) * col;
	z->im = p->x2_min + ((p->x2_max - p->x2_min) / WIN) * row;
}
