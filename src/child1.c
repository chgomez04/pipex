/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:11:35 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:12:00 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_child(char **argv, int *fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		ft_error_sys(argv[1]);
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error_sys("dup2 infile");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error_sys("dup2 pipe write");
	close(fd[0]);
	close(infile);
	execute(argv[2], envp);
}
