
#include "get_next_line.h"
#include <stdio.h>

int	check_arr(char *arr[FD_SIZE], int fd, char **line);

int	read_buf(char *arr[FD_SIZE], const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if (read(fd, buf, 0) < 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		tmp = ft_strchr(buf, '\n');
		if (tmp == NULL)
		{
			if (*line == NULL)
				*line = ft_strdup(buf);
			else
				*line = ft_strjoin(*line, buf);
		}
		else
		{
			tmp[0] = '\0';
			*line = ft_strjoin(*line, buf);
			tmp++;
			if (tmp[0] != '\0')
				arr[fd] = ft_strdup(tmp);
			return (1);
		}
	}
	//printf("jälel: %s\n", arr[fd]);
	
	return (0);
}

int	check_arr(char *arr[FD_SIZE], int fd, char **line)
{
	char	*tmp;

	if (arr[fd] == NULL)
		return (read_buf(arr, fd, line));
	tmp = ft_strchr(arr[fd], '\n');
	if (tmp == NULL)
	{
		*line = ft_strdup(arr[fd]);
		ft_bzero(arr[fd], 20);
		return (read_buf(arr, fd, line));
	}
	tmp[0] = '\0';
	*line = ft_strdup(arr[fd]);
	tmp++;
	//ft_bzero(arr[fd], 20);
	//free(arr[fd]);
	arr[fd] = tmp;
	return (1);
	
}


int	get_next_line(const int fd, char **line)
{
	static char	*arr[FD_SIZE];

	*line = NULL;


	return (check_arr(arr, fd, line));







}




int main(void)
{
	char *s;
	int x;

	int fd = open("todo.txt", O_RDONLY);
	//int fd1 = open("toinenTesti.txt", O_RDONLY);
	

	for (int i = 0; i < 4; i++)
	{
		x = get_next_line(fd, &s);
		printf("%d, %s\n", x, s);
	}




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

