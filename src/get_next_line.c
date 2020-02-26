#include "libal.h"

static t_gnl_fd	*get_gnl_fd(int fd, t_list **fds)
{
	t_list		*lst;
	t_gnl_fd 	current;

	lst = *fds;
	while(lst)
	{
		current = *((t_gnl_fd*)lst->content);
		if(current.fd == fd)
			return ((t_gnl_fd*)lst->content);
	}
	current.fd = fd;
	current.pos = 0;
	current.buffer = NULL;
	lst = al_lstnew(&current, sizeof(t_gnl_fd));
	al_lstadd(fds, lst);
}

static int		char_to_append(t_gnl_fd *gnl)
{
	int i;

	i = gnl->pos;
	if(gnl->buffer == NULL)
		return (0);
	while(i < gnl->len && gnl->buffer[i] != '\n')
		i++;
	if(i == gnl->len)
		return (0);
	return (i - gnl->pos);
}

int	get_next_line(const int fd, char **line)
{
	int				append;
	char			*tmp;
	char			*ret;
	t_gnl_fd		*current;
	static t_list 	*fds = NULL;

	ret = NULL;
	current = get_gnl_fd(fd, &fds);
	while(current->len != 0 && (append = char_to_append(current)) == 0)
	{
		tmp = ret;
		ret = al_strjoin(ret, current->buffer);
		if(tmp != NULL)
			free(tmp);
		if(current->buffer != NULL)
			free(current->buffer);
		current->buffer = al_strnew(GNL_BUFF_SIZE);
		current->len = read(fd, current->buffer, GNL_BUFF_SIZE);
	}
	tmp = ret;
	ret = al_strnjoin(ret, current->buffer, append);
	current->pos += append + 1;
	free(tmp);
	*line = ret;
	return (current->len != 0);
}
