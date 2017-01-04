/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:20:30 by mleclair          #+#    #+#             */
/*   Updated: 2017/01/04 11:09:36 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <pwd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <errno.h>
# include <grp.h>
# include "./libft/libft.h"

typedef struct		s_truc
{
	int				flag_rr;
	int				flag_l;
	int				flag_a;
	int				flag_r;
	int				flag_t;
	int				flag_tt;
}					t_truc;

typedef struct		s_file
{
	char			*acces;
	char			type;
	int				nbf;
	char			*nbfconv;
	char			*owner;
	int				total;
	char			*group;
	int				size;
	char			*sizeconv;
	char			*name;
	long int		date;
	char			*path;
	int				major;
	int				minor;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

void				list_free_inner(t_file *lst);
void				flag_r(t_truc *parse, char *path);
void				ls_core(t_truc *parse, char *av, t_file **lsd);
void				ft_lstsort(t_truc *parse, t_file *lst, int i);
void				print_l(t_file *lst, t_truc *parse);
char				*ft_strrev(char *str);
int					ft_err(int i, char *tmp);
void				list_free(t_file *lst);
char				*ft_color(t_file *lsd, int i);

void				print_l_reverse(t_file *lst, t_truc *parse);

#endif
