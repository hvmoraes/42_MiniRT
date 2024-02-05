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

#include "../inc/minirt.h"

void	put_pixel(int x, int y, int color)
{
	char	*dst;
	int		new_x;
	int		new_y;

	new_x = (WIDTH / 2) + x;
	new_y = (HEIGHT / 2) - y;
	dst = data()->mlx->addr + (new_y * data()->mlx->line_length + new_x
			* (data()->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	trace_ray(t_vec3 viewport, float min_t, float max_t)
{
	float		closest_t;
	t_sphere	closest_sphere;
	t_vec2		t;
	int			i;
	t_vec3	point;
	t_vec3	normal;

	closest_t = INF;
	i = -1;
	closest_sphere.radius = -1;
	while (++i < data()->total_spheres)
	{
		t = intersect_sphere(camera()->center, viewport, data()->spheres[i]);
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
	}
	if (closest_sphere.radius == -1)
		return (BLACK);
	point = vec3_add(camera()->center, scalar(viewport, closest_t));
	normal = vec3_sub(point, closest_sphere.center);
	normal = normalize(normal);
	return (rgb_to_int(scalar(closest_sphere.color, calculate_light(point, normal))));
}

int	render(void)
{
	int			x;
	int			y;
	t_vec3		viewport_point;
	int			color;

	y = HEIGHT / 2;
	while (--y >= (HEIGHT / 2) * -1)
	{
		x = (WIDTH / 2) * -1;
		while (++x <= WIDTH / 2)
		{
			viewport_point = canvas_viewport(x, y);
			color = trace_ray(viewport_point, 1, INF);
			put_pixel(x, y, color);
		}
	}
	mlx_put_image_to_window(data()->mlx->mlx, data()->mlx->win,
		data()->mlx->img, 0, 0);
	return (0);
}
