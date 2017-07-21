/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:35:54 by twalton           #+#    #+#             */
/*   Updated: 2017/07/16 18:35:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <string.h>

int	main(void)
{
	int i;
	struct timespec ts;

	ts.tv_sec = 0;
	ts.tv_nsec = 50000000;
	i = 0;
	write(1, "\n", 1);
	while (1)
	{
		i++;
		if (i == 40)
			i = 0;
		write(1, "\033[F", 4);
		write(1, "         ]", 10);
		if (i % 40 < 20)
		{
			write(1, "                    ", i % 20);
			write(1, "XXXXXXXXXXXXXXXXXXXX", 20 - i % 20);
		}
		else
		{
                        write(1, "XXXXXXXXXXXXXXXXXXXX", i % 20);
                        write(1, "                    ", 20 - i % 20);
		}
		write(1, "[", 1);
		write(1, "\n", 1);
		nanosleep(&ts, &ts);
	}
}
