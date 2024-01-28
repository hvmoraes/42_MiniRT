/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:18:30 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 11:18:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init(data);
	mlx_loop_hook(data->mlx->mlx, render, data);
	mlx_key_hook(data->mlx->win, key_hooks, data);
	mlx_hook(data->mlx->win, 17, 17, close_window, data);
	mlx_loop(data->mlx->mlx);
}
