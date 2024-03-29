/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:46:27 by wchen             #+#    #+#             */
/*   Updated: 2024/03/07 23:49:28 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

void	fill_the_map_array(char *content, char *map, int w)
{
	int	i;

	i = 0;
	while (i < w && content[i] && content[i] != '\n')
	{
		map[i] = content[i];
		i++;
	}
	while (i < w)
	{
		map[i] = ' ';
		i++;
	}
	map[i] = '\0';
}

bool	initial_map_array(t_g_board *g)
{
	t_node	*temp_node;
	int		i;

	g->m_info->map = malloc(sizeof(char *) * (g->m_info->h + 1));
	if (!g->m_info->map)
		return (false);
	i = 0;
	temp_node = g->line_lst;
	while (temp_node)
	{
		g->m_info->map[i] = malloc(sizeof(char) * (g->m_info->w + 1));
		if (!g->m_info->map[i])
			return (false);
		fill_the_map_array(temp_node->content, g->m_info->map[i],
			g->m_info->w);
		temp_node = temp_node->next;
		i++;
	}
	g->m_info->map[i] = NULL;
	return (true);
}

bool	map_check(t_g_board *g_board)
{
	errno = 0;
	if (!initial_map_array(g_board))
		return (ft_error(INITIAL_MAP_ERR));
	if (wall_check(g_board->m_info->map, g_board->m_info->h))
		return (ft_error(WALL_ERR));
	if (wall_graph_check(g_board))
		return (true);
	return (false);
}

bool	create_map_array(t_g_board *g_board)
{
	errno = 0;
	if (g_board->m_info->h < 3 || g_board->m_info->w < 3)
		return (ft_error(MAP_SIZE_ERR));
	if (map_check(g_board))
		return (true);
	return (false);
}
