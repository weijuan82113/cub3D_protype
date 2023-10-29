/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:42:47 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 20:34:03 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void debug_print_imglst(t_img_node *img_lst)
{
	while (img_lst)
	{
		printf("Print Image\n");
		printf("obj:%s\n", img_lst->obj);
		printf("img_path:%s\n", img_lst->img_path);
		printf("p_img:%p\n", img_lst->p_img);
		printf("h:%d\n", img_lst->h);
		printf("w:%d\n", img_lst->w);
		img_lst = img_lst->next;
	}
}

void debug_print_colorlst(t_color_node *color_lst)
{
	while (color_lst)
	{
		printf("Print Color\n");
		printf("obj:%s\n", color_lst->obj);
		printf("color:%s\n", color_lst->rbg);
		color_lst = color_lst->next;
	}
}

void debug_print_linelst(t_g_board *g_board)
{
	t_node	*temp_line;

	temp_line = g_board->line_lst;
	printf("print line content:\n");
	while (temp_line)
	{
		printf("%s\n", (char *)temp_line->content);
		temp_line = temp_line->next;
	}
	printf("w:%d\n", *g_board->m_info->w);
	printf("h:%d\n", *g_board->m_info->h);
	printf("position:%d\n", *g_board->p_position);
}

bool fd_check(t_mlx *mlx, int fd)
{
	char		*line;
	int x;
	int y;

	x = -1;
	y = -1;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line_check(line, mlx, &x, &y))
			return (true);
		//free (line);
		//printf("%s",line);
	}
	if (x == -1 || y == -1)
		return (ft_error(PLAYER_POSITON_ERR));
	*mlx->g->p_position = y * *mlx->g->m_info->w + x;
	//debug_print_linelst(mlx->g);
	//debug_print_imglst(mlx->g->img_lst);
	//debug_print_colorlst(mlx->g->color_lst);
	if (create_map_array(mlx->g))
		return (true);
	return (false);
}

