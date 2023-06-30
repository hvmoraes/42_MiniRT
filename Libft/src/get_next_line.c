/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:43:04 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/28 10:19:23 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_line(char *matrix)
{
	int		i;
	char	*result;

	i = 0;
	if (!matrix[i])
		return (NULL);
	while (matrix[i] && matrix[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (matrix[i] && matrix[i] != '\n')
	{
		result[i] = matrix[i];
		i++;
	}
	if (matrix[i] == '\n')
	{
		result[i] = matrix[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_new_matrix(char *matrix)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (matrix[i] && matrix[i] != '\n')
		i++;
	if (!matrix[i])
	{
		free(matrix);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(matrix) - i + 1));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (matrix[i])
		result[j++] = matrix[i++];
	result[j] = '\0';
	free(matrix);
	return (result);
}

char	*ft_read(int fd, char *matrix)
{
	char	*buff;
	int		rd;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd = 1;
	while (ft_strchr(matrix, '\n') == 0 && rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		matrix = ft_strjoin(matrix, buff);
	}
	free(buff);
	return (matrix);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*matrix[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!matrix[fd])
		matrix[fd] = ft_strdup("");
	matrix[fd] = ft_read(fd, matrix[fd]);
	if (!matrix[fd])
		return (NULL);
	line = ft_line(matrix[fd]);
	matrix[fd] = ft_new_matrix(matrix[fd]);
	if (!matrix[fd])
		return (NULL);
	return (line);
}
