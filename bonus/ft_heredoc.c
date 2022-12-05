/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:40:04 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/05 22:49:23 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

static char	*ft_get_input(void)
{
	char	c;
	int		bytes;
	char	*line;
	int		i;

	line = (char *)malloc(400);
	bytes = read(0, &c, 1);
	i = 0;
	while (bytes > 0 && c != '\0')
	{
		*(line + i++) = c;
		if (c == '\n')
			break ;
		bytes = read(0, &c, 1);
	}
	*(line + i) = '\0';
	return (line);
}

// ft_checkline(*(argv + 2), *(fd + 1))

static void	ft_checkline(char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		line = ft_get_input();
		if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
		{
			free (line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd);
		free (line);
	}
}

void	ft_heredoc(char **argv)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit_w_error("errno");
	pid = fork();
	if (pid == -1)
		ft_exit_w_error("errno");
	if (pid > 0)
	{
		close(*(fd + 1));
		dup2(*(fd + 0), STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(*(fd + 0));
		ft_checkline(*(argv + 2), *(fd + 1));
	}
}
