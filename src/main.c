/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:41:57 by user              #+#    #+#             */
/*   Updated: 2022/04/13 17:47:59 by mdankou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "init.h"
#include "utils.h"
#include "load.h"

int		render(t_data *data)
{
	(void) data;
	return (0);
}

t_point	yrev(t_point p, t_img *frame)
{
	t_point res;

	res.x = p.x;
	res.y = frame->height - p.y;

	return (res);
}

void	draw_landscape(t_data *data, t_point **map, int w, int h)
{
	int	j;
	int	i;

	j = 0;
	while(j < h)
	{
		i = 0;
		while(i < w)
		{
			if (i < w - 1)
				render_line(&data->frame, yrev(map[j][i], &data->frame), yrev(map[j][i + 1], &data->frame), 0xFFFFFFFF);
			if (j < h - 1)
				render_line(&data->frame, yrev(map[j][i], &data->frame), yrev(map[j + 1][i], &data->frame), 0xFFFFFFFF);
			++i;
		}
		++j;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (-1);
	load_file(&data, av[1]);

	printf("WIDTH :%d / HEIGHT: %d\n", data.cols, data.rows);
	for(int j = 0; j < data.rows; j++)
	{
		for(int i = 0; i < data.cols; i++)
			printf("(%d %d) ", data.map[j][i].x, data.map[j][i].y);
		printf("\n");
	}
	draw_landscape(&data, data.map, data.cols, data.rows);
	mlx_put_image_to_window(data.mlx, data.win, data.frame.img, 0, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_event, &data);
	mlx_hook(data.win, DestroyNotify, KeyPressMask, mouse_event, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
