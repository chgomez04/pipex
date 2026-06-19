/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:15:21 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:53:09 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

static char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		full = join_path(paths[i], cmd);
		if (access(full, X_OK) == 0)
			return (ft_free_matrix(paths), full);
		free(full);
	}
	ft_free_matrix(paths);
	return (NULL);
}

static void	print_error_cmd(char *cmd)
{
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		ft_error_msg("empty command");
	if (args[0][0] == '/' || (args[0][0] == '.' && args[0][1] == '/'))
		path = args[0];
	else
		path = get_path(args[0], envp);
	if (!path)
	{
		print_error_cmd(args[0]);
		ft_free_matrix(args);
		exit(127);
	}
	if (execve(path, args, envp) == -1)
	{
		print_error_cmd(args[0]);
		ft_free_matrix(args);
		if (path != args[0])
			free(path);
		exit(127);
	}
}
