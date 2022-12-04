/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:25:48 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/04 17:35:13 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pipex.h"

void	ft_exit_w_error(char *str)
{
	if (ft_strcmp("errno", str) == 0)
	{
		perror("\033[31mError");
		ft_putstr_fd("\033[0;39m", 2);
	}
	else
	{
		ft_putstr_fd("\033[31mError: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0;39m", 2);
	}
	exit(EXIT_FAILURE);
}

static char	*ft_get_path(char *cmd, char **envp)
{
	int		i;
	char	**path_tab;
	char	*path;
	char	*aux;

	i = 0;
	while (ft_strnstr(*(envp + i), "PATH", 4) == NULL)
		i++;
	path_tab = ft_split(*(envp + i), ':');
	i = 0;
	while (*(path_tab + i))
	{
		aux = ft_strjoin(*(path_tab + i), "/");
		path = ft_strjoin(aux, cmd);
		free (aux);
		free (*(path_tab + i++));
		if (access(path, F_OK) == 0)
			break ;
	}
	while (*(path_tab + i))
		free (*(path_tab + i++));
	free (path_tab);
	return (path);
}

void	ft_space_to_tab(char **arg)
{
	char	*str;

	str = *arg;
	while (*str)
	{
		if (*str == 34 || *str == 39)
		{
			while (*str && (*str != 34 || *str != 39))
			{
				if (*str == ' ')
					*str = 9;
				str++;
			}
		}
		str++;
	}
}

static void	ft_tab_to_space(char **arg)
{
	char	*str;
	int		i;
	int		len;

	str = *arg;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == 9)
			*(str + i) = ' ';
		i++;
	}
	len = i;
	if (*str == 34 || *str == 39)
	{
		i = 0;
		while (i < (len - 2))
		{
			*(str + i) = *(str + i + 1);
			i++;
		}
		*(str + i) = '\0';
	}
}

void	ft_run_command(char *arg, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		i;
	int		error_flag;

	error_flag = 0;
	ft_space_to_tab(&arg);
	cmd = ft_split(arg, ' ');
	i = 0;
	while (*(cmd + i))
		ft_tab_to_space((cmd + i++));
	cmd_path = ft_get_path(*(cmd + 0), envp);
	if (execve(cmd_path, cmd, envp) == -1)
		error_flag = 1;
	i = 0;
	while (*(cmd + i))
		free (*(cmd + i++));
	free (cmd);
	free (cmd_path);
	if (error_flag == 1)
		ft_exit_w_error("Command not found\n");
}
