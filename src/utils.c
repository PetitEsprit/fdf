/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:13:07 by user              #+#    #+#             */
/*   Updated: 2022/04/11 14:52:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "init.h"
#include "utils.h"

int	key_event(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		free_window(data);
	return (0);
}

int	mouse_event(t_data *data)
{
	free_window(data);
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

static void	render_line_calc(t_point *p1, t_point *d, t_point *s, int *error)
{
	int	e2;

	e2 = 2 * *error;
	if (e2 >= d->y)
	{
		*error = *error + d->y;
		p1->x = p1->x + s->x;
	}
	if (e2 <= d->x)
	{
		*error = *error + d->x;
		p1->y = p1->y + s->y;
	}
}

void	render_line(t_img *frame, t_point p1, t_point p2, int color)
{
	t_point	d;
	t_point	s;
	int		error;

	d.x = p2.x - p1.x;
	if (d.x < 0)
		d.x = -d.x;
	s.x = (p1.x < p2.x) * 1 + (p1.x >= p2.x) * -1;
	d.y = p2.y - p1.y;
	if (d.y > 0)
		d.y = -d.y;
	s.y = (p1.y < p2.y) * 1 + (p1.y >= p2.y) * -1;
	error = d.x + d.y;
	while (1)
	{
		img_pixel_put(frame, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		render_line_calc(&p1, &d, &s, &error);
	}
}
