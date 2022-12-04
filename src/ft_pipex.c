/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:19:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/04 19:02:23 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

static void	ft_process(char *str, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
		ft_exit_w_error("errno");
	pid = fork();
	if (pid == -1)
		ft_exit_w_error("errno");
	if (pid > 0)
	{
		close(*(fd + 1));
		dup2(*(fd + 0), STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
	else
	{
		close(*(fd + 0));
		dup2(*(fd + 1), STDOUT_FILENO);
		ft_run_command(str, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infd;
	int	outfd;
	int	i;

	if (argc == 5)
	{
		infd = open(*(argv + 1), O_RDONLY);
		if (infd == -1)
			ft_exit_w_error("errno");
		dup2(infd, STDIN_FILENO);
		outfd = open(*(argv + 4), O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (outfd == -1)
			ft_exit_w_error("errno");
		i = 2;
		while (i < (argc - 2))
			ft_process(*(argv + i++), envp);
		dup2(outfd, STDOUT_FILENO);
		ft_run_command(*(argv + i), envp);
		close(infd);
		close(outfd);
	}
	else
		ft_exit_w_error("syntax: ./pipex infile cmd1 cmd2 outfile\n");
	return (EXIT_SUCCESS);
}
