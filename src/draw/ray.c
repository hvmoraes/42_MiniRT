/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:34:18 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/07 14:30:24 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	closest(double *t, double *closest_t, t_object *closest_sphere,
	t_object *object)
{
	(void)closest_sphere;
	printf("%f\n%f\n", *closest_t, *t);
	if (*t < *closest_t)
	{
		*closest_t = *t;
		closest_sphere = object;
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
			t = intersect_sphere(g_data.camera.coor, viewport_point,
					*sphere);
			printf("%f\n", t);
			closest(&t, &closest_t, closest_sphere, g_data.objects);
			printf("%i\n", closest_sphere->color.r);
		}
		g_data.objects = g_data.objects->next;
	}
	if (closest_sphere == NULL)
		return (BACK_COLOR);
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

	x = -WIDTH / 2;
	while (x < WIDTH / 2)
	{
		y = -HEIGHT / 2;
		while (y < HEIGHT / 2)
		{
			canvas_viewport(x, y, &point);
			copy = g_data.objects;
			color = get_color(point);
			g_data.objects = copy;
			mlx_pixel_put(g_data.mlx.mlx, g_data.mlx.win, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(g_data.mlx.mlx, g_data.mlx.win,
		g_data.mlx.img, 0, 0);
}
