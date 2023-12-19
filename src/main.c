/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:58:48 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/09/12 13:32:43 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_data	g_data;

int	close_window(void)
{
	end();
	exit(0);
}

int	key_press(int keycode)
{
	printf("Key pressed: %i\n", keycode);
	if (keycode == 65307)
	{
		end();
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
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
