/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:01:50 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/29 21:03:31 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_exit_w_error(char *str);
void	ft_run_command(char *arg, char **envp);

#endif
