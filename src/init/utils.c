/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:21:51 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/04 08:53:06 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	parse_error(char *error)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

/**
 * @brief Count the number of fields in line
 * 
 * @param line 
 * @return int 
 */
int	line_fields(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

/**
 * @brief Checks if a double is very close to zero
 * 
 * @param nbr 
 * @return int 
 */
int	is_zero(double nbr)
{
	return (nbr < 0.00001 && nbr > -0.00001);
}

void	set_vectors(t_coor3 *u, t_coor3 *v)
{
	t_coor3	w;

	w.x = 1;
	w.y = 0;
	w.z = 0;
	cross_prod(&w, &g_data.camera.normal, u);
	if (is_zero(g_data.camera.normal.x) && is_zero(g_data.camera.normal.y)
		&& is_zero(g_data.camera.normal.z))
	{
		u->x = 1;
		u->y = 0;
		u->z = 0;
	}
	cross_prod(u, &g_data.camera.normal, v);
}
