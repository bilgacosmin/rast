/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:41:48 by cbilga            #+#    #+#             */
/*   Updated: 2019/01/24 15:23:46 by cbilga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"
#include "../includes/libft.h"

double	rad_deg(double radians) 
{
    return radians * (180.0 / M_PI);
}

double	deg_rad(double degrees)
{
	return degrees * (M_PI / 180);
}

/**

on utilise cette partie pour faire des rotation de vertex et du scaling
\/
100 0 -> on utilise cela pour faire les translations
010 0
001 0

0001 - on s'en fou de cette ligne


1000
0100   = matrice qui ne fait rien
0010
0001

**/

t_vec	*vec_init(double x, double y, double z, double w)
{
	t_vec	*vertex;

	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	vertex->w = w;
	return (vertex);
}

void	vec_mod(t_vec *vertex, double x, double y, double z)
{
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
}

t_mat	*mat_ident()
{
	t_mat *mat;

	if (!(mat = (t_matx*)malloc(sizeof(t_mat))))
		return (NULL);
	mat->mat[0][0] = 1;
	mat->mat[1][0] = 0;
	mat->mat[2][0] = 0;
	mat->mat[3][0] = 0;
	mat->mat[0][1] = 0;
    mat->mat[1][1] = 1;
    mat->mat[2][1] = 0;
    mat->mat[3][1] = 0;
	mat->mat[0][2] = 0;
    mat->mat[1][2] = 0;
    mat->mat[2][2] = 1;
    mat->mat[3][2] = 0;
	mat->mat[0][3] = 0;
    mat->mat[1][3] = 0;
    mat->mat[2][3] = 0;
    mat->mat[3][3] = 1;
	return mat;
}

void	vec_x_mat(t_vec	*vertex, t_mat *mat)
{

/**
    Multiplication d'un vertex avec les coordonees x,y,z par une matrice.

    x       a0 a1 a2 a3        x' = a0 * x + a1 * y + a2 * z + a3
	y  *    b0 b1 b2 b3   ==>  y' = b0 * x + b1 * y + b2 * z + b3
	z       c0 c1 c2 c3        z' = c0 * x + c1 * y + c2 * z + c3
	        d0 d1 d2 d3
**/
	vertex->x = mat->mat[0][0] * vertex->x + mat->mat[1][0] * vertex->y + mat->mat[2][0] * vertex->z + mat->mat[3][0] * vertex->w;
	vertex->y = mat->mat[0][1] * vertex->x + mat->mat[1][1] * vertex->y + mat->mat[2][1] * vertex->z + mat->mat[3][1] * vertex->w;
	vertex->z = mat->mat[0][2] * vertex->x + mat->mat[1][2] * vertex->y + mat->mat[2][2] * vertex->z + mat->mat[3][2] * vertex->w;
	vertex->w = mat->mat[0][3] * vertex->x + mat->mat[1][3] * vertex->y + mat->mat[2][3] * vertex->z + mat->mat[3][3] * vertex->w;
}

void	mat_trans(t_matrix *mat, double x, double y, double z)
{
	mat->mat[3][0] += x;
	mat->mat[3][1] += y;
	mat->mat[3][2] += z;
}

void	mat_scale(t_mat *mat, double scale)
{
	mat->mat[0][0] *= scale;
	mat->mat[1][1] *= scale;
	mat->mat[2][2] *= scale;
}

void 	mat_xrot(t_mat *mat,double angle)
{
	/** 1 0 0 0
		0 cos sin 0
		0 -sin cos 0
        0 0 0 1
	**/

    mat->mat[1][1] = cos(deg_rad(angle));
    mat->mat[2][1] = sin(deg_rad(angle));
    mat->mat[1][2] = -sin(deg_rad(angle));
    mat->mat[2][2] = cos(deg_rad(angle));
}

void	mat_yrot(t_mat *mat, double angle)
{
    /** cos 0 -sin 0
        0 1 0 0
        sin 0 cos 0
        0 0 0 1
	**/

    mat->mat[0][0] = cos(deg_rad(angle));
    mat->mat[2][0] = -sin(deg_rad(angle));
    mat->mat[0][2] = sin(deg_rad(angle));
    mat->mat[2][2] = cos(deg_rad(angle));
}

void 	mat_zrot(t_mat *mat, double angle)
{
    /** cos -sin 0 0
        sin cos 0 0
        0 0 1 0
        0 0 0 1
	**/

    mat->mat[0][0] = cos(deg_rad(angle));
    mat->mat[1][0] = -sin(deg_rad(angle));
    mat->mat[0][1] = sin(deg_rad(angle));
    mat->mat[1][1] = cos(deg_rad(angle));
}

void	mat_mult(t_matrix *mat1, t_matrix *mat2, t_mat *res)
{
	int a;
	int b;
	inc c;

	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			c = 0;
			while (c < 4)
			{
				res->mat[a][b] += mat1->mat[a][c] * mat2->mat[c][b];
				c++;
			}
			b++;
		}
		a++;
	}
}

void	mat_print(t_matrix *mat)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			ft_putnbr(mat->mat[b][a]);
			ft_putchar(' ');
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}
