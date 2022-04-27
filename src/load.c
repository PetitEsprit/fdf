/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:12:53 by user              #+#    #+#             */
/*   Updated: 2022/04/27 19:26:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "init.h"
#include "type.h"

static void	free_word_tab(void *data)
{
	char	**tab;
	int		j;

	j = 0;
	tab = (char **)data;
	if (!tab)
		return ;
	while (tab[j])
	{
		free(tab[j++]);
	}
	free(tab);
}

static t_list	*file_to_lst(char *filename)
{
	int		fd;
	char	*line;
	t_list	*l;
	t_list	*tmp;

	l = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_lstnew(ft_split(line, ' '));
		if (!tmp || !tmp->content)
		{
			ft_lstclear(&l, free_word_tab);
			return (NULL);
		}
		ft_lstadd_back(&l, tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (l);
}

static t_point	**list_to_tab(t_list *l, int width, int height)
{
	t_list	*curr;
	t_point	**tab;
	int		j;
	int		i;

	curr = l;
	j = 0;
	tab = (t_point **)malloc(sizeof(t_point *) * height);
	while (tab && j < height)
	{
		tab[j] = (t_point *)malloc(sizeof(t_point) * (width + 1));
		if (!tab[j])
		{
			while (--j >= 0)
				free(tab[j]);
			free(tab);
			return (NULL);
		}
		i = -1;
		while (((char **)curr->content)[++i])
			tab[j][i].z = ft_atoi(((char **)curr->content)[i]);
		curr = curr->next;
		++j;
	}
	return (tab);
}

void	cart_to_iso(t_data *data)
{
	int	j;
	int	i;
	int	x;
	int	y;

	j = 0;
	while (j < data->rows)
	{
		i = 0;
		while (i < data->cols)
		{
			x = data->offset.x + (i - j) * data->scale;
			y = data->offset.y + (j + i) / 2.0 * data->scale
				+ data->map[j][i].z * -data->scale / 2;
			data->map[j][i].x = x;
			data->map[j][i].y = y;
			++i;
		}
		++j;
	}
}

int	load_file(t_data *data, char *filename)
{
	t_list	*l;
	char	**tmp;
	t_point	**tab;
	int		w;
	int		h;

	l = file_to_lst(filename);
	if (!l)
		return (-1);
	h = ft_lstsize(l);
	w = 0;
	tmp = ((char **)l->content);
	while (tmp[w])
		++(w);
	tab = list_to_tab(l, w, h);
	if (tab)
	{
		data->map = tab;
		data->cols = w;
		data->rows = h;
		init_data(data, 1280, 720, filename);
		cart_to_iso(data);
	}
	ft_lstclear(&l, free_word_tab);
	return (0);
}
