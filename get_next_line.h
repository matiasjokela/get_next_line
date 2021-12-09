

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

#define BUFF_SIZE	1
# define FD_SIZE	4096

typedef struct lstr
{
	char		c;
	struct lstr	*next;
	struct lstr	*prev;
}					lstr;


int	get_next_line(const int fd, char **line);



#endif