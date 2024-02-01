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

int	main(int argc, char **argv)
{
	init_values();
	parser(argc, argv);
	init_mlx();
	mlx_loop_hook(data()->mlx->mlx, render, NULL);
	mlx_key_hook(data()->mlx->win, key_hooks, NULL);
	mlx_hook(data()->mlx->win, 17, 17, close_window, NULL);
	mlx_loop(data()->mlx->mlx);
}
