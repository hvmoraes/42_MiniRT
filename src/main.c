/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:19:52 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/01/26 15:14:36 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_color_to_pixel(t_rt *rt, int x, int y, int color)
{
	int	*buffer;

	buffer = rt->pointer_to_image;
	buffer[(y * rt->size_line / 4) + x] = color;
}

static void	clear_screen(t_rt *rt)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < SIZE)
	{
		while (y < SIZE)
		{
			put_color_to_pixel(rt, x, y, 0x000000);
			y++;
		}
		x++;
		y = 0;
	}
}

static void	put_colour(t_rt *rt, t_vec2d coord, t_vec3d colour)
{
	t_vec3d		accum_colour;

	rt->accum[(int)(coord.x + coord.y * SIZE)]
		= t_vec3d_add(rt->accum[(int)(coord.x + coord.y * SIZE)], colour);
	accum_colour = rt->accum[(int)(coord.x + coord.y * SIZE)];
	accum_colour = t_vec3d_div(accum_colour, rt->frameindex);
	colour = clamp(accum_colour, rt->mincolour, rt->maxcolour);
	put_color_to_pixel(rt, coord.x, coord.y, convert_to_rgba(colour));
}

void	render(t_rt *rt)
{
	t_vec2d		coord;
	t_vec3d		colour;

	clear_screen(rt);
	camera()->mat = rotate_camera();
	if (rt->frameindex == 1)
		t_vec3dmemset(&rt->accum, 0);
	coord.y = -1;
	if (rt->hitable)
	{
		while (++(coord.y) < SIZE)
		{
			coord.x = -1;
			while (++(coord.x) < SIZE)
			{
				colour = per_pixal(rt, coord.x, coord.y);
				put_colour(rt, coord, colour);
			}
		}
	}
	rt->frameindex++;
	mlx_put_image_to_window(rt->mlx, rt->window, rt->image, 0, 0);
}

int	main(int ac, char **av)
{
	t_rt	*rt;

	if (ac != 2)
	{
		printf("Error\nUsage: ./minirt scene.rt\n");
		exit(1);
	}
	rt = malloc(sizeof(t_rt));
	init_rt(rt);
	init_mlx(rt);
	parse(&rt->hitable, av[1]);
	rt->frameindex = 1;
	mlx_loop_hook(rt->mlx, (void *)render, rt);
	mlx_key_hook(rt->window, key_hook, rt);
	mlx_hook(rt->window, 17, 0L, exit_mlx, rt);
	mlx_loop(rt->mlx);
	return (0);
}