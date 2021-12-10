#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s;
	int x;

	int fd = open("todo.txt", O_RDONLY);
	int fd1 = open("toinenTesti.txt", O_RDONLY);
	int fd2 = open("test1.txt", O_RDONLY);
	int fd3 = open("test2.txt", O_RDONLY);
	int fd4 = open("empty.txt", O_RDONLY);
	int fd5 = open("emptyline.txt", O_RDONLY);
	

	printf("-------\nTesting negative fd:\n%d\n", get_next_line(-5, &s));
	printf("-------\nTesting NULL **line:\n%d\n", get_next_line(1, 0));
	printf("-------\nBasic tests:\n");

	for (int i = 0; i < 2; i++)
	{
		x = get_next_line(fd, &s);
		printf("%d, %s\n", x, s);
	}
	printf("\n");



	while (1)
	{
		x = get_next_line(fd1, &s);
		
		printf("%d, %s\n", x, s);
		if (x <= 0)
			break ;
	}

	printf("-------\nTesting empty file:\n");
	x = get_next_line(fd4, &s);
	printf("%d, %s\n", x, s);

	printf("-------\nTesting file with just empty line:\n");
	x = get_next_line(fd5, &s);
	printf("%d, %s\n", x, s);
	x = get_next_line(fd5, &s);
	printf("%d, %s\n", x, s);	

	printf("-------\nTesting calling diff fd one after another:\n");
	get_next_line(fd2, &s);
	printf("%s\n",s);
	get_next_line(fd3, &s);
	printf("%s\n",s);
	get_next_line(fd2, &s);
	printf("%s\n",s);
	get_next_line(fd3, &s);
	printf("%s\n",s);

	printf("-------\nTesting stdin:\n");
	while (1)
	{
		get_next_line(1, &s);
		printf("%s\n",s);
	}
	




}