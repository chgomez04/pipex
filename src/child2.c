/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:13:56 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:14:07 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	second_child(char **argv, int *fd, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error_sys(argv[4]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error_sys("dup2 pipe read");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error_sys("dup2 outfile");
	close(fd[1]);
	close(outfile);
	execute(argv[3], envp);
}
