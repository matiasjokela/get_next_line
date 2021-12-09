

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

#define BUFF_SIZE	8
# define FD_SIZE	4096




int	get_next_line(const int fd, char **line);



#endif