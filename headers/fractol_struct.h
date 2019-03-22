/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:43:33 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 22:20:45 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define WIN 1000.0

# define NBTHREAD 4

# define MLX_KEY_PAD_LEFT 123
# define MLX_KEY_PAD_RIGHT 124
# define MLX_KEY_PAD_UP 126
# define MLX_KEY_PAD_DOWN 125
# define MLX_KEY_PAD_ESC 53
# define MLX_KEY_PAD_J 38
# define MLX_KEY_PAD_M 46
# define MLX_KEY_PAD_T 17
# define MLX_KEY_PAD_N 45
# define MLX_KEY_PAD_R 15
# define MLX_KEY_PAD_B 11
# define MLX_KEY_PAD_S 1
# define MLX_KEY_PAD_X 7
# define MLX_KEY_PAD_MINUS 78
# define MLX_KEY_PAD_PLUS 69
# define MLX_KEY_PAD_SPACE 49

# define POWER_2 -2
# define POWER2 2
# define POWER_3 -3
# define POWER3 3

# define B_ABS(x) { x = x > 0 ? x : -x; }

typedef	struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_color
{
	int			a;
	int			b;
}				t_color;

typedef struct	s_ptr
{
	void		*win;
	void		*mlx;
	void		*img;
	int			*data;
	int			*bpp;
	int			*size;
	int			*endian;
	int			stop;
	int			julia_type;
	int			tricorne_type;
	int			mandelbrot_type;
	int			color;
	t_point		seed;
	double		zoom;
	double		x1_max;
	double		x1_min;
	double		x2_max;
	double		x2_min;
	double		max_iter;
	double		(*type)(struct s_ptr *p, double col, double row);
}				t_ptr;

typedef struct	s_thread
{
	int			i;
	t_ptr		*e;
}				t_thread;

#endif
