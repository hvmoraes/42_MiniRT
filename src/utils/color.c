/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:46:11 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/19 14:18:05 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_color(char *color, t_color *color_final)
{
	char	**color_check;

	color_check = ft_split(color, ',');
	if (line_fields(color_check) != 3)
	{
		free_matrix(color_check);
		return (parse_error("Color has to be in format [R,G,B]"));
	}
	color_final->r = ft_atoi(color_check[0]);
	color_final->g = ft_atoi(color_check[1]);
	color_final->b = ft_atoi(color_check[2]);
	free_matrix(color_check);
	if (color_final->r > 255)
		color_final->r = 255;
	if (color_final->g > 255)
		color_final->g = 255;
	if (color_final->b > 255)
		color_final->b = 255;
	if (color_final->r < 0)
		color_final->r = 0;
	if (color_final->g < 0)
		color_final->g = 0;
	if (color_final->b < 0)
		color_final->b = 0;
	return (1);
}

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dest = color;
}
