

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

#define BUFF_SIZE	32

/*typedef struct str_list
{
	char			*str;
	unsigned int	bytes_read;
	struct str_list	*next;
}				str_list;*/

typedef struct	lstring
{
	char			c;
	struct lstring	*next;
}				lstring;

int	get_next_line(const int fd, char **line);



#endif