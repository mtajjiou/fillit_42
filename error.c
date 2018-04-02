/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajjiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:52:26 by mtajjiou          #+#    #+#             */
/*   Updated: 2018/04/02 15:52:28 by mtajjiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage_msg(void)
{
	ft_putendl("usage: ./fillit [input_file]");
	exit(1);
}

void	error_msg(void)
{
	ft_putendl("error");
	exit(1);
}
