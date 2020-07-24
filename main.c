//
// Created by Mari Ashley on 7/24/20.
//

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int			i;
	int			fd;
	int 		fd2;
	char		*line;
	char 		*line2;
	char 		**words;
	int 		a;
	int 		b;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		fd2 = open("author", O_RDONLY);
		a = get_next_line(fd, &line);
		b = get_next_line(fd2, &line2);
		while (a == 1 || b == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
			ft_putstr(line2);
			ft_putchar('\n');
			free(line2);
			a = get_next_line(fd, &line);
			b = get_next_line(fd2, &line2);
		}
		free(line);
		line = NULL;
		free(line2);
		line2 = NULL;
		close(fd);
		close(fd2);
	}
	words = ft_strsplit("10 20 30 04 05 06 07 08 09 0", ' ');
	ft_strdel(words);
	return (0);
}