/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:02:45 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 14:16:48 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Check if the file is in the right format: "file.rt"
 * 
 * @param file 
 * @return int 
 */
int	valid_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 3] == '.' && file[i - 2] == 'r' && file[i - 1] == 't')
		return (1);
	return (0);
}

/**
 * @brief Sets the end of every line to '\0'
 * 
 * @param buffer 
 */
void	end_file(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i != 0)
		buffer[i] = '\0';
}

/**
 * @brief Check every line of the file and call init functions 
 * for each element for the scene
 * 
 * @param buffer 
 */
int	line_info(char *buffer)
{
	char	**line;

	end_file(buffer);
	line = ft_split(buffer, ' ');
	if (!line)
		return (0);
	if (ft_strcmp(line[0], "C") == 0)
	{
		if (!init_camera(line))
		{
			free_matrix(line);
			return (0);
		}
	}
	if (ft_strcmp(line[0], "sp") == 0)
	{
		if (!add_sphere(line))
		{
			free_matrix(line);
			free_all(1);
			return (0);
		}
	}
	free_matrix(line);
	return (1);
}

/**
 * @brief Check if file name is valid and read line after line
 * 
 * @param argv 
 */
int	parse_file(char **argv)
{
	int		fd;
	char	*buffer;

	fd = open(argv[1], O_RDONLY);
	if (valid_file(argv[1]) == 0 || fd == -1)
	{
		handle_error("Invalid file name");
		close(fd);
		return (0);
	}
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (!line_info(buffer))
		{
			free(buffer);
			close(fd);
			return (0);
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
	return (1);
}

/**
 * @brief Init everything: parse_file, init_scene
 * 
 * @param argv 
 */
void	init_data(char **argv)
{
	if (!parse_file(argv))
		exit(errno);
	init_scene();
	draw();
}
