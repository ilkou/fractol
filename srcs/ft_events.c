/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:06:06 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 21:36:54 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int			ft_switch(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_J)
	{
		if (p->type == ft_julia)
			p->julia_type = p->julia_type < 8 ? p->julia_type + 1 : 0;
		p->type = ft_julia;
	}
	if (key == MLX_KEY_PAD_M)
	{
		if (p->type == ft_mandelbrot)
			p->mandelbrot_type = p->mandelbrot_type == 2 ? 3 : 2;
		p->type = ft_mandelbrot;
	}
	if (key == MLX_KEY_PAD_N)
		p->type = ft_negatibrot;
	if (key == MLX_KEY_PAD_T)
	{
		if (p->type == ft_tricorne)
			p->tricorne_type = p->tricorne_type == -2 ? -3 : -2;
		p->type = ft_tricorne;
	}
	if (key == MLX_KEY_PAD_B)
		p->type = ft_burningship;
	if (key == MLX_KEY_PAD_X)
		p->type = ft_monsieur;
	return (key == 11 || key == 17 || key == 45 || key == 46 || key == 38);
}

void		ft_move(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_LEFT)
	{
		p->x1_min += 0.05 * p->zoom;
		p->x1_max += 0.05 * p->zoom;
	}
	if (key == MLX_KEY_PAD_RIGHT)
	{
		p->x1_min -= 0.05 * p->zoom;
		p->x1_max -= 0.05 * p->zoom;
	}
	if (key == MLX_KEY_PAD_UP)
	{
		p->x2_min += 0.05 * p->zoom;
		p->x2_max += 0.05 * p->zoom;
	}
	if (key == MLX_KEY_PAD_DOWN)
	{
		p->x2_min -= 0.05 * p->zoom;
		p->x2_max -= 0.05 * p->zoom;
	}
}

int			ft_deal_key(int key, t_ptr *p)
{
	if (key == MLX_KEY_PAD_ESC)
		ft_close(p);
	if (key == MLX_KEY_PAD_S)
		p->stop = p->stop == 1 ? 0 : 1;
	if (key == MLX_KEY_PAD_PLUS)
		p->max_iter += 10.0;
	if (key == MLX_KEY_PAD_MINUS)
		p->max_iter -= 10.0;
	ft_move(key, p);
	if (ft_switch(key, p) || key == 15 || key == 7)
		ft_init_switch(&p);
	if (key == MLX_KEY_PAD_SPACE)
		p->color = p->color < 7 ? p->color + 1 : 0;
	ft_draw(p);
	return (key);
}

int			ft_mouse_press(int button, int x, int y, t_ptr *p)
{
	if (button == 5)
	{
		zoom(p, x, y, 0.8);
		p->zoom /= 1.2;
	}
	if (button == 4)
	{
		zoom(p, x, y, 1.0 / 0.8);
		p->zoom *= 1.2;
	}
	ft_draw(p);
	return (0);
}

int			ft_mouse_move(int x, int y, t_ptr *p)
{
	if (p->type == ft_julia && p->stop == 0)
	{
		p->seed.x = x / (double)(WIN);
		p->seed.y = y / (double)(WIN);
		ft_draw(p);
	}
	return (0);
}
