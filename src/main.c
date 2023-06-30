/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:58:48 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/28 10:48:32 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	close_window(void)
{
	printf("Window closed\n");
	exit(0);
}

int	key_press(int keycode)
{
	if (keycode == 53)
	{
		printf("Window closed\n");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		init_data(argv);
		mlx_hook(g_data.mlx.win, 2, 0, key_press, NULL);
		mlx_hook(g_data.mlx.win, 17, 17, close_window, NULL);
		mlx_loop(g_data.mlx.mlx);
	}
	else
	{
		printf("Usage: ./minirt {scene}.rt\n");
		return (1);
	}
	return (0);
}
