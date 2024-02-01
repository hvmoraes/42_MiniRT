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

typedef	struct s_vec3
{
	float		x;
	float		y;
	float		z;
}	t_vec3;

typedef struct	s_vec2
{
	float		x;
	float		y;
}	t_vec2;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		*addr;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct s_sphere
{
	float		radius;
	t_vec3		color;
	int			int_color;
	t_vec3		center;
}	t_sphere;

typedef struct s_camera
{
	t_vec3		center;
	t_vec3		normal;
	float		fov;
}	t_camera;

typedef	struct s_objs
{
}	t_objs;

typedef	struct s_viewport
{
	float		width;
	float		height;
	float		distance;
}	t_viewport;

typedef struct s_data
{
	t_sphere	*spheres;
	int			total_spheres;
	int			total_cameras;
	t_mlx		*mlx;
}	t_data;

#endif
