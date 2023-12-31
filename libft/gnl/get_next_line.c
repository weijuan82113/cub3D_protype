/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:27:19 by wchen             #+#    #+#             */
/*   Updated: 2023/11/12 22:48:31 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	save(char **line, char *find_return)
{
	char	*tmp;

	tmp = *line;
	if (*(find_return + 1) != '\0')
		*line = ft_strdup_gnl(find_return + 1);
	else
		*line = NULL;
	free(tmp);
}

static char	*return_save(char **line, char *find_return)
{
	char	*ret_chr;
	size_t	ret_length;
	size_t	i;

	ret_length = (size_t)find_return - (size_t)(*line) + 2;
	ret_chr = (char *)malloc(sizeof(char) * (ret_length + 2));
	if (!ret_chr)
	{
		if (*line)
			free(*line);
		*line = NULL;
		return (NULL);
	}
	i = 0;
	while ((*line)[i] != '\n')
	{
		ret_chr[i] = (*line)[i];
		i ++;
	}
	ret_chr[i ++] = '\n';
	ret_chr[i] = '\0';
	save(line, find_return);
	return (ret_chr);
}

static char	*return_line(char **line)
{
	char	*ret_chr;

	if (*line && **line != '\0')
	{
		ret_chr = *line;
		*line = NULL;
		return (ret_chr);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t			read_byte;
	char			*buf;
	char			*find_return;
	static char		*line[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	find_return = ft_memchr_gnl(line[fd], '\n', ft_strlen_gnl(line[fd]));
	if (find_return)
		return (return_save(&line[fd], find_return));
	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte = read(fd, buf, BUFFER_SIZE);
	if (read_byte <= 0)
	{
		free (buf);
		return (return_line(&line[fd]));
	}
	buf[read_byte] = '\0';
	line[fd] = ft_strjoin_and_free_s1(line[fd], buf);
	free(buf);
	return (get_next_line(fd));
}

// # include <stdbool.h>

// int main(int ac, char **av) {
// 	size_t i;
//     if (ac != 2) {
//         fprintf(stderr, "invalid argument");
//         return 1;
//     }
//     int fd1 = open(av[1], O_RDONLY);
// 	int fd2 = open(av[2], O_RDONLY);
// 	int fd3 = open(av[3], O_RDONLY);
// 	//printf("fd is %d \n", fd);
//     i = 0;
// 	while (true) {
//         char *s1 = get_next_line(fd1);
// 		char *s2 = get_next_line(fd2);
// 		char *s3 = get_next_line(fd3);
// 		printf("%zu:%s \n",i, s1);
// 		printf("%zu:%s \n",i, s2);
// 		printf("%zu:%s \n",i, s3);
//         if (s1 == NULL || s2 == NULL || s3 == NULL) {
//             break;
//         }
//         free(s1);
// 		// free(s2);
// 		// free(s3);
// 		i ++;
//     }
// }
