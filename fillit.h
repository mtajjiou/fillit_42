/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:35:20 by gwood             #+#    #+#             */
/*   Updated: 2018/03/17 23:08:31 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

typedef struct			s_mino
{
	short				content;
	struct s_list		*next;
}						t_mino;

#endif
