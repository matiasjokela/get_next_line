
#include "get_next_line.h"
#include <stdio.h>




static void	read_buffer(const int fd, char *str_arr[FD])
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	if (read(fd, buf, 0) < 0)
	{
		str_arr[FD - 1] = "-1";
		str_arr[FD - 2] = "1";	
		return ;
	}
	
	ft_bzero(buf, BUFF_SIZE + 1);
	bytes_read = read(fd, buf, BUFF_SIZE);
	tmp = ft_strjoin(str_arr[fd], buf);
	free(str_arr[fd]);
	str_arr[fd] = ft_strdup(tmp);
	free(tmp);
	if (bytes_read == 0)
		str_arr[FD - 3] = "1";

}

static void	read_fd(const int fd, char **line, char *str_arr[FD])
{
	int		i;
	char	*tmp;

	i = 0;
	while ((str_arr[fd]) && str_arr[fd][i])
	{
		if (str_arr[fd][i] == '\n')
		{
			str_arr[fd][i] = '\0';
			*line = ft_strdup(str_arr[fd]);
			tmp = ft_strdup(&(str_arr)[fd][i + 1]);
			free(str_arr[fd]);
			str_arr[fd] = ft_strdup(tmp);
			free(tmp);
			str_arr[FD - 2] = "1";
			return ;
		}
		i++;
	}
}

static void	read_last_fd(const int fd, char **line, char *str_arr[FD])
{
	int		lines;

	lines = ft_count_delimited_words(str_arr[fd], '\n');
	if (lines == 0)
	{
		if (str_arr[fd][0] == 0)
			*line = NULL;
		else
			*line = ft_strdup(str_arr[fd]);
		str_arr[FD - 1] = "0";	
		str_arr[FD - 2] = "1";
		str_arr[FD - 3] = "2";
		return ;
	}
	read_fd(fd, line, str_arr);
	/**line = ft_strdup(str_arr[fd]);


	tmp = ft_strdup(str_arr[fd]);
	free(str_arr[fd]);
	str_arr[fd] = ft_strdup(tmp);
	free(tmp);
	str_arr[FD - 2] = "1";*/


}


int			get_next_line(const int fd, char **line)
{
	static char	*str_arr[FD];



	str_arr[FD - 1] = "1"; // return value
	str_arr[FD - 2] = "0"; // found line
	if (!str_arr[FD - 3])
		str_arr[FD - 3] = "0"; // Reached EOF 0 no, 1 yes, 2 last line returned


	if (ft_atoi(str_arr[FD - 3]) == 2)
	{
		*line = NULL;
		str_arr[FD - 3] = "0";
		return (0);
	}



	while (ft_atoi(str_arr[FD - 2]) == 0)
	{
		if (ft_atoi(str_arr[FD - 3]) == 1)
			read_last_fd(fd, line, str_arr);
		else
		{
			read_buffer(fd, str_arr);
			read_fd(fd, line, str_arr);
		}
	} 

	return (ft_atoi(str_arr[FD - 1]));

}


int main(void)
{
	char *s;
	int x;

	int fd = open("todo.txt", O_RDONLY);
	int fd1 = open("toinenTesti.txt", O_RDONLY);
	
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
			



}

