
#include "get_next_line.h"
#include <stdio.h>

static lstr	*new_node(void)
{
	lstr	*node;

	node = (lstr *)malloc(sizeof(lstr));
	node->c = '\0';
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	free_nodes(lstr *head)
{
	if (head != NULL)
		free_nodes(head->prev);
	free(head);
}

int read_leftover(char **line, int fd, lstr	*arr)
{
	;
}

int	get_next_line(const int fd, char **line)
{
	
	static lstr	*arr[FD_SIZE];
	lstr		*head;

	*line = NULL;


	


	return (0);

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

