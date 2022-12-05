/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:19:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/05 22:42:22 by isojo-go         ###   ########.fr       */
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

int	ft_openfiles(int argc, char **argv, int *infd, int *outfd)
{
	int		bonus;
	char	*opath;

	if (ft_strcmp("here_doc", *(argv + 1)) == 0)
		bonus = 3;
	else
	{
		bonus = 2;
		*infd = open(*(argv + 1), O_RDONLY);
		if (*infd == -1)
			ft_exit_w_error("errno");
	}
	opath = *(argv + (argc - 1));
	if (ft_strcmp("here_doc", *(argv + 1)) == 0)
		*outfd = open(opath, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		*outfd = open(opath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (*outfd == -1)
		ft_exit_w_error("errno");
	return (bonus);
}

int	main(int argc, char **argv, char **envp)
{
	int	infd;
	int	outfd;
	int	i;

	if (argc >= 5)
	{
		i = ft_openfiles(argc, argv, &infd, &outfd);
		if (i == 3)
			ft_heredoc(argv);
		else
			dup2(infd, STDIN_FILENO);
		while (i < (argc - 2))
			ft_process(*(argv + i++), envp);
		dup2(outfd, STDOUT_FILENO);
		ft_run_command(*(argv + i), envp);
		close(outfd);
		if (ft_strcmp("here_doc", *(argv + 1)) == 0)
			close(infd);
	}
	else
		ft_exit_w_error("Wrong syntax\n");
	return (EXIT_SUCCESS);
}
