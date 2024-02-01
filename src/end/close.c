/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:36:08 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 13:36:08 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_mlx(void)
{
	mlx_destroy_image(data()->mlx->mlx, data()->mlx->img);
	mlx_destroy_window(data()->mlx->mlx, data()->mlx->win);
	mlx_destroy_display(data()->mlx->mlx);
}

void	free_all(void)
{
	free(data()->mlx->mlx);
	free(data()->mlx);
	free(data()->spheres);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}

int	close_window(void)
{
	free_mlx();
	free_all();
	exit(0);
	return (0);
}
