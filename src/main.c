/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:19:01 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:20:04 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		ft_error_msg("Uso: ./pipex infile cmd1 cmd2 outfile");
	if (pipe(fd) == -1)
		ft_error_sys("pipe");
	pid1 = fork();
	if (pid1 < 0)
		ft_error_sys("fork");
	if (pid1 == 0)
		first_child(argv, fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_error_sys("fork");
	if (pid2 == 0)
		second_child(argv, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
