

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

#define BUFF_SIZE	1
#define FD			4096

typedef struct	lstring
{
	char			c;
	struct lstring	*next;
}				lstring;

int	get_next_line(const int fd, char **line);



#endif