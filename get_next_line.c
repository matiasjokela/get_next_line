
#include "get_next_line.h"
#include <stdio.h>




int		get_next_line(const int fd, char **line)
{
	static char	*str_arr[FD_INDEX];
	char		buf[BUFF_SIZE + 1];


	
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