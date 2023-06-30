/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:28 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/29 16:48:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_coor3
{
	double	x;
	double	y;
	double	z;
}	t_coor3;

typedef struct s_coor2
{
	int	x;
	int	y;
}	t_coor2;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_camera
{
	t_coor3	coor;
	t_coor3	normal;
	double	fov;
}	t_camera;

typedef struct s_viewport
{
	double	width;
	double	height;
	double	distance;
}	t_viewport;

typedef struct t_mlx
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}	t_mlx;

typedef struct s_data
{
	t_mlx				mlx;
	t_camera		camera;
	t_viewport	viewport;
}	t_data;

#endif