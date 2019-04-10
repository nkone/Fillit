/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:53:23 by phtruong          #+#    #+#             */
/*   Updated: 2019/04/10 13:17:00 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct		s_tetris
{
	void			*tet_id;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]) {2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]) {1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JL_PIECE  (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]) {0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]) {1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]) {1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]) {1,0,0,1,1,1,0,2}
# define USAGE "usage:\t./fillit source_file\n"

int					pre_read(const int fd);
void				ft_exit(void);
char				*get_tetid(int *tab);
int					*trans_coord(int *tab);
int					dup_coord(int *dst, int *src);
int					*x_shift(int *tab, int x);
int					*y_shift(int *tab, int y);
int					*shift_tet(int *tab, int x, int y);
int					*one_tetris(const int fd, char *line);
char				**one_block(const int fd);
t_tetris			*store_tet(const int fd, char *line);
t_tetris			*append(void *tet_id, t_tetris *head, char c);
t_tetris			*add_piece(void *tet_id, char c);
t_tetris			*id_to_coord(t_tetris *stack);
int					*convert_id(char *id);
int					count_tet(t_tetris *stack);
int					start_size(t_tetris *stack);
char				**gen_grid(int size);
void				free_grid(char **grid, int size);
void				stck_free(t_tetris *stack);
void				stck_free_coord(t_tetris *stack);
void				clear_piece(char **grid, int *tet);
void				insert_piece(char **grid, int *tet, char c);
int					collision(char **grid, int *tet, int size);
int					help_solve(char **grid, int *tet, t_tetris *stck, int siz);
int					solve_tet(char **grid, t_tetris *stack, int size);
int					solve_driver(const int fd);

#endif
