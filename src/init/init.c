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

# include "../inc/minirt.h"

int	init_camera(char **line)
{
	int	error;
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

void	init(void)
{
	data()->mlx = malloc(sizeof(t_mlx));
	data()->mlx->mlx = mlx_init();
	data()->mlx->win = mlx_new_window(data()->mlx->mlx, WIDTH, HEIGHT, "Minirt");
	data()->mlx->img = mlx_new_image(data()->mlx->mlx, WIDTH, HEIGHT);
	data()->mlx->addr = mlx_get_data_addr(data()->mlx->img, &data()->mlx->bits_per_pixel,
			&data()->mlx->line_length, &data()->mlx->endian);

	data()->spheres = malloc(3 * sizeof(t_sphere));
	data()->spheres[0].int_color = RED;
	data()->spheres[0].radius = 1;
	data()->spheres[0].center.x = 0;
	data()->spheres[0].center.y = -1;
	data()->spheres[0].center.z = 3;

	data()->spheres[1].int_color = BLUE;
	data()->spheres[1].radius = 1;
	data()->spheres[1].center.x = 2;
	data()->spheres[1].center.y = 0;
	data()->spheres[1].center.z = 4;

	data()->spheres[2].int_color = GREEN;
	data()->spheres[2].radius = 1;
	data()->spheres[2].center.x = -2;
	data()->spheres[2].center.y = 0;
	data()->spheres[2].center.z = 4;
	data()->total_spheres = 3;
}
