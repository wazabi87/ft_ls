/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:46:22 by mleclair          #+#    #+#             */
/*   Updated: 2017/01/04 14:39:48 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	type(struct stat *buf)
{
	char ret;

	ret = '-';
	if (S_ISDIR(buf->st_mode) == 1)
		ret = 'd';
	else if (S_ISCHR(buf->st_mode) == 1)
		ret = 'c';
	else if (S_ISBLK(buf->st_mode) == 1)
		ret = 'b';
	else if (S_ISFIFO(buf->st_mode) == 1)
		ret = 'p';
	else if (S_ISLNK(buf->st_mode) == 1)
		ret = 'l';
	else if (S_ISSOCK(buf->st_mode) == 1)
		ret = 's';
	return (ret);
}

char	*droit(int mode, t_file *lsd)
{
	static char *str;

	if (!(str = malloc(12)))
		ft_err(-10, 0);
	ft_strcpy(str, "---------- \0");
	(mode & S_IRUSR) ? str[1] = 'r' : 0;
	(mode & S_IWUSR) ? str[2] = 'w' : 0;
	(mode & S_IXUSR) ? str[3] = 'x' : 0;
	(mode & S_IRGRP) ? str[4] = 'r' : 0;
	(mode & S_IWGRP) ? str[5] = 'w' : 0;
	(mode & S_IXGRP) ? str[6] = 'x' : 0;
	(mode & S_IROTH) ? str[7] = 'r' : 0;
	(mode & S_IWOTH) ? str[8] = 'w' : 0;
	(mode & S_IXOTH) ? str[9] = 'x' : 0;
	str[0] = lsd->type;
	return (str);
}

char	*ft_color(t_file *lsd, int i)
{
	if (i == 1)
	{
		if (lsd->type == 'd')
			return ("\e[0;36m");
		if (lsd->type == 'c')
			return ("\e[7;33m");
		if (lsd->type == 'b')
			return ("\e[0;32m");
		if (lsd->type == 'p')
			return ("\e[1;33m");
		if (lsd->type == 'l')
			return ("\e[0;35m");
		if (lsd->type == 's')
			return ("\e[0;32m");
	}
	return ("\e[0m");
}

void	lsd_null(t_file *lsd)
{
	lsd->acces = NULL;
	lsd->type = 0;
	lsd->nbf = 0;
	lsd->nbfconv = NULL;
	lsd->total = 0;
	lsd->group = NULL;
	lsd->size = 0;
	lsd->sizeconv = NULL;
	lsd->date = 0;
	lsd->name = NULL;
	lsd->path = NULL;
	lsd->next = NULL;
	lsd->prev = NULL;
	lsd->minor = 0;
	lsd->major = 0;
	lsd->owner = NULL;
}