
#include "get_next_line.h"
#include <stdio.h>




int		get_next_line(const int fd, char **line)
{
	static char	*str_arr[FD_INDEX];
	char		buf[BUFF_SIZE + 1];
	long		bytes_read;
	int 		i;

	bytes_read = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
	str_arr[0] = ft_strjoin("", str_arr[fd]);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		if (bytes_read < 0)
			return (-1);
		while (i < bytes_read)
		{
			if (buf[i] == '\n')
			{
				buf[i] = '\0';
				str_arr[0] = ft_strjoin(str_arr[0], buf);
				str_arr[fd] = ft_strjoin("", (&(buf))[i + 1]);
				*line = str_arr[0];
				//ft_bzero(str_arr[0], ft_strlen(str_arr[0]));
				return (0);
			}
			str_arr[0] = ft_strjoin(str_arr[0], buf);
			i++;
		}
	}
	return (-1);
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