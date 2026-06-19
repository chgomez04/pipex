/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:09:59 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:10:34 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h> 

int		main(int argc, char **argv, char **envp);
void	first_child(char **argv, int *fd, char **envp);
void	second_child(char **argv, int *fd, char **envp);
void	execute(char *cmd, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_free_matrix(char **matrix);
void	ft_free_matrix_n(char **matrix, int n);
char	**ft_split(char const *s, char c);
void	ft_error_sys(const char *msg);
void	ft_error_msg(const char *msg);

#endif
