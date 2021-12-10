#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s;
	int x;

	int fd = open("todo.txt", O_RDONLY);
	int fd1 = open("toinenTesti.txt", O_RDONLY);
	

	for (int i = 0; i < 15; i++)
	{
		x = get_next_line(6, &s);
		printf("%d, %s\n", x, s);
	}




	
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