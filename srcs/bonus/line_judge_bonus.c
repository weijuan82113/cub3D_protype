/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:56:08 by wchen             #+#    #+#             */
/*   Updated: 2024/03/19 23:03:03 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_line_lst(t_g_board *g_board, char *line)
{
	int	str_len;

	str_len = 0;
	str_len = ft_strlen_ntr(line);
	if (str_len != 0 && line[str_len - 1] == ' ')
		str_len --;
	if (str_len > g_board->m_info->w)
		g_board->m_info->w = str_len;
	if (!g_board->line_lst)
		g_board->line_lst = ft_lstnew(line);
	else
		ft_lstadd_back(&g_board->line_lst, ft_lstnew(line));
}

bool	line_judge(t_g_board *g_board, char *line, int *x, int *y)
{
	char	*content;

	errno = 0;
	if (character_judge(g_board, line, x, y))
		return (true);
	content = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!content)
		return (ft_error(MALLOC_ERR));
	ft_memcpy(content, line, ft_strlen(line));
	save_line_lst(g_board, content);
	g_board->m_info->h += 1;
	return (false);
}
