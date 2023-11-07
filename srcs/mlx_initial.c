/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:37:32 by wchen             #+#    #+#             */
/*   Updated: 2023/11/07 23:18:06 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	g_init(t_g_board *g_board)
{
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->color_lst = NULL;
	g_board->p_position = NULL;
	g_board->t_count = 0;
	g_board->m_info -> map = NULL;
	g_board->m_info -> h = NULL;
	g_board->m_info -> w = NULL;
	g_board->identifier = NULL;
}

bool	game_board_initial(t_g_board *g_board)
{
	g_board->m_info = malloc(sizeof(t_map_info));
	if (!g_board->m_info)
		return (ft_error(MALLOC_ERR));
	g_init(g_board);
	g_board->m_info->h = (int *)malloc(sizeof(int));
	if (!g_board->m_info->h)
		return (ft_error(MALLOC_ERR));
	*g_board->m_info->h = 0;
	g_board->m_info->w = (int *)malloc(sizeof(int));
	if (!g_board->m_info->w)
		return (ft_error(MALLOC_ERR));
	*g_board->m_info->w = 0;
	g_board->p_position = (int *)malloc(sizeof(int));
	if (!g_board->p_position)
		return (ft_error(MALLOC_ERR));
	*g_board->p_position = 0;
	g_board->identifier = ft_split(IDENTIFIER, '/');
	if (!g_board->identifier)
		return (ft_error(MALLOC_ERR));
	return (false);
}

bool	mlx_initial(t_mlx **dst)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	*dst = mlx;
	if (!mlx)
		return (true);
	mlx->p_mlx = mlx_init();
	if (!mlx->p_mlx)
		return (true);
	mlx->p_win = mlx_new_window(mlx->p_mlx, WIN_X, WIN_Y, "Cub3D");
	if (!mlx->p_win)
		return (true);
	mlx->g = malloc(sizeof(t_g_board));
	if (!mlx->g)
		return (true);
	if (game_board_initial(mlx->g))
		return (true);
	return (false);
}
