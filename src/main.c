/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:41:57 by user              #+#    #+#             */
/*   Updated: 2022/04/16 21:55:53 by user             ###   ########.fr       */
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
#include "render.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (-1);
	load_file(&data, av[1]);

	// A enveler ou à remplacer par le ft_printf
	/*printf("WIDTH :%d / HEIGHT: %d\n", data.cols, data.rows);
	for(int j = 0; j < data.rows; j++)
	{
		for(int i = 0; i < data.cols; i++)
			printf("(%d %d) ", data.map[j][i].x, data.map[j][i].y);
		printf("\n");
	}*/
	mlx_loop_hook(data.mlx, render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_event, &data);
	mlx_hook(data.win, DestroyNotify, KeyPressMask, mouse_event, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
