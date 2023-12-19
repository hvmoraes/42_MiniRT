/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:41:46 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/12/19 10:18:53 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_objects(void)
{
	t_object	*tmp;

	while (g_data.objects)
	{
		tmp = g_data.objects->next;
		if (g_data.objects->object)
			free((t_sphere *)g_data.objects->object);
		free(g_data.objects);
		g_data.objects = tmp;
	}
	g_data.objects = NULL;
}

void	free_all(int flag)
{
	free_objects();
	if (flag)
	{
		if (g_data.mlx.img)
			mlx_destroy_image(g_data.mlx.mlx, g_data.mlx.img);
		if (g_data.mlx.win)
			mlx_destroy_window(g_data.mlx.mlx, g_data.mlx.win);
		if (g_data.mlx.mlx)
		{
			free(g_data.mlx.mlx);
		}
	}
}

void	end(void)
{
	printf("Ending...\n");
	free_all(1);
	exit(0);
}
