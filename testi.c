
#include "get_next_line.h"
#include <stdio.h>


int	read_buf(char *arr[FD_SIZE], const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	if (read(fd, buf, 0) < 0)
		return (-1);
	if ((bytes_read = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	if (ft_count_delimited_words(buf, '\n') < 2)
	{
		if (*line == NULL)
			*line = ft_strdup(buf);
		else
			*line = ft_strjoin(*line, buf);
	}

	
	return (0);
}


int			get_next_line(const int fd, char **line)
{
	static char	*arr[FD_SIZE];

	*line = NULL;

	read_buf(arr, fd, line);
	read_buf(arr, fd, line);	

	return (0);	





}




int main(void)
{
	char *s;
	//int x;

	int fd = open("todo.txt", O_RDONLY);
	//int fd1 = open("toinenTesti.txt", O_RDONLY);
	
	get_next_line(fd, &s);

	printf("%s\n", s);

	/*
	printf("File 1:\n");
	while (1)
	{

		x = get_next_line(fd, &s);
		
		printf("%d, %s\n", x, s);
		if (x <= 0)
			break ;

	}
	printf("-----\nFile 2:\n");	
	while (1)
	{
		x = get_next_line(fd1, &s);
		printf("%d, %s\n", x, s);
		if (x <= 0)
			break ;
	}
			
*/


}

