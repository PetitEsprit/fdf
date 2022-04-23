/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:24 by user              #+#    #+#             */
/*   Updated: 2022/04/23 13:43:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "init.h"

int	init_data(t_data *data, int width, int height, char *title)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, title);
	data->offset.x = width / 2;
	data->offset.y = height / 2;
	data->scale = 10;
	data->frame.width = width;
	data->frame.height = height;
	data->frame.img = mlx_new_image(data->mlx, width, height);
	data->frame.buff = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	if (!data->mlx || !data->win || !data->frame.img || !data->frame.buff)
	{
		free_data(data);
		free(data->win);
		write(1, "Initialisation error", 20);
		return (-1);
	}
	return (0);
}

void	free_data(t_data *data)
{
	int	j;

	mlx_destroy_image(data->mlx, data->frame.img);
	mlx_destroy_window(data->mlx, data->win);
	j = 0;
	while (j < data->rows)
		free(data->map[j++]);
	free(data->map);
	data->win = NULL;
	data->frame.img = NULL;
}
