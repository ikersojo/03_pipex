/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:19:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/28 18:35:28 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

void	ft_child(char *str, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit_w_error();
	pid = fork();
	if (pid == -1)
		ft_exit_w_error();
	if (pid > 0)
	{
		ft_printf("Father process (pid %d) waiting for children to execute %s\n", pid, str);
		// close(*(fd + 1));
		// dup2(*(fd + 0), STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		ft_printf("Child process (pid %d) executing command %s\n", pid, str);
		// close(*(fd + 0));
		// dup2(*(fd + 1), STDOUT_FILENO);
		ft_run_command(str, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infd;
	int	outfd;
	int	i;

	if (argc == 5) // Cambiar a >= para bonus
	{
		infd = open(*(argv + 1), O_RDONLY);
		if (infd == -1)
			ft_exit_w_error();
		dup2(infd, STDIN_FILENO);
		outfd = open(*(argv + 4), O_CREAT | O_RDWR);
		i = 2;
		while (i < 4)
			ft_child(*(argv + i++), envp);
		// dup2(STDOUT_FILENO, outfd);
		close(infd);
		close(outfd); 
	}
	return (0);
}
