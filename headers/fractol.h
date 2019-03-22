/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:43:33 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 19:59:55 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "fractol_struct.h"

double		ft_julia(t_ptr *p, double col, double row);
double		ft_mandelbrot(t_ptr *p, double col, double row);
double		ft_tricorne(t_ptr *p, double col, double row);
double		ft_negatibrot(t_ptr *p, double col, double row);
double		ft_monsieur(t_ptr *p, double col, double row);
double		ft_burningship(t_ptr *p, double col, double row);
double		interpolate(double start, double end, double interpolation);
void		zoom(t_ptr *ptr, double x, double y, double k);
void		set_coordinate(t_complex *z, t_ptr *p, double col, double row);
void		ft_power_complex(t_complex *z, t_complex *c, int power);
t_complex	ft_create_complex(double a, double b);
void		ft_mlx_putpixel(t_ptr *p, int x, int y, int color);
int			wrong_parameters(char **argv);
void		disp_help(void);
void		disp_usage(void);
void		ft_creat_window(t_ptr *p);
void		ft_creat_image(t_ptr *p);
void		*ft_calcul(t_thread *p);
void		ft_begin(t_ptr *p);
void		ft_draw(t_ptr *p);
int			ft_switch(int key, t_ptr *p);
void		ft_move(int key, t_ptr *p);
int			ft_deal_key(int key, t_ptr *p);
int			ft_mouse_press(int button, int x, int y, t_ptr *p);
int			ft_mouse_move(int x, int y, t_ptr *p);
void		choose_fractale(char **argv, t_ptr *p);
void		ft_init_switch(t_ptr **p);
void		ft_init(t_ptr **p, char **argv);

#endif
