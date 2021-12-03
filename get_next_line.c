
#include "get_next_line.h"
#include <stdio.h>

static	int	read_fd(const int fd, char **line, char *str_arr[FD])
{
	int	i;

	i = 0;

}

static	int read_buffer(const int fd, char **line, char *str_arr[FD])
{
	char	buf[BUFF_SIZE];
	int		bytes_read;

	if (read(fd, buf, 0) < 0)
		return (-1);
	
}


int			get_next_line(const int fd, char **line)
{
	static char	*str_arr[FD];

	if (!str_arr[fd])
		return (read_buffer(fd, line, str_arr));
	return (read_fd(fd, line, str_arr));
}


int main(void)
{
	char **s;

	int fd = open("todo.txt", O_RDONLY);
	int fd1 = open("toinenTesti.txt", O_RDONLY);
	get_next_line(fd, s);
	printf("%s\n", *s);	
	get_next_line(fd1, s);
	printf("%s\n", *s);		
	get_next_line(fd, s);
	printf("%s\n", *s);		
	get_next_line(fd1, s);
	printf("%s\n", *s);		



	return (0);

	//printf("%d\n", fd);
}