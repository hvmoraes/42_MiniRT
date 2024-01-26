/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:40:49 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/01/26 14:16:25 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_rt(t_rt *rt)
{
	rt->hitable = NULL;
	rt->theta = 2.0f;
	rt->mincolour = init_vec3d(0, 0, 0);
	rt->maxcolour = init_vec3d(255, 255, 255);
	rt->i = -1;
	rt->mul = 1.0f;
}

void	init_mlx(t_rt *rt)
{
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, SIZE, SIZE, "minirt");
	rt->image = mlx_new_image(rt->mlx, SIZE, SIZE);
	rt->pointer_to_image = mlx_get_data_addr(rt->image,
			&rt->bits_per_pixel,
			&rt->size_line,
			&rt->endian);
}

int	exit_mlx(t_rt *rt)
{
	mlx_destroy_image(rt->mlx, rt->image);
	mlx_destroy_window(rt->mlx, rt->window);
	t_hitable *current = rt->hitable;
	while (current != NULL) {
		t_hitable *temp = current;
		current = current->next;
		free(temp);
	}
	free(rt->mlx);
	free(rt);
	exit(0);
}