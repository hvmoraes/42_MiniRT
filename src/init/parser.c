/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:50:09 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 14:50:09 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	parse_error(char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error, 2);
	return (1);
}

int	check_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return ((file[i - 3] != '.') + (file[i - 2] != 'r') + (file[i - 1] != 't'));
}

void	verify_line(char *line, int *error)
{
	char	**verify;

	verify = ft_split(line, ' ');
	if (!verify[0])
		return ;
	else if (!ft_strncmp("C", verify[0], ft_strlen(verify[0])))
		*error += init_camera(verify);
	else if (!ft_strncmp("sp", verify[0], ft_strlen(verify[0])))
		*error += add_sphere(verify);
	else if (verify[0][0] != '\n')
		*error += parse_error("Invalid character found\n");
	free_array(verify);
	free(line);
}

void	parser(int argc, char **argv)
{
	int	fd;
	char	*line;
	static int	error;

	if (argc != 2)
	{
		parse_error("Usage: ./minirt [scene].rt\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (check_name(argv[1]) || fd == -1)
	{
		error += parse_error("Invalid filename\n");
	}
	line = get_next_line(fd);
	while (line)
	{
		verify_line(line, &error);
		line = get_next_line(fd);
	}
	close(fd);
	parser2(&error);
	check_error(error);
}
