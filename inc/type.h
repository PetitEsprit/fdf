/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:06:58 by user              #+#    #+#             */
/*   Updated: 2022/04/16 20:07:43 by user             ###   ########.fr       */
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

typedef struct s_point {
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	frame;
	t_point	**map;
	int		cols;
	int		rows;
	int		scale;
	t_point	offset;
}	t_data;

#endif
