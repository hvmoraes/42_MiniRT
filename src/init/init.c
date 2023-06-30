/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:02:45 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/29 16:09:18 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_data	g_data;

/**
 * @brief Check if the file is in the right format: "file.rt"
 * 
 * @param file 
 * @return int 
 */
int	valid_file(char *file)
{
	while (*file != '.' && *file)
		file++;
	if (ft_strcmp(file, "rt"))
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
 * @brief Check every line of the file and call init functions for each element for the scene
 * 
 * @param buffer 
 */
void	line_info(char *buffer)
{
	char	**line;

	end_file(buffer);
	line = ft_split(buffer, ' ');
	if (!line)
		return ;
	if (ft_strcmp(line[0], "C") == 0)
		init_camera(line);
	if (ft_strcmp(line[0], "sp") == 0)
		init_sphere(line);
	if (ft_strcmp(line[0], "pl") == 0)
		init_plane(line);
}

/**
 * @brief Check if file name is valid and read line after line
 * 
 * @param argv 
 */
void	parse_file(char **argv)
{
	int		fd;
	char	*buffer;

	fd = open(argv[1], O_RDONLY);
	if (!valid_file(argv[1]) || fd == -1)
		handle_error("Invalid file name");
	buffer = get_next_line(fd);
	while (buffer)
	{
		line_info(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}

/**
 * @brief Init everything: parse_file, init_scene
 * 
 * @param argv 
 */
void	init_data(char **argv)
{
	parse_file(argv);
	init_scene();
	(void)argv;
}
