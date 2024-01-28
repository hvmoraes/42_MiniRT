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

void	init(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, 640, 360, "Minirt");
	data->mlx->img = mlx_new_image(data->mlx->mlx, WIDTH, HEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel,
			&data->mlx->line_length, &data->mlx->endian);
}
