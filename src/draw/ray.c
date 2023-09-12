/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:34:18 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/09/07 14:06:44 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	closest(double *t, double *closest_t, t_object **closest_sphere,
	t_object *object)
{
	printf("color of sphere r = %i g = %i b = %i\n", object->color.r, object->color.g,object->color.b);
	printf("t in closest = %f; closest_t in closest = %f\n", *t, *closest_t);
	if (*t < *closest_t && *t != -1 && *t > g_data.viewport.distance)
	{
		*closest_t = *t;
		*closest_sphere = object;
	}
}

int	get_color(t_coor3 viewport_point)
{
	t_object	*closest_sphere;
	t_sphere	*sphere;
	double		closest_t;
	double		t;

	closest_t = INF;
	closest_sphere = NULL;
	while (g_data.objects)
	{
		if (g_data.objects->type == SPHERE)
		{
			sphere = (t_sphere *)(g_data.objects->object);
			printf("viewport point x = %f; y = %f; z = %f\n", viewport_point.x, viewport_point.y, viewport_point.z);
			t = intersect_sphere(g_data.camera.coor, viewport_point,
					*sphere);
			printf("t = %f\n", t);
			closest(&t, &closest_t, &closest_sphere, g_data.objects);
		}
		g_data.objects = g_data.objects->next;
	}
	if (closest_sphere == NULL)
	{
		printf("BLACK\n");
		return (BACK_COLOR);
	}
	printf("color at return: r = %i g = %i b = %i\n", closest_sphere->color.r, closest_sphere->color.g, closest_sphere->color.b);
	return ((closest_sphere->color.r << 16) | (closest_sphere->color.g << 8)
		| closest_sphere->color.b);
}

void	draw(void)
{
	t_coor3		point;
	int			x;
	int			y;
	int			color;
	t_object	*copy;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			canvas_viewport(x, y, &point);
			copy = g_data.objects;
			point = normalize(point);
			color = get_color(point);
			printf("color = %i\n", color);
			g_data.objects = copy;
			pixel_put(&g_data.mlx, x, y, color);
		}
	}
	mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
}
