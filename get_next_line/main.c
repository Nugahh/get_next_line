#include <stdio.h>
#include "get_next_line.h"

/* int    main(int argc, char **argv)
{
    char    *str;
    int        fd;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
	while (1){
		str = get_next_line(fd);
        printf("%s", str);
        free(str);
		if (str == NULL)
			break;
	}
    return (0);
} */

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}