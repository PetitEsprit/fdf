/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:38:30 by user              #+#    #+#             */
/*   Updated: 2022/04/16 21:07:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "init.h"
#include "utils.h"
#include "load.h"

void	clear_image(t_img *frame)
{
	int	j;
	int	i;

	j = 0;
	while (j < frame->height)
	{
		i = 0;
		while (i < frame->width)
		{
			img_pixel_put(frame, i, j, 0);
			++i;
		}
		++j;
	}
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

void	draw_landscape(t_data *data, t_point **map, int w, int h)
{
	int	j;
	int	i;

	j = -1;
	while (++j < h)
	{
		i = -1;
		while (++i < w)
		{
			if (i < w - 1)
				render_line(&data->frame, map[j][i], map[j][i + 1], 0xFFFFFFFF);
			if (j < h - 1)
				render_line(&data->frame, map[j][i], map[j + 1][i], 0xFFFFFFFF);
		}
	}
}

int	render(t_data *data)
{
	(void) data;
	
	if (!data->win)
		return (0);
	clear_image(&data->frame);
	draw_landscape(data, data->map, data->cols, data->rows);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
	mlx_string_put(data->mlx, data->win, 130, 100, 0xFF00, "CONTROL");
	mlx_string_put(data->mlx, data->win, 100, 115, 0xFF00, "ZOOM in/out: p / m");
	mlx_string_put(data->mlx, data->win, 100, 130, 0xFF00, "Move left/right: left / right");
	return (0);
}
