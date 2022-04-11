/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:06:58 by user              #+#    #+#             */
/*   Updated: 2022/04/06 10:27:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct s_img {
	void	*img;
	char	*buff;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	frame;
}	t_data;

typedef struct s_point {
	int x;
	int y;
}	t_point;

#endif
