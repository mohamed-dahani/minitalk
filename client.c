/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:53:54 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/15 13:44:28 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void send_signal(char c, pid_t pid)
{
    int i = 0;

    while (i < 8)
    {
        if (!((c >> i) & 1))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        pid_t pid;
        pid = ft_atoi(av[1]);
        if (pid <= 0)
            return (1);
        int i  = 0;
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