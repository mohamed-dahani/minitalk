/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:53:54 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/22 17:56:48 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	send_signal(char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				custom_error("permission denied\n");	
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				custom_error("permission denied\n");
		}
		usleep(400);
	}
}

static void	handler_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("the message has been received\n");
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			custom_error("the process id is incorrect\n");
		i = 0;
		signal(SIGUSR1, handler_signal);
		while (av[2][i])
		{
			send_signal(av[2][i], pid);
			i++;
		}
		send_signal('\0', pid);
	}
	else
		custom_error("./programe_name [pid] 'message'\n");
}
