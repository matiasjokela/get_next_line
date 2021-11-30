
#include "get_next_line.h"
#include <stdio.h>

static str_list	*add_str_node(void)
{
	str_list	*node;
	char		string[BUFF_SIZE];

	node = (str_list *)malloc(sizeof(str_list));
	if (node == NULL)
		return (NULL);
	ft_bzero(string, BUFF_SIZE);
	node->str = string;
	node->bytes_read = 0;
	node->next = NULL;
	return (node);
}


int	get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE];
	unsigned int	total_bytes;
	str_list		*list;
	str_list		*tmp;

	total_bytes = 0;
	tmp = add_str_node();
	if (tmp == NULL)
		return (-1);
	list = tmp;
	while ((tmp->bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		//ft_strcpy(tmp->str, buf);
		for (int i = 0; i < tmp->bytes_read; i++)
		{
			(tmp->str)[i] = buf[i];
			//printf("i: %d\ntmp: %c \nbuf: %c\n---\n", i, (tmp->str)[i], buf[i]);
		}

		for (int i = 0; i < tmp->bytes_read; i++)
		{
			//(tmp->str)[i] = buf[i];
			printf("i: %d\ntmp: %c \nbuf: %c\n---\n", i, (tmp->str)[i], buf[i]);
		}

		total_bytes += tmp->bytes_read;
		tmp->next = add_str_node();
		tmp = tmp->next;

	}

	return(0);
}


int main(void)
{
	char **s;

	int fd = open("todo.txt", O_RDONLY);
	get_next_line(fd, s);

	//printf("%d\n", fd);
}