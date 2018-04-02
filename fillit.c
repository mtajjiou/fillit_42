/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajjiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:51:13 by mtajjiou          #+#    #+#             */
/*   Updated: 2018/04/02 15:51:17 by mtajjiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:34:45 by gwood             #+#    #+#             */
/*   Updated: 2018/03/19 14:23:04 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_mino(short mino)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_itoa_base((int)mino, 2);
	if (mino < 256)
		ft_putstr("0000\n0000\n");
	while (s[i])
	{
		ft_putchar(s[i]);
		if (i != 0 && (i + 1) % 4 == 0)
			ft_putchar('\n');
		i++;
	}
}

static void	shift_mino(short *mino, int dir, int dist)
{
	if (dir == UP)
		*mino = *mino << 4 * dist;
	if (dir == DOWN)
		*mino = *mino >> 4 * dist;
	if (dir == LEFT)
		*mino = *mino << 1 * dist;
	if (dir == RIGHT)
		*mino = *mino >> 1 * dist;
}

static short build_mino(char *s)
{
	int		i;
	short	mino;
	
	i = 0;
	mino = 0;
	while (s[i])
	{
		
		if (s[i] == '.' || s[i] == '#')
		{
			mino = mino << 1;
			if (s[i] == '#')
				mino += 1;
		}
		else if (s[i] != '\n')
			return (0);
		i++;
	}
	ft_putchar('\n');
	return (mino);
}

int		main()
{
	char	*str;
	short	mino;

	str = "....\n....\n..#.\n.###\n";
	mino = build_mino(str);

	ft_putendl(str);
	print_mino(mino);
	ft_putchar('\n');
	shift_mino(&mino, UP, 2);
	shift_mino(&mino, LEFT, 1);
	print_mino(mino);
}
