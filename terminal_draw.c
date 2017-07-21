/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 02:48:03 by twalton           #+#    #+#             */
/*   Updated: 2017/07/21 02:48:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

static void	*read_inp(void *p)
{
	char temp;

	while (1)
	{
		temp = *(char*)p;
		read(0, (char*)p, 1);
		if (*(char*)p >= 'a' && *(char*)p <= 'z')
			*(char*)p = '.';
		if (*(char*)p != 'A' && *(char*)p != 'B' && *(char*)p != 'C' && 
		*(char*)p != 'D' && *(char*)p != '.')
		{
			*(char*)p = temp;
		}
	}
}

static void	logic_loop(char *c)
{
	struct timespec ts;

        ts.tv_sec = 0;
        while (1)
        {
                if (*c == '.')
                        break ;
                if (*c == 'A')
                        write(1, "\033[A\b\b", 6);
                else if (*c == 'D')
                        write(1, "\b\033[D\b", 6);
                else if (*c == 'B')
                        write(1, "\033[B\b\b", 6);
                else if (*c == 'C')
                        write(1, "\b\033[C\b", 6);
                if (*c == 'A' || *c == 'B')
                        ts.tv_nsec = 100000000;
                else
                        ts.tv_nsec = 50000000;
                write(1, "\x1b[44m  ", 7);
                nanosleep(&ts, &ts);
        }
}

int	main(void)
{
	pthread_t t1id;
	char c;

	system ("/bin/stty raw");
	c = '\0';
	pthread_create(&t1id, NULL, read_inp, &c);
	logic_loop(&c);
	system ("/bin/stty cooked");
}
