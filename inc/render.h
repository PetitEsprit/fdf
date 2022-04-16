/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:41:51 by user              #+#    #+#             */
/*   Updated: 2022/04/15 19:44:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	render_line(t_img *frame, t_point p1, t_point p2, int color);
void	draw_landscape(t_data *data, t_point **map, int w, int h);
int		render(t_data *data);

#endif
