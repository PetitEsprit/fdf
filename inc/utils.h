/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:23:29 by user              #+#    #+#             */
/*   Updated: 2022/04/05 20:26:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "type.h"

int		key_event(int keycode, t_data *data);
int		mouse_event(t_data *data);
void	img_pixel_put(t_img *frame, int x, int y, int color);
void	render_line(t_img *frame, t_point p1, t_point p2, int color);

#endif
