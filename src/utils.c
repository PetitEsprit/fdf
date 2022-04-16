/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:13:07 by user              #+#    #+#             */
/*   Updated: 2022/04/16 22:16:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "init.h"
#include "utils.h"
#include "libft.h"
#include <stdio.h>

void	cart_to_iso(t_data *data);

void	zoom(t_data *data, float factor)
{
	data->scale *= factor;
	cart_to_iso(data);
}

void	translate(t_data *data, t_point delta)
{
	int	j;
	int	i;

	data->offset.x += delta.x;
	data->offset.y += delta.y;
	j = 0;
	while (j < data->rows)
	{
		i = 0;
		while (i < data->cols)
		{
			data->map[j][i].x += delta.x;
			data->map[j][i].y += delta.y;
			++i;
		}
		++j;
	}
}

int	key_event(int keycode, t_data *data)
{
	t_point	delta;

	ft_bzero(&delta, sizeof(delta));
	if (keycode == XK_Escape)
	{
		free_data(data);
		return (0);
	}
	if (keycode >= XK_Left && keycode <= XK_Down)
	{
		delta.x += (keycode == XK_Left) * -50 + (keycode == XK_Right) * 50;
		delta.y += (keycode == XK_Up) * -50 + (keycode == XK_Down) * 50;
		translate(data, delta);
	}
	if (keycode == XK_p)
		zoom(data, 1.50);
	else if (keycode == XK_m)
		zoom(data, 0.50);
	return (0);
}

int	mouse_event(t_data *data)
{
	free_data(data);
	return (0);
}

void	img_pixel_put(t_img *frame, int x, int y, int color)
{
	char	*dst;

	if (0 > x || x > frame->width || 0 > y || y > frame->height)
		return ;
	dst = frame->buff + (y * frame->line_len + x * (frame->bpp / 8));
	*(unsigned int *)dst = color;
}
