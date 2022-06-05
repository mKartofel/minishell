/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:17:10 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/06/05 15:54:18 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Check if the string is a -n option.
 * If yes, set the n_option bool to 1
 * @param s String to check
 * @param n_option Boolean: is one of the arguments a -n option ?
 * @return int 1 if true, 0 if false
 */
int check_n_option(char *s, int *n_option)
{
	int i;
	if (s[0] != '-')
		return (0);
	
	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	*n_option = 1;
	return (1);
}


/**
 * @brief Write command args to stdout.
 * -n option : do not output the trailing newline
 * @param command Linked list of command (name) and arguments
 * @return int 0 when done
 */
int echo(t_token *command)
{
	int n_option;

	n_option = 0;
	if (command != NULL) //necessaire ?
		command = command->next;
	while (command && (command->type == 4 || check_n_option(command->content, &n_option))) //check for -n options
		command = command->next;
	while (command && (command->type == 2 || command->type == 4)) //space ou word
	{
		ft_putstr_fd(command->content, 1);
		command = command->next;
	}
	if (n_option == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}

int pwd()
{
	char buffer[BUFFER_SIZE];
	char *ret;
	
	ret = getcwd(buffer, BUFFER_SIZE);
	if (ret == NULL)
		return handle_error("getcwd failed", -1);
	ft_putendl_fd(ret, 1);
	return (0);
}