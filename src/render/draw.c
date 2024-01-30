/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:58:26 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 12:58:26 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minirt.h"

void	put_pixel(int x, int y, int color)
{
	char	*dst;
	int	new_x;
	int	new_y;

	new_x = (WIDTH / 2) + x;
	new_y = (HEIGHT / 2) - y;
	dst = data()->mlx->addr + (new_y * data()->mlx->line_length + new_x * (data()->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	trace_ray(t_vec3 camera, t_vec3 viewport, float min_t, float max_t)
{
	float	closest_t;
	t_sphere	closest_sphere;
	t_vec2	t;
	int	i;

	closest_t = INF;
	i = 0;
	closest_sphere.radius = -1;
	while (i < data()->total_spheres)
	{
		t = intersect_sphere(camera, viewport, data()->spheres[i]);
		if (t.x >= min_t && t.x <= max_t && t.x < closest_t)
		{
			closest_t = t.x;
			closest_sphere = data()->spheres[i];
		}
		if (t.y >= min_t && t.x <= max_t && t.y < closest_t)
		{
			closest_t = t.y;
			closest_sphere = data()->spheres[i];
		}
		i++;
	}
	if (closest_sphere.radius == -1)
		return BLACK;
	return closest_sphere.int_color;
}

int	render(void)
{
	int	x;
	int	y;
	t_vec3	viewport_point;
	t_vec3	camera;
	int	color;

	camera.x = 0;
	camera.y = 0;
	camera.z = 0;
	y = HEIGHT / 2;
	while (--y >= (HEIGHT / 2) * -1)
	{
		x = (WIDTH / 2) * -1;
		while (++x <= WIDTH / 2)
		{
			viewport_point = canvas_viewport(x, y);
			color = trace_ray(camera, viewport_point, 1, INF);
			//printf("x = %f y = %f z = %f\n", viewport_point.r, viewport_point.g, viewport_point.b);
			put_pixel(x, y, color);
		}
	}
	mlx_put_image_to_window(data()->mlx->mlx, data()->mlx->win, data()->mlx->img, 0, 0);
	return (0);
}