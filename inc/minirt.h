/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:06:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/12/19 10:18:04 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../Libft/inc/libft.h"
# include "../mlx/mlx.h"
# include "structs.h"
# include "enums.h"

# define WIDTH 800
# define HEIGHT 600
# define INF 10000
# define BACK_COLOR 0x00000000

extern t_data	g_data;

/*    draw/ray.c    */

void	draw(void);

/*    init/init_camera.c    */

int		init_camera(char **line);
void	canvas_viewport(int x, int y, t_coor3 *point);

/*    init/init.c    */

void	init_data(char **argv);
void	init_scene(void);

/*    init/utils.c    */

int		line_fields(char **line);
int		is_zero(double nbr);
void	set_vectors(t_coor3 *u, t_coor3 *v);
int		parse_error(char *error);

/*    objects/object.c    */

void	add_object(t_object *object);

/*    objects/sphere.c    */

double	intersect_sphere(t_coor3 camera_origin, t_coor3 viewport_point,
			t_sphere sphere);
int		add_sphere(char **line);

/*    end/error.c    */

void	handle_error(char *error);

/*    end/free.c    */

void	free_matrix(char **matrix);
void	free_all(int flag);
void	free_objects(void);
void	end(void);

/*    utils/coords.c    */

int		check_coords(char *coords, t_coor3 *camera);
int		check_normal(char *normal, t_coor3 *normal_final);

/*    utils/color.c    */

int		check_color(char *color, t_color *color_final);
void	pixel_put(t_mlx *mlx, int x, int y, int color);

/*    utils/math.c    */

double	to_rad(int deg);
double	quadratic(double a, double b, double c);

/*    utils/vectors.c    */

double	vec_size(t_coor3 vec);
void	cross_prod(t_coor3 *u, t_coor3 *v, t_coor3 *w);
double	dot(t_coor3 *u, t_coor3 *v);
t_coor3	subtract(t_coor3 u, t_coor3 v);
t_coor3	normalize(t_coor3 vector);

/*    utils/extra.c    */

int		is_number(char *str);

#endif
