

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

#define BUFF_SIZE	2
#define FD_INDEX	4096

/*typedef struct	lstring
{
	char			c;
	struct lstring	*next;
}				lstring;*/

int	get_next_line(const int fd, char **line);



#endif