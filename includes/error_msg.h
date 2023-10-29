/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:57:31 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 19:30:34 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define MLX_INIT_ERR				"Error\nError occurs in mlx initial"
# define ARG_ERR					"Error\nWrong Argument amount"
# define FILE_EXT_ERR				"Error\nThe file extension is Wrong"
# define OPEN_FILE_ERR				"Error\nOpen file failure"
# define IDENTIFIER_TYPE_ERR 		"Error\nInput identifier type is Wrong"
# define IDENTIFIER_PATH_ERR 		"Error\nInput identifier path is Wrong"
# define MALLOC_ERR 				"Error\nMalloc Error"
# define INPUT_EMPTY_LINE_ERR 		"Error\nCan not input empty line in map"
# define MAP_SIZE_ERR				"Error\nThe size of map is wrong"
# define CHARACTER_ERR				"Error\nThe character in map is wrong"
# define WALL_ERR					"Error\nThe map is not surrended by wall"
# define INITIAL_MAP_ERR			"Error\nError occurs in map initial"
# define GRAPH_INITIAL_ERR			"Error\nError occurs in graph initial"
# define EDGE_INITIAL_ERR			"Error\nError occurs in edge initial"
# define IMG_INITIAL_ERR			"Error\nError occurs in img initial"
# define COLOR_INITIAL_ERR			"Error\nError occurs in color initial"
# define PLAYER_POSITON_ERR			"Error\nThere is no player in map"
# define GAME_OVER					"GAME OVER!"

# define IDENTIFIER "NO/SO/WE/EA/F/C"
# define CHARACTER "0/1/N/S/E/W/ "
# define PLAYER "N/S/E/W"

# define identifier_amount 6

# define img_h	64
# define img_w	64

# define win_x	1024
# define win_y	1024

//KEYBOARD
# define KEY_UP						0xff52
# define KEY_DOWN					0xff54
# define KEY_LEFT					0xff51
# define KEY_RIGHT					0xff53
# define KEY_W						0X77
# define KEY_S						0x73
# define KEY_A						0x61
# define KEY_D						0x64
# define KEY_Q						0x71
# define KEY_SPC					0x20
# define ESC						0xff1b
# define UP							1
# define DOWN						2
# define LEFT						3
# define RIGHT						4




#endif