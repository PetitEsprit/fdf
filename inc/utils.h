/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:23:29 by user              #+#    #+#             */
/*   Updated: 2022/04/16 20:08:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "type.h"

int		key_event(int keycode, t_data *data);
int		mouse_event(t_data *data);
void	img_pixel_put(t_img *frame, int x, int y, int color);

#endif
