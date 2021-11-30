
#include "get_next_line.h"
#include <stdio.h>

static lstring	*new_node()
{
	lstring	*node;

	node = (lstring *)malloc(sizeof(lstring));
	node->c = '\0';
	node->next = NULL;
	return (node);
}

static void	free_nodes(lstring *head)
{
	if (head != NULL)
		free_nodes(head->next);
	free(head);
}


int		get_next_line(const int fd, char **line)
{
	char			buf[1];
	unsigned int	linelen;
	lstring			*head;
	lstring			*tmp;
	char			*oneline;

	linelen = 0;
	tmp = new_node();
	head = tmp;
	if (read(fd, buf, 0) < 0)
		return (-1); // What if read returns 0
	while (read(fd, buf, 1) > 0)
	{
		if (buf[0] == '\n')
			break ;
		tmp->c = buf[0];
		tmp->next = new_node();
		tmp = tmp->next;
		linelen++;
	}
	tmp = head;
	/*line = (char **)malloc(sizeof(char *));
	if (line == NULL)
		return (-1);*/
	oneline = (char *)malloc(sizeof(char) * linelen + 1);
	if (oneline == NULL)
		return (-1);  // Must free line, make a function
	linelen = 0;
	while (tmp->c != '\0')
	{
		oneline[linelen] = tmp->c;
		tmp = tmp->next;
		linelen++;
	}
	oneline[linelen] = '\0';
	*line = oneline;
	free_nodes(head);	

	


	return(0); // Miten meni returnit??
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
	get_next_line(1, s);
	printf("%s\n", *s);		

	return (0);

	//printf("%d\n", fd);
}