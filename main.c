/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:37:07 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/03 23:38:55 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void    ft_mlx_putpixel(t_ptr *p, int x, int y, int color)
{
    if (x >= 0 && x < WIN_WIDTH
        && y >= 0 && y < WIN_HEIGHT)
    {
        p->data[y * WIN_WIDTH + x] = color;
    }
}

void	choose_fractale(char **argv, t_ptr *p)
{
	int		i;

	i = 1;
	while (argv[i])
	{
        if (ft_strcmp(argv[i], "julia") == 0)
            p->type.julia = 1;
        if (ft_strcmp(argv[i], "mandelbrot") == 0)
            p->type.mandelbrot= 1;
        if (ft_strcmp(argv[i], "newton") == 0)
            p->type.newton = 1;
		i++;
	}
}

int		wrong_parameters(int argc, char **argv)
{
	int		i;
	int		check;

	i = 1;
	check = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "julia") || !ft_strcmp(argv[i], "mandelbrot")
				|| !ft_strcmp(argv[i], "newton"))
			check++;
		i++;
	}
	return (check != argc);
}

void	disp_usage(void)
{
	ft_putstr("Usage: ./fractol fractale\n");
	ft_putstr("       ./fractol [ julia | mandelbrot | newton ]\n");
}
void	init(t_ptr **p, char **argv)
{
	*p = (struct s_ptr*)malloc(sizeof(struct s_ptr));
    (*p)->type.julia = 0;
    (*p)->type.mandelbrot = 0;
    (*p)->type.newton = 0;
	choose_fractale(argv, *p);
    (*p)->img = NULL;
    (*p)->mlx = NULL;
    (*p)->data = NULL;
    (*p)->win = NULL;
    (*p)->bpp = malloc(4);
    (*p)->size = malloc(4);
    (*p)->endian = malloc(4);
    (*p)->zoom = 1.0;
    (*p)->xii = 0.1;
    (*p)->yii = 0.1;
    (*p)->stop = 0;
    (*p)->max_iter = 500.0;
}
void ft_creat_window(t_ptr *p)
{
    p->mlx = mlx_init();
    p->win = mlx_new_window(p->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
}
void ft_creat_image(t_ptr *p)
{
    p->img = mlx_new_image(p->mlx, WIN_WIDTH, WIN_HEIGHT);
    p->data = (int*)mlx_get_data_addr(p->img, p->bpp, p->size, p->endian);
}
void ft_draw_mandelbrot_a(t_ptr *p)
{
    double c_re;
    double c_im;
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = 0; row < WIN_HEIGHT / 2; row++)
    {
        for (int col = 0; col < WIN_WIDTH / 2; col++)
        {
            c_re = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH * p->zoom;
            c_im = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT * p->zoom;
            x = 0;
            y = 0;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + c_re;
                y = 2*x*y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0000FF * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x000000 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_mandelbrot_b(t_ptr *p)
{
    double c_re;
    double c_im;
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = 0; row < WIN_HEIGHT; row++)
    {
        for (int col = WIN_WIDTH / 2; col < WIN_WIDTH; col++)
        {
            c_re = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH * p->zoom;
            c_im = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT * p->zoom;
            x = 0;
            y = 0;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + c_re;
                y = 2*x*y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0000FF * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x000000 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_mandelbrot_c(t_ptr *p)
{
    double c_re;
    double c_im;
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = WIN_HEIGHT/2; row < WIN_HEIGHT; row++)
    {
        for (int col = 0; col < WIN_WIDTH; col++)
        {
            c_re = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH * p->zoom;
            c_im = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT * p->zoom;
            x = 0;
            y = 0;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + c_re;
                y = 2*x*y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0000FF * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x000000 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_mandelbrot_d(t_ptr *p)
{
    double c_re;
    double c_im;
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = WIN_HEIGHT / 2; row < WIN_HEIGHT; row++)
    {
        for (int col = WIN_WIDTH / 2; col < WIN_WIDTH; col++)
        {
            c_re = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH * p->zoom;
            c_im = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT * p->zoom;
            x = 0;
            y = 0;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + c_re;
                y = 2*x*y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0000FF * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x000000 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_julia_a(t_ptr *p)
{
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = 0; row < WIN_HEIGHT / 2; row++)
    {
        for (int col = 0; col < WIN_WIDTH / 2; col++)
        {
            x = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH;
            y = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + p->xii;
                y = 2*x*y + p->yii;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0FF00F * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x0F00F0 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_julia_b(t_ptr *p)
{
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = 0; row < WIN_HEIGHT; row++)
    {
        for (int col = WIN_WIDTH / 2; col < WIN_WIDTH; col++)
        {
            x = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH;
            y = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + p->xii;
                y = 2*x*y + p->yii;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0FF00F * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x0F00F0 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_julia_c(t_ptr *p)
{
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = WIN_HEIGHT/2; row < WIN_HEIGHT; row++)
    {
        for (int col = 0; col < WIN_WIDTH; col++)
        {
            x = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH;
            y = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + p->xii;
                y = 2*x*y + p->yii;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x0FF00F * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x0F00F0 * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_julia_d(t_ptr *p)
{
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = WIN_HEIGHT / 2; row < WIN_HEIGHT; row++)
    {
        for (int col = WIN_WIDTH / 2; col < WIN_WIDTH; col++)
        {
            x = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH;
            y = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x - y*y + p->xii;
                y = 2*x*y + p->yii;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x00FF00 * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x0000FF * iteration/2.003);
        }
    }
    pthread_exit(NULL);
}
void ft_draw_mandelbrot(t_ptr *p)
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_create(&thread1, NULL, (void*)ft_draw_mandelbrot_a, (void *)p);
    pthread_create(&thread2, NULL, (void*)ft_draw_mandelbrot_b, (void *)p);
    pthread_create(&thread3, NULL, (void*)ft_draw_mandelbrot_c, (void *)p);
    pthread_create(&thread4, NULL, (void*)ft_draw_mandelbrot_d, (void *)p);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
}
void ft_draw_julia(t_ptr *p)
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    pthread_create(&thread1, NULL, (void*)ft_draw_julia_a, (void *)p);
    pthread_create(&thread2, NULL, (void*)ft_draw_julia_b, (void *)p);
    pthread_create(&thread3, NULL, (void*)ft_draw_julia_c, (void *)p);
    pthread_create(&thread4, NULL, (void*)ft_draw_julia_d, (void *)p);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
}
/*void ft_draw_julia(t_ptr *p)
{
    double x;
    double y;
    int iteration;
    double x_new;
    for (int row = 0; row < WIN_HEIGHT; row++)
    {
        for (int col = 0; col < WIN_WIDTH; col++)
        {
            x = (col - WIN_WIDTH / 2.0) * 4.0/WIN_WIDTH;
            y = (row - WIN_HEIGHT / 2.0) * 4.0/WIN_HEIGHT;
            iteration = 0;
            while (x*x+y*y <= 4 && (double)iteration < p->max_iter)
            {
                x_new = x*x*x - 3*x*y*y -0.123 + p->xii;
                y = 3*x*x*y - y*y*y +0.745+p->yii;
                x = x_new;
                iteration++;
            }
            if (iteration < p->max_iter)
                ft_mlx_putpixel(p, col, row, 0x00FF00 * iteration/2.003);
            else
                ft_mlx_putpixel(p, col, row, 0x0000FF * iteration/2.003);
        }
    }
}*/
void ft_draw(t_ptr *p)
{
    ft_bzero(p->data, WIN_WIDTH * WIN_HEIGHT * 4);
    if (p->type.julia == 1)
        ft_draw_julia(p);
    else if (p->type.mandelbrot == 1)
        ft_draw_mandelbrot(p);
    mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
int        ft_deal_key(int key, t_ptr *p)
{
    if (key == MLX_KEY_PAD_ESC)
    {
        mlx_destroy_image(p->mlx, p->img);
        mlx_destroy_window(p->mlx, p->win);
        free(p);
        exit(0);
    }
    if (key == 38)
    {
        p->type.julia = 1;
        p->type.newton = 0;
        p->type.mandelbrot = 0;
    }
    if (key == 46)
    {
        p->type.julia = 0;
        p->type.newton = 0;
        p->type.mandelbrot = 1;
    }
    if (key == 45)
    {
        p->type.julia = 0;
        p->type.newton = 1;
        p->type.mandelbrot = 0;
    }
    if (key == 1)
        p->stop = 1;
    if (key == 2)
        p->stop = 0;
    if (key == 34)
        p->max_iter += 10;
    if (key == 31)
        p->max_iter -= 10;
    ft_draw(p);
    return (key);
}
int ft_mouse_press(int button, int x, int y, t_ptr *p)
{
    if (button == 5)
        p->zoom /= 1.2;
    if (button == 4)
        p->zoom *= 1.2;
    if(0)
    {
        x = y;
    }
    ft_draw(p);
    return (0);
}
int        ft_mouse_move(int x, int y, t_ptr *p)
{
    if (p->type.julia == 1 && p->stop == 0)
    {
        p->xii = x/1100.0;
        p->yii = y/1100.0;
        ft_draw(p);
    }
    return (0);
}
int		main(int argc, char **argv)
{
	t_ptr *p;
	if (argc == 1 || argc >= 5 || wrong_parameters(argc, argv))
		disp_usage();
	init(&p, argv);
    ft_creat_window(p);
    ft_creat_image(p);
    
    ft_draw(p);
    mlx_hook(p->win, 2, 0, ft_deal_key, p);
    mlx_hook(p->win, 4, 0, ft_mouse_press, p);
    mlx_hook(p->win, 6, 0, ft_mouse_move, p);
    mlx_loop(p->mlx);
	return (0);
}
