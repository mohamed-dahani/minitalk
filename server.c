/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:27:12 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/19 19:13:33 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

pid_t	g_client;

static void	write_message(char c, int *bit)
{
	*bit = 0;
	write(1, &c, 1);
	if (c == '\0')
	{
		write(1, "\n", 1);
		if (kill(g_client, SIGUSR1) == -1)
		{
			custom_error("Error sending signal\n");
			exit(1);
		}
	}
}

static void	handler_signal(int sigum, siginfo_t *siginfo, void *walo)
{
	static char	c;
	static int	bit;

	(void)walo;
	if (siginfo->si_pid != g_client)
	{
		c = 0;
		bit = 0;
	}
	if (sigum == SIGUSR1)
	{
		bit++;
		c = c << 1 | 1;
	}
	else if (sigum == SIGUSR2)
	{
		bit++;
		c = c << 1;
	}
	if (bit == 8)
	{
		write_message(c, &bit);
		c = 0;
	}
	g_client = siginfo->si_pid;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				server_pid;

	(void)av;
	g_client = 0;
	if (ac != 1)
		return (1);
	server_pid = getpid();
	sa.sa_sigaction = handler_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("pid: %d\n", server_pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
	{
	}
	return (0);
}
