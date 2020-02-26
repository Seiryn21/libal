#ifndef GNL_H
#define GNL_H

#include "libal.h"
#define GNL_BUFF_SIZE 256

typedef struct	s_gnl_fd
{
	int		fd;
	int		pos;
	int		len;
	char	*buffer;
}				t_gnl_fd;

int	get_next_line(const int fd, char **line);

#endif
