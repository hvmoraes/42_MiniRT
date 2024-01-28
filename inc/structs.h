/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:49:44 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 11:49:44 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef	struct	s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_sphere
{
	float	radius;
	t_color	color;
}	t_sphere;

typedef	struct s_objs
{
	t_sphere	*spheres;
}	t_objs;

typedef struct s_data
{
	t_objs	*objs;
	t_mlx 	*mlx;
}	t_data;

#endif