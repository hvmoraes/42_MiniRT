/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:10:26 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 13:10:26 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	init_camera(char **line)
{
	int		error;
	char	**coords;

	error = 0;
	if (data()->total_cameras)
		return (parse_error("More than one camera in scene\n"));
	if (array_size(line) != 4)
		return (parse_error("Invalid number of arguments for camera\n"));
	coords = check_coords(line[1], &error);
	camera()->center.x = ft_atod(coords[0]);
	camera()->center.y = ft_atod(coords[1]);
	camera()->center.z = ft_atod(coords[2]);
	free_array(coords);
	error += check_normal(line[2], &error);
	error += check_fov(line[3]);
	set_viewport();
	data()->total_cameras++;
	return (error);
}

int	add_sphere(char **line)
{
	int			error;
	char		**coords;
	t_sphere	*tmp;
	int			i;
	t_vec3		color;

	i = 0;
	error = 0;
	if (array_size(line) != 4)
		return (parse_error("Invalid number of arguments for sphere\n"));
	data()->total_spheres++;
	tmp = malloc(data()->total_spheres * sizeof(t_sphere));
	if (data()->spheres)
	{
		while (i < data()->total_spheres - 1)
		{
			tmp[i] = data()->spheres[i];
			i++;
		}
	}
	coords = check_coords(line[1], &error);
	tmp[i].center.x = ft_atod(coords[0]);
	tmp[i].center.y = ft_atod(coords[1]);
	tmp[i].center.z = ft_atod(coords[2]);
	free_array(coords);
	tmp[i].radius = ft_atod(line[2]) / (float)2;
	if (tmp[0].radius < 0)
		return (parse_error("Sphere's diameter can't be negative"));
	color = check_color(line[3], &error);
	tmp[i].color.x = color.x;
	tmp[i].color.y = color.y;
	tmp[i].color.z = color.z;
	tmp[i].int_color = rgb_to_int(tmp[i].color);
	free(data()->spheres);
	data()->spheres = tmp;
	return (error);
}

void	init_values(void)
{
	data()->total_spheres = 0;
	data()->total_cameras = 0;
	data()->total_lights = 0;
	data()->total_ambients = 0;
	data()->spheres = NULL;
}

void	init_mlx(void)
{
	data()->mlx = malloc(sizeof(t_mlx));
	data()->mlx->mlx = mlx_init();
	data()->mlx->win = mlx_new_window(data()->mlx->mlx, WIDTH, HEIGHT, "Minirt");
	data()->mlx->img = mlx_new_image(data()->mlx->mlx, WIDTH, HEIGHT);
	data()->mlx->addr = mlx_get_data_addr(data()->mlx->img,
		&data()->mlx->bits_per_pixel, &data()->mlx->line_length, &data()->mlx->endian);
}
