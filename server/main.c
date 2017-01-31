/*
** main.c for a in /home/soucan_d/soucan_d/Projets/PSU_2015_minitalk/serveur
**
** Made by Dimitri
** Login   <soucan_d@epitech.net>
**
** Started on  Fri Jan 29 17:18:35 2016 Dimitri
** Last update Sat Feb 20 16:59:28 2016 Dimitri
*/

#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	display_char(int *str)
{
  int	a;
  int	nb_tmp;
  int	power;
  int	result;

  power = 7;
  nb_tmp = 0;
  result = 0;
  a = 0;
  while (a <= 7)
    {
      if (str[a] == '1')
	{
	  nb_tmp = exponen(2, power);
	  result = nb_tmp * 1 + result;
	  power = power - 1;
	  a = a + 1;
	}
      else
	{
	  power = power - 1;
	  a = a + 1;
	}
    }
  my_putchar(result);
}

void	serveur(int sign)
{
  static int	*str;
  static int	a;
  int	i;

  i = 10;
  if (a == 0)
    {
      str = malloc(8 * i);
      i = i + 1;
    }
  if (sign == SIGUSR1)
    {
      str[a] = '0';
      a = a + 1;
    }
  else if (sign == SIGUSR2)
    {
      str[a] = '1';
      a = a + 1;
    }
  if (a == 8)
    {
      display_char(str);
      a = 0;
    }
}

int	my_receive()
{
  if (signal(SIGUSR1, serveur) == SIG_ERR)
    return (0);
  if (signal(SIGUSR2, serveur) == SIG_ERR)
    return (0);
}

int	main(int argc, char **argv)
{
  pid_t	pid;

  if (argc == 1)
    {
      pid = getpid();
      if (pid <= 0)
	{
	  write(2, "Wrong PID\n", 10);
	  exit(1);
	}
      my_put_nbr(pid);
      my_putchar(10);
      my_receive();
      while (1);
    }
  else
    my_error_2();
}
