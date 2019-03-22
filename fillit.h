/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:53:23 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/21 18:26:08 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

typedef struct tetris
{
	char *name;
	struct tetris *next;
} stck_tet;

# define I_PIECE (int [8]) {0,3,0,2,0,1,0,0}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,1,1,1,0,0,1,0}
# define L_PIECE (int [8]) {0,2,0,1,0,0,1,0}
# define LR_PIECE (int [8]) {0,1,1,1,2,1,0,0}
# define LD_PIECE (int [8]) {0,2,1,2,1,1,1,0}
# define LL_PIECE (int [8]) {2,1,0,0,1,0,2,0}
# define J_PIECE (int [8]) {1,2,1,1,1,0,0,0}
# define JR_PIECE (int [8]) {0,1,0,0,1,0,2,0}
# define JD_PIECE (int [8]) {0,2,1,2,0,1,0,0}
# define JL_PIECE  (int [8]) {0,1,1,1,2,1,2,0}
# define T_PIECE (int [8]) {1,1,0,0,1,0,2,0}
# define TR_PIECE (int [8]) {0,2,0,1,1,1,0,0}
# define TD_PIECE (int [8]) {0,1,1,1,2,1,1,0}
# define TL_PIECE (int [8]) {1,2,0,1,1,1,1,0}
# define S_PIECE (int [8]) {1,1,2,1,0,0,1,0}
# define SR_PIECE (int [8]) {0,2,0,1,1,1,1,0}
# define Z_PIECE (int [8]) {0,1,1,1,1,0,2,0}
# define ZR_PIECE (int [8]) {1,2,0,1,1,1,0,0}

int					pre_read(const int fd);
void				ft_exit();	
char				*get_tetID(int *tab);
int					*trans_coord(int *tab);
int					*one_tetris(const int fd, char *line);

#endif
