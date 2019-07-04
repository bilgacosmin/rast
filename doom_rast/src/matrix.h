/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:33:51 by cbilga            #+#    #+#             */
/*   Updated: 2018/12/17 13:26:19 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <math.h>
typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
	double 	w;
}				t_vec;

typedef	struct	s_matrix
{
	double	mat[4][4];
}				t_matrix;

double			rad_deg(double radians);
double			deg_rad(double degrees);
t_vertex		*vert_init(double x, double y, double z);
void			vert_mod(t_vertex *vertex, double x, double y, double z);
t_matrix		*mat_init();
void			vert_x_mat(t_vertex *vertex, t_matrix *mat);
void			mat_move(t_matrix *mat, double x, double y, double z);
void			mat_scale(t_matrix *mat, double scale);
t_matrix		*mat_xrot(double angle);
t_matrix		*mat_yrot(double angle);
t_matrix		*mat_zrot(double angle);
void			mat_mult(t_matrix *mat1, t_matrix *mat2);
void			mat_print(t_matrix *mat);
#endif
