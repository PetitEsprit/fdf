/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:41:57 by user              #+#    #+#             */
/*   Updated: 2022/04/27 19:27:10 by user             ###   ########.fr       */
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

	if (ac < 2 || load_file(&data, av[1]) < 0)
		return (-1);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_event, &data);
	mlx_hook(data.win, DestroyNotify, KeyPressMask, mouse_event, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
