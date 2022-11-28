/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:01:50 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/28 16:45:58 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_exit_w_error(void);
void	ft_run_command(char *arg, char **envp);

#endif
