/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgomez <chgomez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:14:35 by chgomez           #+#    #+#             */
/*   Updated: 2025/11/11 17:14:43 by chgomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error_sys(const char *msg)
{
	write(2, "pipex: ", 7);
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_error_msg(const char *msg)
{
	write(2, "pipex: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
