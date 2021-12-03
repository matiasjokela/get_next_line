
#include "get_next_line.h"
#include <stdio.h>

int loppu = 0;
static	int	read_fd(const int fd, char **line, char *str_arr[FD], int end);


static	int read_buffer(const int fd, char **line, char *str_arr[FD], int end)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	if (read(fd, buf, 0) < 0)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		tmp = ft_strjoin(str_arr[fd], buf);
		//ft_bzero(str_arr[fd], ft_strlen(str_arr[fd]));	
		free(str_arr[fd]);
		str_arr[fd] = ft_strdup(tmp);
		free(tmp);
		//printf("In array: %s\n", str_arr[fd]);
		//printf("Read_buffer, return read_fd\n");
		if (end == 1)
			return (read_fd(fd, line, str_arr, end));
	}
	end = 0;
	str_arr[FD] = "End";
	loppu = 1;
	read_fd(fd, line, str_arr, end);
	return (0);
}

static	int	read_fd(const int fd, char **line, char *str_arr[FD], int end)
{
	int		i;
	char	*tmp;

	i = 0;

	while (str_arr[fd][i])
	{
		if (str_arr[fd][i] == '\n')
		{
			str_arr[fd][i] = '\0';
			*line = ft_strdup(str_arr[fd]);
			tmp = ft_strdup(&(str_arr)[fd][i + 1]);
			free(str_arr[fd]);
			str_arr[fd] = ft_strdup(tmp);
			free(tmp);
			//printf("Read_fd, return 1\n");
			return (8);	
		}
		i++;
	}
	if (end == 0)
	{
			*line = ft_strdup(str_arr[fd]);
			tmp = ft_strdup(str_arr[fd]);
			free(str_arr[fd]);
			str_arr[fd] = ft_strdup(tmp);
			free(tmp);
			printf("Ollaan taalla\n");

	}
	//printf("Read_fd, return read_buffer\n");
	if (end != 0)
		read_buffer(fd, line, str_arr, end);
	printf("end: %d\n", end);
	return (end);
}




int			get_next_line(const int fd, char **line)
{
	static char	*str_arr[FD];

	str_arr[FD] = "No end";
	int			end;
	end = 1;

	read_buffer(fd, line, str_arr, end);


	printf("%s\n", str_arr[FD]);
	if (loppu == 1)
		return (0);
	return (1);
}


int main(void)
{
	char **s;

	int fd = open("todo.txt", O_RDONLY);
	int fd1 = open("toinenTesti.txt", O_RDONLY);
	
	printf("File 1:\n");
	for (int i = 0; i < 3; i++)
	{
		int x = get_next_line(fd, s);
		printf("%d, %s\n", x, *s);
	}
			



	return (0);

	//printf("%d\n", fd);
}